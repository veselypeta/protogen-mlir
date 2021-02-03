#include "Target/TranslateToMurphi.h"
#include "Murphi/Dialect.h"
#include "Target/MurphiModule.h"
#include "Target/MurphiTemplates.h"
#include "mlir/Dialect/StandardOps/IR/Ops.h"
#include "mlir/Target/LLVMIR/ModuleTranslation.h"
#include "mlir/Translation.h"
#include "llvm/ADT/TypeSwitch.h"
#include <algorithm>
#include <iostream>
#include <set>

namespace murphiGenImpl {
class MurphiGen {
public:
  MurphiGen(mlir::ModuleOp moduleOp, bool concurrent = false)
      : moduleOp{moduleOp}, concurrent{concurrent} {}
  // We return a reference to prevent destructor being called
  target::murphi::Module &createModule() {
    addConstants();
    addBoilerplateConstants();
    addAccessEnum();
    addMessageTypes();
    addCacheDirectoryStates();

    addAddressesAndCl();
    addCacheDirectoryObjectDefinitions();
    addCacheDirectoryDefinitions();
    addGloablMessageType();
    addBoilerplateTypes();
    addVariableDeclarations();

    addMessageFactories();
    if (!concurrent)
      addClMutexHelperFunctions();
    addSendFunctions();
    addCacheFunction();
    addDirectoryFunction();

    addCacheCPUEventFunctions();
    addCacheRuleset();
    addStartStateDefinition();
    addNetworkRulesets();
    return murphiModule;
  }

private:
  target::murphi::Module murphiModule;
  mlir::ModuleOp moduleOp;
  bool concurrent = false;

  bool isCpuEvent(std::string action) {
    return action == "load" || action == "store" || action == "evict";
  }

  void addConstants() {
    moduleOp.walk([&](mlir::murphi::ConstantOp constOp) {
      int value = constOp.getAttr("value").cast<mlir::IntegerAttr>().getInt();
      std::string id =
          constOp.getAttr("id").cast<mlir::StringAttr>().getValue().str();

      target::murphi::Constant *constDecl =
          new target::murphi::Constant(id, value);
      murphiModule.addConstant(constDecl);

      return mlir::WalkResult::advance();
    });
  }

  void addBoilerplateConstants() {
    // VAL_COUNT: 1;
    murphiModule.addConstant(new target::murphi::Constant("VAL_COUNT", 1));

    // ADR_COUNT: 1;
    murphiModule.addConstant(new target::murphi::Constant("ADR_COUNT", 1));

    // O_NET_MAX: 12;
    // U_NET_MAX: 12;
    murphiModule.addConstant(new target::murphi::Constant("O_NET_MAX", 12));
    murphiModule.addConstant(new target::murphi::Constant("U_NET_MAX", 12));
  }

  void addAccessEnum() {
    std::vector<std::string> enumList = {"load", "store", "none"};
    murphiModule.addEnum(new target::murphi::Enum("Access", enumList));
  }

  void addMessageTypes() {
    std::set<std::string> msgTypes;
    moduleOp.walk([&](mlir::murphi::FunctionOp funOp) {
      std::string action =
          funOp.getAttr("action").cast<mlir::StringAttr>().getValue().str();
      if (!isCpuEvent(action)) {
        msgTypes.insert(action);
      }
      return mlir::WalkResult::advance();
    });
    std::vector<std::string> msgTypesVec;
    std::copy(msgTypes.begin(), msgTypes.end(),
              std::back_inserter(msgTypesVec));

    target::murphi::Enum *msgTypesEnum =
        new target::murphi::Enum("MessageType", msgTypesVec);
    murphiModule.addEnum(msgTypesEnum);
  }

