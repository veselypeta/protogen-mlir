#include "Target/TranslateToMurphi.h"
#include "Murphi/Dialect.h"
#include "Target/MurphiModule.h"
#include "Target/MurphiTemplates.h"
#include "mlir/Dialect/StandardOps/IR/Ops.h"
#include "mlir/Target/LLVMIR/ModuleTranslation.h"
#include "mlir/Translation.h"
#include "llvm/ADT/TypeSwitch.h"
#include <iostream>
#include <set>

bool isCpuEvent(std::string action) {
  return action == "load" || action == "store" || action == "evict";
}

void addConstants(target::murphi::Module &m, mlir::ModuleOp op) {
  op.walk([&](mlir::murphi::ConstantOp constOp) {
    int value = constOp.getAttr("value").cast<mlir::IntegerAttr>().getInt();
    std::string id =
        constOp.getAttr("id").cast<mlir::StringAttr>().getValue().str();

    target::murphi::Constant *constDecl =
        new target::murphi::Constant(id, value);
    m.addConstant(constDecl);

    return mlir::WalkResult::advance();
  });
}

void addBoilerplateConstants(target::murphi::Module &m) {
  // VAL_COUNT: 1;
  m.addConstant(new target::murphi::Constant("VAL_COUNT", 1));

  // ADR_COUNT: 1;
  m.addConstant(new target::murphi::Constant("ADR_COUNT", 1));

  // O_NET_MAX: 12;
  // U_NET_MAX: 12;
  m.addConstant(new target::murphi::Constant("O_NET_MAX", 1));
  m.addConstant(new target::murphi::Constant("VAL_COUNT", 1));
}

void addAccessEnum(target::murphi::Module &m) {
  std::vector<std::string> enumList = {"load", "store", "none"};
  m.addEnum(new target::murphi::Enum("Access", enumList));
}

void addMessageTypes(target::murphi::Module &m, mlir::ModuleOp op) {
  std::set<std::string> msgTypes;
  op.walk([&](mlir::murphi::FunctionOp funOp) {
    std::string action =
        funOp.getAttr("action").cast<mlir::StringAttr>().getValue().str();
    if (!isCpuEvent(action)) {
      msgTypes.insert(action);
    }
    return mlir::WalkResult::advance();
  });
  std::vector<std::string> msgTypesVec;
  std::copy(msgTypes.begin(), msgTypes.end(), std::back_inserter(msgTypesVec));

  target::murphi::Enum *msgTypesEnum =
      new target::murphi::Enum("MessageType", msgTypesVec);
  m.addEnum(msgTypesEnum);
}

void addCacheDirectoryStates(target::murphi::Module &m, mlir::ModuleOp op) {
  std::set<std::string> cacheState;
  std::set<std::string> dirState;
  op.walk([&](mlir::murphi::FunctionOp funOp) {
    std::string machine =
        funOp.getAttr("machine").cast<mlir::StringAttr>().getValue().str();
    std::string state =
        funOp.getAttr("cur_state").cast<mlir::StringAttr>().getValue().str();
    if (machine == "cache") {
      cacheState.insert(state);
    }
    if (machine == "directory") {
      dirState.insert(state);
    }
    return mlir::WalkResult::advance();
  });
  // Convert Set to Vector
  std::vector<std::string> cacheStateVec;
  std::vector<std::string> dirStateVec;

  std::copy(cacheState.begin(), cacheState.end(),
            std::back_inserter(cacheStateVec));
  std::copy(dirState.begin(), dirState.end(), std::back_inserter(dirStateVec));

  target::murphi::Enum *cacheStateDecl =
      new target::murphi::Enum("cache_state", cacheStateVec);
  target::murphi::Enum *dirStateDecl =
      new target::murphi::Enum("directory_state", dirStateVec);
  m.addEnum(cacheStateDecl);
  m.addEnum(dirStateDecl);
}

void addAddressesAndCl(target::murphi::Module &m) {
  // Address: scalarset(ADR_COUNT);
  m.addScalarset(
      new target::murphi::Scalarset("Address", m.findReference("ADR_COUNT")));

  // ClValue: 0..VAL_COUNT;
  target::murphi::ValRange *clValue =
      new target::murphi::ValRange("ClValue", 0, m.findReference("VAL_COUNT"));
  m.addValRange(clValue);
};

