#include "mlir/IR/Dialect.h"
#include "mlir/IR/MLIRContext.h"
#include "mlir/InitAllDialects.h"
#include "mlir/InitAllPasses.h"
#include "mlir/Pass/Pass.h"
#include "mlir/Pass/PassManager.h"
#include "mlir/Support/FileUtilities.h"
#include "mlir/Support/MlirOptMain.h"
#include "llvm/Support/CommandLine.h"
#include "llvm/Support/InitLLVM.h"
#include "llvm/Support/SourceMgr.h"
#include "llvm/Support/ToolOutputFile.h"

#include "PCC/Dialect.h"
#include "Murphi/Dialect.h"
#include "Passes/PCCtoMurphiPass/Passes.h"

int main(int argc, char **argv) {
  mlir::registerAllPasses();
  // TODO: Register standalone passes here.
  mlir::registerAddTansientStatesPass();
  mlir::registerAddMutexReleasePass();
  mlir::registerConvertPCCToMurphiPass();
  mlir::registerProtogenOptimizationPass();
  mlir::registerStableCompilation();

  mlir::DialectRegistry registry;
  registry.insert<mlir::pcc::PCCDialect>();
  registry.insert<mlir::murphi::MurphiDialect>();
  registry.insert<mlir::StandardOpsDialect>();
  // Add the following to include *all* MLIR Core dialects, or selectively
  // include what you need like above. You only need to register dialects that
  // will be *parsed* by the tool, not the one generated
  // registerAllDialects(registry);

  return failed(
      mlir::MlirOptMain(argc, argv, "Standalone optimizer driver\n", registry));
}