  void addCacheDirectoryStates() {
    std::set<std::string> cacheState;
    std::set<std::string> dirState;
    moduleOp.walk([&](mlir::murphi::FunctionOp funOp) {
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
    std::copy(dirState.begin(), dirState.end(),
              std::back_inserter(dirStateVec));

    target::murphi::Enum *cacheStateDecl =
        new target::murphi::Enum("cache_state", cacheStateVec);
    target::murphi::Enum *dirStateDecl =
        new target::murphi::Enum("directory_state", dirStateVec);
    murphiModule.addEnum(cacheStateDecl);
    murphiModule.addEnum(dirStateDecl);
  }

  void addAddressesAndCl() {
    // Address: scalarset(ADR_COUNT);
    murphiModule.addScalarset(new target::murphi::Scalarset(
        "Address", murphiModule.findReference("ADR_COUNT")));

    // ClValue: 0..VAL_COUNT;
    target::murphi::ValRange *clValue = new target::murphi::ValRange(
        "ClValue", 0, murphiModule.findReference("VAL_COUNT"));
    murphiModule.addValRange(clValue);
  };

  void addCacheDirectoryObjectDefinitions() {
    // OBJSET_cache: scalarset(NrCaches);
    target::murphi::Scalarset *objsetCache = new target::murphi::Scalarset(
        "OBJSET_cache", murphiModule.findReference("nrCaches"));

    // OBJSET_directory: enum{directory};
    std::vector<std::string> directoryValues;
    directoryValues.push_back("directory");
    target::murphi::Enum *objsetDirectory =
        new target::murphi::Enum("OBJSET_directory", directoryValues);

    // Machines: union{OBJSET_cache, OBJSET_directory};
    target::murphi::Union *machines =
        new target::murphi::Union("Machines", objsetCache, objsetDirectory);

    // Add Then to the Module
    murphiModule.addScalarset(objsetCache);
    murphiModule.addEnum(objsetDirectory);
    murphiModule.addUnion(machines);
  }

  void addCacheDirectoryDefinitions() {
    target::murphi::Record *cache = new target::murphi::Record("ENTRY_cache");
    target::murphi::Record *directory =
        new target::murphi::Record("ENTRY_directory");
    moduleOp.walk([&](mlir::murphi::CacheDefOp cacheDef) {
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
        cache->addEntry(fieldName, murphiModule.findReference(typeId));
      }
      cache->addEntry("Perm", murphiModule.findReference("Access"));
    });

    moduleOp.walk([&](mlir::murphi::DirectoryDefOp directoryDef) {
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
        directory->addEntry(fieldName, murphiModule.findReference(typeId));
      }
      directory->addEntry("Perm", murphiModule.findReference("Access"));
    });
    // Add Access

    murphiModule.addRecord(cache);
    murphiModule.addRecord(directory);
  }

  void addGloablMessageType() {
    target::murphi::Record *msgDef = new target::murphi::Record("Message");
    // All messages have default values
    // Address of the CL
    msgDef->addEntry("adr", murphiModule.findReference("Address"));
    // Message Type
    msgDef->addEntry("mtype", murphiModule.findReference("MessageType"));
    // Msg Src
    msgDef->addEntry("src", murphiModule.findReference("Machines"));
    // Msg Dest
    msgDef->addEntry("dst", murphiModule.findReference("Machines"));

    // Now walk all the Msg Declaration operations and find
    moduleOp.walk([&](mlir::murphi::MessageDefOp op) {
      auto fieldIds = op.getAttr("fields").cast<mlir::ArrayAttr>();
      auto typeIds = op.getAttr("types").cast<mlir::ArrayAttr>();

      for (int i = 0; i < (int)fieldIds.size(); i++) {
        std::string fid = fieldIds[i].cast<mlir::StringAttr>().getValue().str();
        std::string tid = typeIds[i].cast<mlir::StringAttr>().getValue().str();
        // TODO -- Make more sophisticated
        if (tid == "Data") {
          msgDef->addEntry(fid, murphiModule.findReference("ClValue"));
        }
      }
    });

    murphiModule.addRecord(msgDef);
  }

  void addBoilerplateTypes() {
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

    murphiModule.addBoilerplate(mcache);
    murphiModule.addBoilerplate(mdir);
    murphiModule.addBoilerplate(objcache);
    murphiModule.addBoilerplate(objdir);
    murphiModule.addBoilerplate(objorder);
    murphiModule.addBoilerplate(ordercnt);
    murphiModule.addBoilerplate(objunorder);

    // add CL Mutex if not a concurrent protocol
    if (!concurrent) {
      target::murphi::Boilerplate *clMutex =
          new target::murphi::Boilerplate("CL_MUTEX", CL_MUTEX_template);
      murphiModule.addBoilerplate(clMutex);
    }
  }