void addCacheDirectoryObjectDefinitions(target::murphi::Module &m) {
  // OBJSET_cache: scalarset(NrCaches);
  target::murphi::Scalarset *objsetCache = new target::murphi::Scalarset(
      "OBJSET_cache", m.findReference("nrCaches"));

  // OBJSET_directory: enum{directory};
  std::vector<std::string> directoryValues;
  directoryValues.push_back("directory");
  target::murphi::Enum *objsetDirectory =
      new target::murphi::Enum("OBJSET_directory", directoryValues);

  // Machines: union{OBJSET_cache, OBJSET_directory};
  target::murphi::Union *machines =
      new target::murphi::Union("Machines", objsetCache, objsetDirectory);

  // Add Then to the Module
  m.addScalarset(objsetCache);
  m.addEnum(objsetDirectory);
  m.addUnion(machines);
}

void addCacheDirectoryDefinitions(target::murphi::Module &m,
                                  mlir::ModuleOp op) {
  target::murphi::Record *cache = new target::murphi::Record("ENTRY_cache");
  target::murphi::Record *directory =
      new target::murphi::Record("ENTRY_directory");
  op.walk([&](mlir::murphi::CacheDefOp cacheDef) {
    auto fieldsAttr = cacheDef.getAttr("fields").cast<mlir::ArrayAttr>();
    auto typesAttr = cacheDef.getAttr("types").cast<mlir::ArrayAttr>();
    for (int i = 0; i < (int)fieldsAttr.size(); i++) {
      std::string fieldName =
          fieldsAttr[i].cast<mlir::StringAttr>().getValue().str();
      std::string typeName =
          typesAttr[i].cast<mlir::StringAttr>().getValue().str();
      std::string typeId;
      if (fieldName == "State") {
        typeId = "cache_state";
      } else if (typeName == "Data") {
        typeId = "ClValue";
      } else if (typeName == "ID") {
        typeId = "Machines";
      }
      // Push each element into the data structure
      cache->addEntry(fieldName, m.findReference(typeId));
    }
    cache->addEntry("Perm", m.findReference("Access"));
  });

  op.walk([&](mlir::murphi::DirectoryDefOp directoryDef) {
    auto fieldsAttr = directoryDef.getAttr("fields").cast<mlir::ArrayAttr>();
    auto typesAttr = directoryDef.getAttr("types").cast<mlir::ArrayAttr>();
    for (int i = 0; i < (int)fieldsAttr.size(); i++) {
      std::string fieldName =
          fieldsAttr[i].cast<mlir::StringAttr>().getValue().str();
      std::string typeName =
          typesAttr[i].cast<mlir::StringAttr>().getValue().str();
      std::string typeId;
      if (fieldName == "State") {
        typeId = "directory_state";
      } else if (typeName == "Data") {
        typeId = "ClValue";
      } else if (typeName == "ID") {
        typeId = "Machines";
      }
      // Push each element into the data structure
      directory->addEntry(fieldName, m.findReference(typeId));
    }
    directory->addEntry("Perm", m.findReference("Access"));
  });
  // Add Access

  m.addRecord(cache);
  m.addRecord(directory);
}

void addGloablMessageType(target::murphi::Module &m, mlir::ModuleOp op) {
  target::murphi::Record *msgDef = new target::murphi::Record("Message");
  // All messages have default values
  // Address of the CL
  msgDef->addEntry("adr", m.findReference("Address"));
  // Message Type
  msgDef->addEntry("mtype", m.findReference("MessageType"));
  // Msg Src
  msgDef->addEntry("src", m.findReference("Machines"));
  // Msg Dest
  msgDef->addEntry("dst", m.findReference("Machines"));

  // Now walk all the Msg Declaration operations and find
  op.walk([&](mlir::murphi::MessageDefOp op) {
    auto fieldIds = op.getAttr("fields").cast<mlir::ArrayAttr>();
    auto typeIds = op.getAttr("types").cast<mlir::ArrayAttr>();

    for (int i = 0; i < (int)fieldIds.size(); i++) {
      std::string fid = fieldIds[i].cast<mlir::StringAttr>().getValue().str();
      std::string tid = typeIds[i].cast<mlir::StringAttr>().getValue().str();
      // TODO -- Make more sophisticated
      if (tid == "Data") {
        msgDef->addEntry(fid, m.findReference("ClValue"));
      }
    }
  });

  m.addRecord(msgDef);
}

