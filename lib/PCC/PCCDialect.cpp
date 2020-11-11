#include "PCC/PCCDialect.h"
#include "PCC/PCCOps.h"


using namespace mlir;
using namespace mlir::pcc;

void PCCDialect::initialize() {
  addOperations<
#define GET_OP_LIST
#include "PCC/PCCOps.cpp.inc"
      >();

//   addTypes<
// #define GET_TYPEDEF_LIST
// #include "PCC/PCCOpsTypes.cpp.inc"
//       >();
}