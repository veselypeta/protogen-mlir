#include "PCC/Dialect.h"
#include "PCC/Ops.h"
#include "PCC/Types.h"
#include "mlir/IR/DialectImplementation.h"

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


// override the printType and parseType hooks
void mlir::pcc::PCCDialect::printType(mlir::Type type,
                           ::mlir::DialectAsmPrinter &printer) const {
  if (mlir::failed(generatedTypePrinter(type, printer))) {
    // Print Non-Table Generated PCC Types
    MsgType msgType = type.cast<mlir::pcc::MsgType>();

    // Print the msg type according to the parser format.
    printer << "msg<";
    llvm::interleaveComma(msgType.getElementTypes(), printer);
    printer << ">";
  }
}