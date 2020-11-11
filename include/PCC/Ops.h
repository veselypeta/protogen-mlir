#pragma once

#include "PCC/Dialect.h"
#include "PCC/Types.h"
#include "mlir/IR/Builders.h"
#include "mlir/IR/FunctionSupport.h"
#include "mlir/IR/RegionKindInterface.h"
#include "mlir/IR/SymbolTable.h"
#include "mlir/Interfaces/SideEffectInterfaces.h"

// inport table generated operations
#define GET_OP_CLASSES
#include "PCC/PCC.h.inc"
