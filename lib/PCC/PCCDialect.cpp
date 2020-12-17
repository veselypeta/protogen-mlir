#include "PCC/Dialect.h"
#include "mlir/IR/DialectImplementation.h"
#include "llvm/ADT/TypeSwitch.h"

using namespace mlir;
using namespace mlir::pcc;

void PCCDialect::initialize() {
  addOperations<
#define GET_OP_LIST
#include "PCC/PCC.cpp.inc"
      >();

  addTypes<mlir::pcc::MsgType, mlir::pcc::NetType, ::mlir::pcc::DataType,
           mlir::pcc::IDType,
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
        .Case<mlir::pcc::NetType>([&](::mlir::Type t) {
          mlir::pcc::NetType netType = t.dyn_cast<mlir::pcc::NetType>();
          std::string ordering = netType.getOrdering();
          printer << "Network<" << ordering << ">";
        })
        .Case<mlir::pcc::DataType>([&](::mlir::Type t) {
          mlir::pcc::DataType dataType = t.dyn_cast<mlir::pcc::DataType>();
          printer << "Data";
        })
        .Case<mlir::pcc::IDType>([&](::mlir::Type t) {
          mlir::pcc::IDType idType = t.dyn_cast<mlir::pcc::IDType>();
          printer << "ID";
        })
        .Case<mlir::pcc::StateType>([&](::mlir::Type t) {
          mlir::pcc::StateType stateType = t.dyn_cast<mlir::pcc::StateType>();
          printer << "State<" << stateType.getState() << ">";
        })
        .Default([](::mlir::Type) {});
  }
}