#include "Target/TranslateToMurphi.h"
#include "Murphi/Dialect.h"
#include "Target/MurphiModule.h"
#include "Target/MurphiTemplates.h"
#include "mlir/Dialect/StandardOps/IR/Ops.h"
#include "mlir/Target/LLVMIR/ModuleTranslation.h"
#include "mlir/Translation.h"
#include "llvm/ADT/TypeSwitch.h"
#include <iostream>

// Perform house keeping tasks here -- setup the file correctly
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

void setupMessageTypes(target::murphi::Module &m, mlir::ModuleOp op) {
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
      new target::murphi::Boilerplate("OBJ_Orderdcnt", OBJ_Orderedcnt);
  target::murphi::Boilerplate *objunorder =
      new target::murphi::Boilerplate("MACH_cache", OBJ_Unordered);

  m.addBoilerplate(mcache);
  m.addBoilerplate(mdir);
  m.addBoilerplate(objcache);
  m.addBoilerplate(objdir);
  m.addBoilerplate(objorder);
  m.addBoilerplate(ordercnt);
  m.addBoilerplate(objunorder);
}

void addVariableDeclarations(target::murphi::Module &m){
  target::murphi::Variable *i_cache = new target::murphi::Variable("i_cache", m.findReference("OBJ_cache"));
  target::murphi::Variable *i_directory = new target::murphi::Variable("i_directory", m.findReference("OBJ_directory"));

  m.addVariable(i_cache);
  m.addVariable(i_directory);
}

void setupMessageFactories(target::murphi::Module &m, mlir::ModuleOp op) {
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

target::murphi::Module createModule(mlir::ModuleOp op,
                                    mlir::raw_ostream &output) {
  target::murphi::Module m;

  op.walk([&](mlir::murphi::ConstantOp constOp) {
    int value = constOp.getAttr("value").cast<mlir::IntegerAttr>().getInt();
    std::string id =
        constOp.getAttr("id").cast<mlir::StringAttr>().getValue().str();

    target::murphi::Constant *constDecl =
        new target::murphi::Constant(id, value);
    m.addConstant(constDecl);

    return mlir::WalkResult::advance();
  });
  addBoilerplateConstants(m);
  addAccessEnum(m);

  op.walk([&](mlir::murphi::EnumOp enumOp) {
    std::string definingId =
        enumOp.getAttr("id").cast<mlir::StringAttr>().getValue().str();

    mlir::ArrayAttr valuesAttr =
        enumOp.getAttr("values").cast<mlir::ArrayAttr>();
    std::vector<std::string> allValues;

    for (mlir::Attribute a : valuesAttr.getValue()) {
      mlir::StringAttr s = a.cast<mlir::StringAttr>();
      std::string enumValue = s.getValue().str();
      allValues.push_back(enumValue);
    }

    // create enum in module
    target::murphi::Enum *enumDecl =
        new target::murphi::Enum(definingId, allValues);
    m.addEnum(enumDecl);
    return mlir::WalkResult::advance();
  });

  addAddressesAndCl(m);
  addCacheDirectoryObjectDefinitions(m);
  addCacheDirectoryDefinitions(m, op);
  setupMessageTypes(m, op);
  addBoilerplateTypes(m);
  addVariableDeclarations(m);

  setupMessageFactories(m, op);
  return m;
}

namespace mlir {
void registerToMurphiTranslation() {
  mlir::TranslateFromMLIRRegistration registration(
      "mlir-to-murphi",
      [](mlir::ModuleOp op, mlir::raw_ostream &output) {
        // TODO -- Run work here;
        // mlir::target::ModuleToMurphi(op, output);
        auto module = createModule(op, output);
        module.print(output);
        // target::murphi::Module module;
        // target::murphi::Module m;

        return mlir::success();
      },
      [](mlir::DialectRegistry &registry) {
        registry.insert<mlir::murphi::MurphiDialect>();
      });
}
} // namespace mlir
