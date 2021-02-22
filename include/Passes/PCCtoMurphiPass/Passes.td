#ifndef PCC_TO_MURPHI_PASS
#define PCC_TO_MURPHI_PASS

include "mlir/Pass/PassBase.td"

def AddTansientStates : Pass<"add-transient-states", "ModuleOp"> {
    let summary = "Split Awaited Operations into Transient States";
    let constructor = "mlir::createAddTransientStatePass()";
}

def AddMutexRelease : Pass<"add-mutex-release", "ModuleOp">{
    let summary = "Adds mutex release operations after end of transactions";
    let constructor = "mlir::createMutexReleasePass()";
}

def ConvertPCCToMurphi : Pass<"pcc-to-murphi", "ModuleOp">{
    let summary = "Converts PCC Ops to Murphi Ops";
    let constructor = "mlir::createPCCToMurphiPass()";
}

def ProtogenOptimization : Pass<"protogen-optimization">{
    let summary = "Adds concurency to handle racing transactions";
    let constructor = "mlir::createProtogenOptimizationPass()";
}

#endif // PCC_TO_MURPHI_PASS