void addBoilerplateTypes(target::murphi::Module &m) {
  target::murphi::Boilerplate *mcache =
      new target::murphi::Boilerplate("MACH_cache", MACH_cache);
  target::murphi::Boilerplate *mdir =
      new target::murphi::Boilerplate("MACH_directory", MACH_directory);
  target::murphi::Boilerplate *objcache =
      new target::murphi::Boilerplate("OBJ_cache", OBJ_cache);
  target::murphi::Boilerplate *objdir =
      new target::murphi::Boilerplate("OBJ_directory", OBJ_directory);
  target::murphi::Boilerplate *objorder =
      new target::murphi::Boilerplate("OBJ_Ordered", OBJ_Ordered);
  target::murphi::Boilerplate *ordercnt =
      new target::murphi::Boilerplate("OBJ_Orderedcnt", OBJ_Orderedcnt);
  target::murphi::Boilerplate *objunorder =
      new target::murphi::Boilerplate("OBJ_Unordered", OBJ_Unordered);

  m.addBoilerplate(mcache);
  m.addBoilerplate(mdir);
  m.addBoilerplate(objcache);
  m.addBoilerplate(objdir);
  m.addBoilerplate(objorder);
  m.addBoilerplate(ordercnt);
  m.addBoilerplate(objunorder);
}

void addVariableDeclarations(target::murphi::Module &m, mlir::ModuleOp op) {
  // ADD CACHE AND DIRECTORY VARIABLES
  target::murphi::Variable *i_cache =
      new target::murphi::Variable("i_cache", m.findReference("OBJ_cache"));
  target::murphi::Variable *i_directory = new target::murphi::Variable(
      "i_directory", m.findReference("OBJ_directory"));
  m.addVariable(i_cache);
  m.addVariable(i_directory);

  // find network declarations
  op.walk([&](mlir::murphi::NetworkDeclOp netDecl) {
    std::string netId =
        netDecl.getAttr("id").cast<mlir::StringAttr>().getValue().str();
    std::string netOrder =
        netDecl.getAttr("ordering").cast<mlir::StringAttr>().getValue().str();
    if (netOrder == "Ordered") {
      // if ordered we need to generate the network and the count
      target::murphi::Variable *netVar =
          new target::murphi::Variable(netId, m.findReference("OBJ_Ordered"));
      target::murphi::Variable *netCount = new target::murphi::Variable(
          netId, m.findReference("OBJ_Orderedcnt"));
      m.addVariable(netVar);
      m.addVariable(netCount);

    } else {
      target::murphi::Variable *netVar =
          new target::murphi::Variable(netId, m.findReference("OBJ_Unordered"));
      m.addVariable(netVar);
    }
  });
}

void addMessageFactories(target::murphi::Module &m, mlir::ModuleOp op) {
  target::murphi::LanguageConstruct *messageDeclaration =
      m.findReference("Message");
  op.walk([&](mlir::murphi::MessageDefOp msgDef) {
    std::string msgId =
        msgDef.getAttr("id").cast<mlir::StringAttr>().getValue().str();
    target::murphi::MessageContructor *msgConstr =
        new target::murphi::MessageContructor(msgId, messageDeclaration);
    auto fieldsAttr = msgDef.getAttr("fields").cast<mlir::ArrayAttr>();
    // auto typesAttr = msgDef.getAttr("types").cast<mlir::ArrayAttr>();
    for (int i = 0; i < (int)fieldsAttr.size(); i++) {
      msgConstr->addExtraField(
          fieldsAttr[i].cast<mlir::StringAttr>().getValue().str());
    }
    // ADD MSG CONSTROCTOR TO MODULE
    m.addMessageConstructor(msgConstr);
    return mlir::WalkResult::advance();
  });
}

void addSendFunctions(target::murphi::Module &m, mlir::ModuleOp op) {
  op.walk([&](mlir::murphi::NetworkDeclOp netDecl) {
    std::string netId =
        netDecl.getAttr("id").cast<mlir::StringAttr>().getValue().str();
    std::string netOrder =
        netDecl.getAttr("ordering").cast<mlir::StringAttr>().getValue().str();
    target::murphi::NetworkOrder order =
        netOrder == "Ordered" ? target::murphi::NetworkOrder::Ordered
                              : target::murphi::NetworkOrder::Unordered;
    target::murphi::SendFunction *sendFunc =
        new target::murphi::SendFunction(netId, order);
    m.addSendFunction(sendFunc);
  });
}