  void addVariableDeclarations() {
    // ADD CACHE AND DIRECTORY VARIABLES
    target::murphi::Variable *i_cache = new target::murphi::Variable(
        "i_cache", murphiModule.findReference("OBJ_cache"));
    target::murphi::Variable *i_directory = new target::murphi::Variable(
        "i_directory", murphiModule.findReference("OBJ_directory"));
    murphiModule.addVariable(i_cache);
    murphiModule.addVariable(i_directory);

    // find network declarations
    moduleOp.walk([&](mlir::murphi::NetworkDeclOp netDecl) {
      std::string netId =
          netDecl.getAttr("id").cast<mlir::StringAttr>().getValue().str();
      std::string netOrder =
          netDecl.getAttr("ordering").cast<mlir::StringAttr>().getValue().str();
      if (netOrder == "Ordered") {
        // if ordered we need to generate the network and the count
        target::murphi::Variable *netVar = new target::murphi::Variable(
            netId, murphiModule.findReference("OBJ_Ordered"));
        target::murphi::Variable *netCount = new target::murphi::Variable(
            "cnt_" + netId, murphiModule.findReference("OBJ_Orderedcnt"));
        murphiModule.addVariable(netVar);
        murphiModule.addVariable(netCount);

      } else {
        target::murphi::Variable *netVar = new target::murphi::Variable(
            netId, murphiModule.findReference("OBJ_Unordered"));
        murphiModule.addVariable(netVar);
      }
    });

    // add cl_mut if required
    if (!concurrent) {
      target::murphi::Variable *cl_mut = new target::murphi::Variable(
          "cl_mut", murphiModule.findReference("CL_MUTEX"));
      murphiModule.addVariable(cl_mut);
    }
  }

  void addMessageFactories() {
    target::murphi::LanguageConstruct *messageDeclaration =
        murphiModule.findReference("Message");
    moduleOp.walk([&](mlir::murphi::MessageDefOp msgDef) {
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
      murphiModule.addMessageConstructor(msgConstr);
      return mlir::WalkResult::advance();
    });
  }

  void addClMutexHelperFunctions() {
    target::murphi::MutexHelperFunction *acqMutex =
        new target::murphi::MutexHelperFunction(
            "Aquire_Mutex", true, murphiModule.findReference("cl_mut"));
    target::murphi::MutexHelperFunction *rlsMutex =
        new target::murphi::MutexHelperFunction(
            "Release_Mutex", false, murphiModule.findReference("cl_mut"));
    murphiModule.addMutexHelperFunction(acqMutex);
    murphiModule.addMutexHelperFunction(rlsMutex);
  }

  void addSendFunctions() {
    moduleOp.walk([&](mlir::murphi::NetworkDeclOp netDecl) {
      std::string netId =
          netDecl.getAttr("id").cast<mlir::StringAttr>().getValue().str();
      std::string netOrder =
          netDecl.getAttr("ordering").cast<mlir::StringAttr>().getValue().str();
      target::murphi::NetworkOrder order =
          netOrder == "Ordered" ? target::murphi::NetworkOrder::Ordered
                                : target::murphi::NetworkOrder::Unordered;
      target::murphi::SendFunction *sendFunc =
          new target::murphi::SendFunction(netId, order);
      murphiModule.addSendFunction(sendFunc);
    });
  }

  std::string interleaveComma(std::vector<std::string> values) {
    std::string interleaved;
    for (std::string v : values) {
      if (v == values.front()) {
        interleaved += v;
      } else {
        interleaved += ", " + v;
      }
    }
    return interleaved;
  }

  std::string getAttributeAsStr(const mlir::Attribute &a) {
    return a.cast<mlir::StringAttr>().getValue().str();
  }

  mlir::ArrayAttr getArrayAttr(mlir::Operation *op, std::string attrId) {
    return op->getAttr(attrId).cast<mlir::ArrayAttr>();
  }

  std::string getStrAttrFromOp(mlir::Operation *a, std::string attrId) {
    return a->getAttr(attrId).cast<mlir::StringAttr>().getValue().str();
  }

