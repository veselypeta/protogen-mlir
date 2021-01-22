#include "TranslatePCCToMLIR.h"
#include "Murphi/Dialect.h"
#include "PCC/Dialect.h"
#include "ProtoCCLexer.h"
#include "ProtoCCParser.h"
#include "mlir/Dialect/StandardOps/IR/Ops.h"
#include "mlirGen.h"
#include "PCC/Dialect.h"
#include "Murphi/Dialect.h"
#include "mlir/IR/AsmState.h"
#include "mlir/IR/Dialect.h"
#include "mlir/IR/MLIRContext.h"
#include "mlir/InitAllDialects.h"
#include "mlir/InitAllPasses.h"

#include <iostream>

mlir::ModuleOp PCCMLIRGen(llvm::StringRef strRef, mlir::MLIRContext *context) {
  const unsigned char *s = strRef.bytes_begin();
  auto ss = reinterpret_cast<const char *>(s);
  std::string inputFileStr(ss);

  antlr4::ANTLRInputStream input(inputFileStr);
  ProtoCCLexer lexer(&input);
  antlr4::CommonTokenStream tokens(&lexer);

  ProtoCCParser parser(&tokens);
  ProtoCCParser::DocumentContext *tree = parser.document();

  return pcc::mlirGen(*context, tree);
}

namespace mlir {
void registerPCCToMlirTranslation() {
  mlir::TranslateToMLIRRegistration registration(
      "pcc-to-mlir", [](llvm::StringRef strRef, mlir::MLIRContext *context) {
        context->getOrLoadDialect<mlir::pcc::PCCDialect>();
        context->getOrLoadDialect<mlir::murphi::MurphiDialect>();
        context->getOrLoadDialect<mlir::StandardOpsDialect>();
        context->getOrLoadDialect<mlir::scf::SCFDialect>();
        return PCCMLIRGen(strRef, context);
        // mlir::OpBuilder builder(context);
        // return builder.create<mlir::ModuleOp>(builder.getUnknownLoc());
      });
}
} // namespace mlir