target::murphi::StateHandler
getStateHandler(std::string stateId, std::string machineId, mlir::ModuleOp op) {
  target::murphi::StateHandler sh(stateId);
  op.walk([&](mlir::murphi::FunctionOp funOp) {
    std::string machine =
        funOp.getAttr("machine").cast<mlir::StringAttr>().getValue().str();
    std::string action =
        funOp.getAttr("action").cast<mlir::StringAttr>().getValue().str();
    std::string cur_state =
        funOp.getAttr("cur_state").cast<mlir::StringAttr>().getValue().str();
    // Filter over all possible messages that can be received
    if (!isCpuEvent(action) && machine == machineId && cur_state == stateId) {
      // For each such message -- possibly zero -- create a message handler
      target::murphi::MessageHandler msgHandler(action);
      sh.addMessageHandler(msgHandler);
    }
  });
  return sh;
}

target::murphi::MachineHandlerFunction
getMachineHandleFunction(target::murphi::Module &m, mlir::ModuleOp op,
                         std::string machId) {
  // Get the Cache State Enum
  target::murphi::MachineHandlerFunction handFunc(machId);
  target::murphi::Enum *states =
      dynamic_cast<target::murphi::Enum *>(m.findReference(machId + "_state"));
  for (auto state : states->getElements()) {
    // Generate a State Handler for each state
    target::murphi::StateHandler sh = getStateHandler(state, machId, op);
    handFunc.addStateHandler(sh);
  }
  return handFunc;
}

void addCacheFunction(target::murphi::Module &m, mlir::ModuleOp op) {
  target::murphi::MachineHandlerFunction funcCache =
      getMachineHandleFunction(m, op, "cache");
  m.addMachineHandleFunction(funcCache);
}

void addDirectoryFunction(target::murphi::Module &m, mlir::ModuleOp op) {
  target::murphi::MachineHandlerFunction funcDir =
      getMachineHandleFunction(m, op, "directory");
  m.addMachineHandleFunction(funcDir);
}

void addStartStateDefinition(target::murphi::Module &m, mlir::ModuleOp op) {
  // Create a StartState Object
  target::murphi::StartState ss;

  // Body of the start state
  std::string body;
  // Add Cache and Directory Startstate Definitions
  op.walk([&](mlir::murphi::CacheDefOp cacheDefOp) {
    // String of operations
    std::string operations;

    // get the Fiels and Types arrays
    mlir::ArrayAttr fields =
        cacheDefOp.getAttr("fields").cast<mlir::ArrayAttr>();
    mlir::ArrayAttr types = cacheDefOp.getAttr("types").cast<mlir::ArrayAttr>();
    for (int i = 0; i < (int)fields.size(); i++) {
      std::string field = fields[i].cast<mlir::StringAttr>().getValue().str();
      std::string type = types[i].cast<mlir::StringAttr>().getValue().str();

      // Hardcoded CL !!!!!
      if (field == "State") {
        std::string initialState = "cache_" + type;
        operations += start_state_assignment("cache", "State", initialState);
      } else if (field == "cl") {
        operations += start_state_assignment("cache", "cl", "0");
      }
    }
    // Add permission initially to None
    operations += start_state_assignment("cache", "Perm", "none");

    // Add the Cache State State Def
    body += mach_start_state("cache", operations);

    return mlir::WalkResult::advance();
  });

  op.walk([&](mlir::murphi::DirectoryDefOp dirDefOp) {
    std::string operations;
    std::string machId = "directory";

    mlir::ArrayAttr fields = dirDefOp.getAttr("fields").cast<mlir::ArrayAttr>();
    mlir::ArrayAttr types = dirDefOp.getAttr("types").cast<mlir::ArrayAttr>();

    for (int i = 0; i < (int)fields.size(); i++) {
      std::string field = fields[i].cast<mlir::StringAttr>().getValue().str();
      std::string type = types[i].cast<mlir::StringAttr>().getValue().str();

      if (field == "State") {
        std::string initialState = machId + "_" + type;
        operations += start_state_assignment(machId, "State", initialState);
      } else if (field == "cl") {
        operations += start_state_assignment(machId, "cl", "0");
      }
    }
    // Add permission initially to None
    operations += start_state_assignment(machId, "Perm", "none");

    // Add the directory definition start state
    body += mach_start_state(machId, operations);

    return mlir::WalkResult::advance();
  });

  // Add the network definitions
  op.walk([&](mlir::murphi::NetworkDeclOp netDeclOp) {
    std::string ordering = netDeclOp.getAttr("ordering").cast<mlir::StringAttr>().getValue().str();
    std::string netId = netDeclOp.getAttr("id").cast<mlir::StringAttr>().getValue().str();
    if(ordering == "Ordered"){
      body += start_state_ordered_network(netId);
    } else{
      body += start_state_unordered_network(netId);
    }
    return mlir::WalkResult::advance();
  });

  // Add the text to SS
  ss.addText(start_state_defintion(body));
  m.addStartState(ss);
};

