#pragma once
#include "mlir/Translation.h"
#include "mlir/Target/LLVMIR/ModuleTranslation.h"


namespace mlir {
namespace target {
void ModuleToMurphi(mlir::ModuleOp op, mlir::raw_ostream &output);
} // namespace target

void registerToMurphiTranslation();
} // namespace mlir
