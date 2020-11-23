#include "PCC/Dialect.h"
#include "PCC/Ops.h"
#include "PCC/Types.h"

using namespace mlir;
using namespace mlir::pcc;

void PCCDialect::initialize() {
  addOperations<
#define GET_OP_LIST
#include "PCC/PCC.cpp.inc"
      >();

  addTypes<
#define GET_TYPEDEF_LIST
#include "PCC/PCCTypes.cpp.inc"
      >();
}