  // Get all the aux state definitions -- i.e State, cl, owner ...
  std::vector<std::string> getMachineAuxStateReferences(std::string mach) {
    std::vector<std::string> auxStates;
    if (mach == "cache") {
      moduleOp.walk([&](mlir::murphi::CacheDefOp cacheDef) {
        mlir::ArrayAttr cacheFieldsAttr = getArrayAttr(cacheDef, "fields");
        mlir::ArrayAttr cacheTypesAttr = getArrayAttr(cacheDef, "types");
        // loop over all the attributes
        for (int i = 0; i < (int)cacheFieldsAttr.size(); i++) {
          std::string field = getAttributeAsStr(cacheFieldsAttr[i]);
          std::string type = getAttributeAsStr(cacheTypesAttr[i]);
          // Special case - State
          if (type == "State") {
            auxStates.push_back(type);
          } else {
            auxStates.push_back(field);
          }
        }
      });
    } else {
      moduleOp.walk([&](mlir::murphi::DirectoryDefOp directoryDef) {
        mlir::ArrayAttr directoryFieldsAttr =
            getArrayAttr(directoryDef, "fields");
        mlir::ArrayAttr directoryTypesAttr =
            getArrayAttr(directoryDef, "types");
        // loop over all the attributes
        for (int i = 0; i < (int)directoryFieldsAttr.size(); i++) {
          std::string field = getAttributeAsStr(directoryFieldsAttr[i]);
          std::string type = getAttributeAsStr(directoryTypesAttr[i]);
          // Special case - State
          if (type == "State") {
            auxStates.push_back(type);
          } else {
            auxStates.push_back(field);
          }
        }
      });
    }
    return auxStates;
  }

  std::string processObjectReference(std::string param, std::string machine) {
    // find (if exists) the dot
    std::size_t dotLoc = param.find('.');

    // if no dot then we are either referencing a constant or something in the
    // aux state
    if (dotLoc == std::string::npos) {
      // get the aux state list i.e. [State, cl, owner ...]
      std::vector<std::string> auxState = getMachineAuxStateReferences(machine);
      // If referece is part of aux state -- then we return mach_entry.param
      // i.e. directory_entry.owner
      if (std::find(auxState.begin(), auxState.end(), param) !=
          auxState.end()) {
        return machine + "_entry." + param;
      }
      // otherwise -- we just return as is, typically for the State i.e. cache_I
      // or some constant
      return param;
    }

    // get the obj and val from the reference i.e. GetM and src
    std::string objRef = param.substr(0, dotLoc);
    std::string valRef = param.substr(dotLoc + 1, param.length());

    // if obj is directory -> must be referencing directory.ID
    // then we reference the enum type 'directory'
    if (objRef == "directory" && valRef == "ID") {
      return "directory";
    }
    // must be referencing the message type
    else {
      return "inmsg." + valRef;
    }
  }

  std::string generateMsgConstructorMurphi(mlir::murphi::MsgConstrOp &msgConstr,
                                           std::string machine) {
    // get the constrId i.e. Resp
    std::string constrId = getStrAttrFromOp(msgConstr, "msgType");
    // get the params array ["GetM", ..]
    mlir::ArrayAttr paramsAttr =
        msgConstr.getAttr("parameters").cast<mlir::ArrayAttr>();
    std::vector<std::string> parameters;
    for (int i = 0; i < (int)paramsAttr.size(); i++) {
      std::string paramStr = getAttributeAsStr(paramsAttr[i]);
      // MsgId
      if (i == 0) {
        // No work here - msgid should just be string
        parameters.push_back(paramStr);
      }
      // src
      else if (i == 1) {
        // Could be an object ref or ID
        if (paramStr == "ID") {
          // hardcoded value !!! -- likely move this as default or something
          parameters.push_back("m");
        }
        // Some reference to another machine (cache or directory) i.e.
        // GetM.src or directory.ID
        else {
          // prepend with mach_entry
          parameters.push_back(processObjectReference(paramStr, machine));
        }
      }
      // dst
      else if (i == 2) {
        parameters.push_back(processObjectReference(paramStr, machine));
      }
      // other fields like owner ...
      else {
        parameters.push_back(processObjectReference(paramStr, machine));
      }
    }

    return message_constructor(constrId, interleaveComma(parameters));
  }

  std::string generateSendOpMurphi(mlir::murphi::SendOp &sendOp) {
    std::string netId = getStrAttrFromOp(sendOp, "netId");
    return send_message(netId);
  }

  std::string generateSetOpMurphi(mlir::murphi::SetOp &setOp,
                                  std::string machine) {
    std::string id = getStrAttrFromOp(setOp, "id");
    std::string value = getStrAttrFromOp(setOp, "value");
    return assign_value(machine, id, processObjectReference(value, machine));
  }

