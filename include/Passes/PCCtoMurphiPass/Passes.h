#pragma once

#include "mlir/Pass/Pass.h"

namespace mlir {
    class Pass;

    std::unique_ptr<::mlir::Pass> createLowerToMurphiPass();
    std::unique_ptr<::mlir::Pass> createMutexReleasePass();

    //===----------------------------------------------------------------------===//
    // Registration
    //===----------------------------------------------------------------------===//

    /// Generate the code for registering passes.
    #define GEN_PASS_CLASSES
    #define GEN_PASS_REGISTRATION
    #include "Passes/PCCtoMurphiPass/Passes.h.inc"

} // namespace mlir

