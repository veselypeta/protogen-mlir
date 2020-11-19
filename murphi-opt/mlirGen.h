#pragma once
#include "mlir/IR/MLIRContext.h"
#include "mlir/IR/Module.h"
#include "ProtoCCParser.h"

#include <memory>

namespace mlir {
class MLIRContext;
class OwningModuleRef;
} // namespace mlir

namespace pcc {
class ModuleAST;

/// Emit IR for the given Toy moduleAST, returns a newly created MLIR module
/// or nullptr on failure.
mlir::OwningModuleRef mlirGen(mlir::MLIRContext &mlirCtx, ProtoCCParser::DocumentContext *docCtx);
} // namespace toy