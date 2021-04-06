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


void pipelineBuilder(mlir::OpPassManager &pm){
    pm.addPass(mlir::createMutexReleasePass());
    pm.addPass(mlir::createAddTransientStatePass());
    pm.addPass(mlir::createPCCToMurphiPass());
    pm.addPass(mlir::createPCCToMurphiPass());
}

void mlir::registerStableCompilation(){
    mlir::PassPipelineRegistration<>(
        "compile-stable", "full compilation of pcc to muprhi (stable states)", pipelineBuilder
    );
}