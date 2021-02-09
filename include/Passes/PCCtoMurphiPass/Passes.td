#ifndef PCC_TO_MURPHI_PASS
#define PCC_TO_MURPHI_PASS

include "mlir/Pass/PassBase.td"

def PCCToMurphiPass : Pass<"convert-pcc-to-murphi", "ModuleOp"> {
    let summary = "Convert PCC dialect to murphi dialect";
    let constructor = "mlir::createLowerToMurphiPass()";
}

def AddMutexRelease : Pass<"add-mutex-release", "ModuleOp">{
    let summary = "Adds mutex release operations after end of transactions";
    let constructor = "mlir::createMutexReleasePass()";
}

#endif // PCC_TO_MURPHI_PASS