  std::string generateOperationMurphi(mlir::Operation &anyOp,
                                      std::string machine) {
    mlir::Operation *ref = &anyOp;

    // Generate the output for a MsgConstructor Operation
    if (mlir::murphi::MsgConstrOp msgConstr =
            mlir::dyn_cast<mlir::murphi::MsgConstrOp>(ref)) {
      return generateMsgConstructorMurphi(msgConstr, machine);
    }

    // Generate the output for a SendOp Operations
    if (mlir::murphi::SendOp sendOp =
            mlir::dyn_cast<mlir::murphi::SendOp>(ref)) {
      return generateSendOpMurphi(sendOp);
    }

    // Generate the output for a set operation
    if (mlir::murphi::SetOp setOp = mlir::dyn_cast<mlir::murphi::SetOp>(ref)) {
      return generateSetOpMurphi(setOp, machine);
      // setOp.dump();
    }

    // Generate the Output for an If op
    if (mlir::murphi::IfOp ifOp = mlir::dyn_cast<mlir::murphi::IfOp>(ref)) {
      std::string nestedOps;
      std::string lhs = getStrAttrFromOp(ifOp, "lhs");
      std::string comparison = getStrAttrFromOp(ifOp, "comparison");
      // TODO!!!! -- Hack for now -- replace == with =
      comparison = comparison == "==" ? "=" : comparison;
      std::string rhs = getStrAttrFromOp(ifOp, "rhs");
      // Loop through nested operations and recurse
      for (mlir::Operation &nestedOp :
           ifOp.getRegion().getBlocks().front().getOperations()) {
        nestedOps += generateOperationMurphi(nestedOp, machine);
      }
      // process lhs/rhs and object references
      return if_statement(processObjectReference(lhs, machine), comparison,
                          processObjectReference(rhs, machine), nestedOps);
    }
    return "";
  }

  target::murphi::MessageHandler
  getMessageHandler(mlir::murphi::FunctionOp handleFunc) {
    std::string action = getStrAttrFromOp(handleFunc, "action");
    std::string machine = getStrAttrFromOp(handleFunc, "machine");

    // generate the message handler
    target::murphi::MessageHandler msgHandler(action);

    // iterate over all operations in the entry block
    for (mlir::Operation &nestedOp :
         handleFunc.getRegion().getBlocks().front().getOperations()) {
      msgHandler.add_operation_text(generateOperationMurphi(nestedOp, machine));
    }
    return msgHandler;
  }

  target::murphi::StateHandler getStateHandler(std::string stateId,
                                               std::string machineId) {
    target::murphi::StateHandler sh(stateId);
    moduleOp.walk([&](mlir::murphi::FunctionOp funOp) {
      std::string machine =
          funOp.getAttr("machine").cast<mlir::StringAttr>().getValue().str();
      std::string action =
          funOp.getAttr("action").cast<mlir::StringAttr>().getValue().str();
      std::string cur_state =
          funOp.getAttr("cur_state").cast<mlir::StringAttr>().getValue().str();
      // Filter over all possible messages that can be received
      if (!isCpuEvent(action) && machine == machineId && cur_state == stateId) {
        // For each such message -- possibly zero -- create a message handler
        target::murphi::MessageHandler msgHandler = getMessageHandler(funOp);
        // target::murphi::MessageHandler msgHandler(action);
        sh.addMessageHandler(msgHandler);
      }
    });
    return sh;
  }

  target::murphi::MachineHandlerFunction
  getMachineHandleFunction(std::string machId) {
    // Get the Cache State Enum
    target::murphi::MachineHandlerFunction handFunc(machId);
    target::murphi::Enum *states = dynamic_cast<target::murphi::Enum *>(
        murphiModule.findReference(machId + "_state"));
    for (auto state : states->getElements()) {
      // Generate a State Handler for each state
      target::murphi::StateHandler sh = getStateHandler(state, machId);
      handFunc.addStateHandler(sh);
    }
    return handFunc;
  }

  void addCacheFunction() {
    target::murphi::MachineHandlerFunction funcCache =
        getMachineHandleFunction("cache");
    murphiModule.addMachineHandleFunction(funcCache);
  }

  void addDirectoryFunction() {
    target::murphi::MachineHandlerFunction funcDir =
        getMachineHandleFunction("directory");
    murphiModule.addMachineHandleFunction(funcDir);
  }

