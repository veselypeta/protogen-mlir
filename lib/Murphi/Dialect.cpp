#include "Murphi/Dialect.h"
#include "Murphi/Ops.h"

using namespace mlir;
using namespace mlir::murphi;

//===----------------------------------------------------------------------===//
// Murphi dialect.
//===----------------------------------------------------------------------===//

void MurphiDialect::initialize() {
  addOperations<
#define GET_OP_LIST
#include "Murphi/Murphi.cpp.inc"
      >();
}
