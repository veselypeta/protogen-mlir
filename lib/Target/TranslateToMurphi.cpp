#include "Target/TranslateToMurphi.h"
#include "Murphi/Dialect.h"

#include "Target/MurphiModule.h"
#include "mlir/Dialect/StandardOps/IR/Ops.h"
#include "mlir/Target/LLVMIR/ModuleTranslation.h"
#include "mlir/Translation.h"
#include "llvm/ADT/TypeSwitch.h"

#include <iostream>


/// Convert MLIR to Murphi -- OLD WAY
void mlir::target::ModuleToMurphi(mlir::ModuleOp op,
                                  mlir::raw_ostream &output) {
  output << "-- Starting the translation \n\n";
  // op.walk([&](){});

  // Output Constant Op Declarations in Murphi
  op.walk([&](mlir::murphi::ConstantOp constOp) {
    auto value = constOp.getAttr("value").cast<mlir::IntegerAttr>().getInt();
    auto id = constOp.getAttr("id").cast<mlir::StringAttr>().getValue();
    output << "const \t" << id << " : " << value << "; \n";
    return WalkResult::advance();
  });

  // Output Enum Op type Decalration in Murphi
  op.walk([&](mlir::murphi::EnumOp enumOp) {
    mlir::StringAttr idAttr = enumOp.getAttr("id").cast<mlir::StringAttr>();
    std::string id = idAttr.getValue().str();
    // Output initial output
    output << "type \t" << id << " : enum "
           << "{\n\t";
    mlir::ArrayAttr valuesAttr =
        enumOp.getAttr("values").cast<mlir::ArrayAttr>();
    std::vector<std::string> allValues;
    for (mlir::Attribute a : valuesAttr.getValue()) {
      mlir::StringAttr s = a.cast<mlir::StringAttr>();
      std::string enumValue = s.getValue().str();
      allValues.push_back(enumValue);
    }
    llvm::interleave(allValues, output, ",\n\t");

    output << "\n};\n\n";
    return WalkResult::advance();
  });

  // Output Scalarset Declartion type in Murphi
  op.walk([&](mlir::murphi::ScalarsetOp scaleOp) {
    std::string definingId =
        scaleOp.getAttr("id").cast<mlir::StringAttr>().getValue().str();

    mlir::Operation *operandOperation = scaleOp.getOperand().getDefiningOp();
    std::string valueId = operandOperation->getAttr("id")
                              .cast<mlir::StringAttr>()
                              .getValue()
                              .str();

    output << "type \t" << definingId << " : scalarset(" << valueId << ");\n";
    return WalkResult::advance();
  });

  // Output Murphi for Subrange Operation
  op.walk([&](mlir::murphi::SubrangeOp subOp) {
    std::string definingId =
        subOp.getAttr("id").cast<mlir::StringAttr>().getValue().str();

    // Get The ID of Start and End
    auto operands = subOp.getOperands();
    mlir::Operation *startOperation = operands[0].getDefiningOp();
    std::string startId =
        startOperation->getAttr("id").cast<mlir::StringAttr>().getValue().str();
    mlir::Operation *endOperation = operands[1].getDefiningOp();
    std::string endId =
        endOperation->getAttr("id").cast<mlir::StringAttr>().getValue().str();

    output << "type \t" << definingId << " : " << startId << ".." << endId
           << ";\n";
    return WalkResult::advance();
  });

  // Output Murphi for Union Operation
  op.walk([&](mlir::murphi::UnionOp unionOp) {
    std::string definingId =
        unionOp.getAttr("id").cast<mlir::StringAttr>().getValue().str();
    std::vector<std::string> operandIds;
    for (auto operand : unionOp.getOperands()) {
      std::string opId = operand.getDefiningOp()
                             ->getAttr("id")
                             .cast<mlir::StringAttr>()
                             .getValue()
                             .str();
      operandIds.push_back(opId);
    }

    output << "type \t" << definingId << " : union {";
    llvm::interleaveComma(operandIds, output);
    output << "};\n";
    return WalkResult::advance();
  });

  op.walk([&](mlir::murphi::RecordOp recOp) {
    std::string definingId =
        recOp.getAttr("id").cast<mlir::StringAttr>().getValue().str();
    auto allOperands = recOp.getOperands();
    auto valueIdsAttr = recOp.getAttr("valueIds").cast<mlir::ArrayAttr>();
    assert(allOperands.size() == valueIdsAttr.size());
    std::vector<std::pair<std::string, std::string>> idMap;
    for (int i = 0; i < (int)allOperands.size(); i++) {
      std::string structId =
          valueIdsAttr[i].cast<mlir::StringAttr>().getValue().str();
      std::string typeId = allOperands[i]
                               .getDefiningOp()
                               ->getAttr("id")
                               .cast<mlir::StringAttr>()
                               .getValue()
                               .str();
      idMap.push_back({structId, typeId});
    }

    // Output The record
    output << "type \t" << definingId << " : record \n";
    for (auto pair : idMap) {
      output << '\t' << pair.first << " : " << pair.second << ";\n";
    }
    output << "end;\n";
    return WalkResult::advance();
  });

  op.walk([&](mlir::murphi::ArrayOp arrOp) {
    std::string definingId =
        arrOp.getAttr("id").cast<mlir::StringAttr>().getValue().str();
    std::string sizeId = arrOp.getOperands()[0]
                             .getDefiningOp()
                             ->getAttr("id")
                             .cast<mlir::StringAttr>()
                             .getValue()
                             .str();
    std::string typeId = arrOp.getOperands()[1]
                             .getDefiningOp()
                             ->getAttr("id")
                             .cast<mlir::StringAttr>()
                             .getValue()
                             .str();

    // Output
    output << "type \t" << definingId << " : array[" << sizeId << "] of "
           << typeId << ";\n";
    return WalkResult::advance();
  });

  op.walk([&](mlir::murphi::MultisetOp multiOp) {
    std::string definingId =
        multiOp.getAttr("id").cast<mlir::StringAttr>().getValue().str();
    std::string sizeId = multiOp.getOperands()[0]
                             .getDefiningOp()
                             ->getAttr("id")
                             .cast<mlir::StringAttr>()
                             .getValue()
                             .str();
    std::string typeId = multiOp.getOperands()[1]
                             .getDefiningOp()
                             ->getAttr("id")
                             .cast<mlir::StringAttr>()
                             .getValue()
                             .str();

    // Output
    output << "type \t" << definingId << " : multiset[" << sizeId << "] of "
           << typeId << ";\n";

    return WalkResult::advance();
  });

  op.walk([&](mlir::murphi::FunctionOp f) {
    std::string definingId =
        f.getAttr("id").cast<mlir::StringAttr>().getValue().str();
    auto allOperands = f.getOperands();
    auto paramIds = f.getAttr("params").cast<mlir::ArrayAttr>();
    assert(allOperands.size() - 1 == paramIds.size());
    std::vector<std::string> paramMap;
    for (int i = 0; i < (int)paramIds.size(); i++) {
      std::string paramId = paramIds[i].cast<StringAttr>().getValue().str();
      std::string typeId = allOperands[i]
                               .getDefiningOp()
                               ->getAttr("id")
                               .cast<mlir::StringAttr>()
                               .getValue()
                               .str();
      paramMap.push_back(paramId + ": " + typeId);
    }
    std::string returnType = allOperands[allOperands.size() - 1]
                                 .getDefiningOp()
                                 ->getAttr("id")
                                 .cast<mlir::StringAttr>()
                                 .getValue()
                                 .str();

    output << "function " << definingId << "(";
    llvm::interleave(paramMap, output, "; ");
    output << ") : " << returnType << ";\n";

    // TODO Walk Var Decl Operations here
    f.walk([&](mlir::murphi::VarDeclOp v) {
      std::string definingId =
          v.getAttr("id").cast<mlir::StringAttr>().getValue().str();
      std::string typeId = v.getOperand()
                               .getDefiningOp()
                               ->getAttr("id")
                               .cast<mlir::StringAttr>()
                               .getValue()
                               .str();
      output << "var " << definingId << " : " << typeId << ";\n";
      return WalkResult::advance();
    });

    output << "begin\n";

    // TODO Walk Nested Operations Here
    f.walk([&](mlir::murphi::ReturnOp r) {
      std::string returnValueId = r.getOperand(0)
                                      .getDefiningOp()
                                      ->getAttr("id")
                                      .cast<mlir::StringAttr>()
                                      .getValue()
                                      .str();
      output << "return " << returnValueId << ";\n";
      return WalkResult::advance();
    });

    output << "end;\n";
    return WalkResult::advance();
  });
}

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
