#include "PCC/Dialect.h"
#include "PCC/Ops.h"
#include "PCC/Types.h"
#include "mlir/IR/DialectImplementation.h"
#include "llvm/ADT/TypeSwitch.h"

using namespace mlir;
using namespace mlir::pcc;

void PCCDialect::initialize() {
  addOperations<
#define GET_OP_LIST
#include "PCC/PCC.cpp.inc"
      >();

  addTypes<mlir::pcc::MsgType, mlir::pcc::NetType,
#define GET_TYPEDEF_LIST
#include "PCC/PCCTypes.cpp.inc"
           >();
}

// override the printType and parseType hooks
void mlir::pcc::PCCDialect::printType(
    mlir::Type type, ::mlir::DialectAsmPrinter &printer) const {

  if (!mlir::succeeded(mlir::pcc::generatedTypePrinter(type, printer))) {
    // Print Non-Table Generated PCC Types
    ::llvm::TypeSwitch<::mlir::Type>(type)
        .Case<mlir::pcc::MsgType>([&](::mlir::Type t) {
          MsgType msgType = t.dyn_cast<mlir::pcc::MsgType>();
          printer << "msg<";
          llvm::interleaveComma(msgType.getElementTypes(), printer);
          printer << ">";
        })
        .Case<mlir::pcc::NetType>([&](::mlir::Type t){
          mlir::pcc::NetType netType = t.dyn_cast<mlir::pcc::NetType>();
          printer << "Network";
        })
        .Default([](::mlir::Type) {});
  }
}