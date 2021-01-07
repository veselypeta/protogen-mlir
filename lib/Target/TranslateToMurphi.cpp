#include "Target/TranslateToMurphi.h"
#include "Murphi/Dialect.h"

#include "mlir/Dialect/StandardOps/IR/Ops.h"
#include "mlir/Target/LLVMIR/ModuleTranslation.h"
#include "mlir/Translation.h"
#include "llvm/ADT/TypeSwitch.h"

#include <iostream>

// Perform house keeping tasks here -- setup the file correctly
void housekeeping(mlir::raw_ostream &output) {}

/// Convert MLIR to Murphi
void mlir::target::ModuleToMurphi(mlir::ModuleOp op,
                                  mlir::raw_ostream &output) {
  output << "-- Starting the translation \n\n";
  // op.walk([&](){});

  // Output Constant Op Declarations in Murphi
  op.walk([&](mlir::murphi::ConstantOp constOp) {
    auto value = constOp.getAttr("value").cast<mlir::IntegerAttr>().getInt();
    auto id = constOp.getAttr("id").cast<mlir::StringAttr>().getValue();
    output << "const \t" << id << " : " << value << "; \n";
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

    
    // TODO Walk Nested Operations Here

    output << "begin\n";
    op.walk([&](mlir::murphi::RecordOp r) { output << "Return Op was here"; });
    output << "end;\n";
  });

}

namespace mlir {
void registerToMurphiTranslation() {
  mlir::TranslateFromMLIRRegistration registration(
      "mlir-to-murphi",
      [](mlir::ModuleOp op, mlir::raw_ostream &output) {
        // TODO -- Run work here;
        mlir::target::ModuleToMurphi(op, output);
        return mlir::success();
      },
      [](mlir::DialectRegistry &registry) {
        registry.insert<mlir::murphi::MurphiDialect>();
      });
}
} // namespace mlir
