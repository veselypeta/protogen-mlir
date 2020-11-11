#ifndef PCC_TO_MURPHI_PASS
#define PCC_TO_MURPHI_PASS

include "mlir/Pass/PassBase.td"

def PCCToMurphiPass : Pass<"convert-pcc-to-murphi", "ModuleOp"> {
    let summary = "Convert PCC dialect to murphi dialect";
    let constructor = "mlir::createLowerToMurphiPass()";
}

#endif // PCC_TO_MURPHI_PASS