  void addStartStateDefinition() {
    // Create a StartState Object
    target::murphi::StartState ss;

    // Body of the start state
    std::string body;
    // Add Cache and Directory Startstate Definitions
    moduleOp.walk([&](mlir::murphi::CacheDefOp cacheDefOp) {
      // String of operations
      std::string operations;

      // get the Fiels and Types arrays
      mlir::ArrayAttr fields =
          cacheDefOp.getAttr("fields").cast<mlir::ArrayAttr>();
      mlir::ArrayAttr types =
          cacheDefOp.getAttr("types").cast<mlir::ArrayAttr>();
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

    moduleOp.walk([&](mlir::murphi::DirectoryDefOp dirDefOp) {
      std::string operations;
      std::string machId = "directory";

      mlir::ArrayAttr fields =
          dirDefOp.getAttr("fields").cast<mlir::ArrayAttr>();
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
    moduleOp.walk([&](mlir::murphi::NetworkDeclOp netDeclOp) {
      std::string ordering = netDeclOp.getAttr("ordering")
                                 .cast<mlir::StringAttr>()
                                 .getValue()
                                 .str();
      std::string netId =
          netDeclOp.getAttr("id").cast<mlir::StringAttr>().getValue().str();
      if (ordering == "Ordered") {
        body += start_state_ordered_network(netId);
      } else {
        body += start_state_unordered_network(netId);
      }
      return mlir::WalkResult::advance();
    });

    // initialise mutexes as false
    if(!concurrent){
      body += mutex_start_state(murphiModule.findReference("cl_mut")->getDefiningId());
    }

    // Add the text to SS
    ss.addText(start_state_defintion(body));
    murphiModule.addStartState(ss);
  };

  void addCacheCPUEventFunctions() {
    moduleOp.walk([&](mlir::murphi::FunctionOp funcOp) {
      std::string action =
          funcOp.getAttr("action").cast<mlir::StringAttr>().getValue().str();
      std::string machine =
          funcOp.getAttr("machine").cast<mlir::StringAttr>().getValue().str();
      if (isCpuEvent(action) && machine == "cache") {
        std::string curState = funcOp.getAttr("cur_state")
                                   .cast<mlir::StringAttr>()
                                   .getValue()
                                   .str();
        target::murphi::CacheCPUEventFunction *cacheFunc =
            new target::murphi::CacheCPUEventFunction(curState, action);
        // Walk the nested Operations in the function and generate Murphi for
        // them
        for (mlir::Operation &nestedOp :
             funcOp.getRegion().getBlocks().front().getOperations()) {
          cacheFunc->addNestedOp(generateOperationMurphi(nestedOp, machine));
        }

        murphiModule.addCacheCPUEventFunction(cacheFunc);
      }
      return mlir::WalkResult::advance();
    });
  }

  void addCacheRuleset() {
    target::murphi::CacheRuleset c_ruleset;
    moduleOp.walk([&](mlir::murphi::FunctionOp funOp) {
      std::string action =
          funOp.getAttr("action").cast<mlir::StringAttr>().getValue().str();
      if (action == "load" || action == "store" || action == "evict") {
        std::string curState = funOp.getAttr("cur_state")
                                   .cast<mlir::StringAttr>()
                                   .getValue()
                                   .str();
        target::murphi::CacheRule cr =
            target::murphi::CacheRule(curState, action, concurrent);
        c_ruleset.addRule(cr);
      }
    });
    murphiModule.setCacheRuleset(c_ruleset);
  }

  void addNetworkRulesets() {
    moduleOp.walk([&](mlir::murphi::NetworkDeclOp netDecl) {
      std::string netId =
          netDecl.getAttr("id").cast<mlir::StringAttr>().getValue().str();
      std::string netOrder =
          netDecl.getAttr("ordering").cast<mlir::StringAttr>().getValue().str();
      target::murphi::NetworkOrder order =
          netOrder == "Ordered" ? target::murphi::NetworkOrder::Ordered
                                : target::murphi::NetworkOrder::Unordered;

      target::murphi::NetworkRuleset netRS(netId, order);
      murphiModule.addNetworkRuleset(netRS);
      return mlir::WalkResult::advance();
    });
  }
};

} // namespace murphiGenImpl

namespace mlir {
void registerToMurphiTranslation() {
  mlir::TranslateFromMLIRRegistration registration(
      "mlir-to-murphi",
      [](mlir::ModuleOp op, mlir::raw_ostream &output) {
        auto murphiGen = murphiGenImpl::MurphiGen(op, /*concurrent*/ false);
        auto &murphiModule = murphiGen.createModule();
        murphiModule.print(output);
        return mlir::success();
      },
      [](mlir::DialectRegistry &registry) {
        registry.insert<mlir::murphi::MurphiDialect>();
        registry.insert<mlir::StandardOpsDialect>();
      });
}
} // namespace mlir