// void addDirectoryFunction(target::murphi::Module &m, mlir::ModuleOp op) {
//   // Get the Cache State Enum
//   target::murphi::MachineHandlerFunction funcDirectory("directory");
//   target::murphi::Enum *dirStateEnum =
//       dynamic_cast<target::murphi::Enum
//       *>(m.findReference("directory_state"));
//   for (auto cs : dirStateEnum->getElements()) {
//     // Generate a State Handler for each state
//     target::murphi::StateHandler sh = getStateHandler(cs, "directory", op);
//     funcDirectory.addStateHandler(sh);
//   }
//   m.addMachineHandleFunction(funcDirectory);
// }

void addCacheCPUEventFunctions(target::murphi::Module &m, mlir::ModuleOp op) {
  op.walk([&](mlir::murphi::FunctionOp funcOp) {
    std::string action =
        funcOp.getAttr("action").cast<mlir::StringAttr>().getValue().str();
    std::string machine =
        funcOp.getAttr("machine").cast<mlir::StringAttr>().getValue().str();
    if (isCpuEvent(action) && machine == "cache") {
      std::string curState =
          funcOp.getAttr("cur_state").cast<mlir::StringAttr>().getValue().str();
      target::murphi::CacheCPUEventFunction *cacheFunc =
          new target::murphi::CacheCPUEventFunction(curState, action);
      // Walk the nested Operations in the function and generate Murphi for them
      funcOp.getRegion().walk([&](mlir::Operation *anyop) {

      });
      m.addCacheCPUEventFunction(cacheFunc);
    }
    return mlir::WalkResult::advance();
  });
}

void addCacheRuleset(target::murphi::Module &m, mlir::ModuleOp op) {
  target::murphi::CacheRuleset c_ruleset;
  op.walk([&](mlir::murphi::FunctionOp funOp) {
    std::string action =
        funOp.getAttr("action").cast<mlir::StringAttr>().getValue().str();
    if (action == "load" || action == "store" || action == "evict") {
      std::string curState =
          funOp.getAttr("cur_state").cast<mlir::StringAttr>().getValue().str();
      target::murphi::CacheRule cr =
          target::murphi::CacheRule(curState, action);
      c_ruleset.addRule(cr);
    }
  });
  m.setCacheRuleset(c_ruleset);
}

void addNetworkRulesets(target::murphi::Module &m, mlir::ModuleOp op) {
  op.walk([&](mlir::murphi::NetworkDeclOp netDecl) {
    std::string netId =
        netDecl.getAttr("id").cast<mlir::StringAttr>().getValue().str();
    std::string netOrder =
        netDecl.getAttr("ordering").cast<mlir::StringAttr>().getValue().str();
    target::murphi::NetworkOrder order =
        netOrder == "Ordered" ? target::murphi::NetworkOrder::Ordered
                              : target::murphi::NetworkOrder::Unordered;

    target::murphi::NetworkRuleset netRS(netId, order);
    m.addNetworkRuleset(netRS);
    return mlir::WalkResult::advance();
  });
}

target::murphi::Module createModule(mlir::ModuleOp op,
                                    mlir::raw_ostream &output) {
  target::murphi::Module m;

  addConstants(m, op);
  addBoilerplateConstants(m);
  addAccessEnum(m);
  addMessageTypes(m, op);
  addCacheDirectoryStates(m, op);

  addAddressesAndCl(m);
  addCacheDirectoryObjectDefinitions(m);
  addCacheDirectoryDefinitions(m, op);
  addGloablMessageType(m, op);
  addBoilerplateTypes(m);
  addVariableDeclarations(m, op);

  addMessageFactories(m, op);
  addSendFunctions(m, op);
  addCacheFunction(m, op);
  addDirectoryFunction(m, op);

  addCacheCPUEventFunctions(m, op);
  addCacheRuleset(m, op);
  addStartStateDefinition(m, op);
  addNetworkRulesets(m, op);
  return m;
}

namespace mlir {
void registerToMurphiTranslation() {
  mlir::TranslateFromMLIRRegistration registration(
      "mlir-to-murphi",
      [](mlir::ModuleOp op, mlir::raw_ostream &output) {
        auto module = createModule(op, output);
        module.print(output);
        return mlir::success();
      },
      [](mlir::DialectRegistry &registry) {
        registry.insert<mlir::murphi::MurphiDialect>();
        registry.insert<mlir::StandardOpsDialect>();
      });
}
} // namespace mlir
