set(LLVM_TARGET_DEFINITIONS Passes.td)
mlir_tablegen(Passes.h.inc -gen-pass-decls -name PCCToMurphi)
add_public_tablegen_target(MLIRPccToMurphiPassIncGen)
add_dependencies(mlir-headers MLIRPccToMurphiPassIncGen)