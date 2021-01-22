#pragma once
#include "mlir/Translation.h"
#include "mlir/Target/LLVMIR/ModuleTranslation.h"


namespace mlir {

void registerPCCToMlirTranslation();
} // namespace mlir