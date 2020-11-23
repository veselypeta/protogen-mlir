#pragma once

#include "mlir/IR/Dialect.h"
#include "PCC/Types.h"
#include "PCC/Ops.h"

namespace mlir {
namespace pcc {

class PCCDialect : public ::mlir::Dialect {
  explicit PCCDialect(::mlir::MLIRContext *context)
    : ::mlir::Dialect(getDialectNamespace(), context,
      ::mlir::TypeID::get<PCCDialect>()) {
    
    initialize();
  }
  void initialize();
  friend class ::mlir::MLIRContext;
public:
  static ::llvm::StringRef getDialectNamespace() { return "pcc"; }
  // add custom type printers/parsers
//   Type parseType(DialectAsmParser &parser) const override;
  void printType(Type, DialectAsmPrinter &) const override;
};
} // namespace pcc
} // namespace mlir