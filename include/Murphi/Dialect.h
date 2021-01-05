#pragma once

#include "Murphi/Ops.h"
#include "Murphi/Types.h"
#include "mlir/IR/Dialect.h"

namespace mlir {
namespace murphi {
class MurphiDialect : public mlir::Dialect {
  explicit MurphiDialect(::mlir::MLIRContext *context)
      : ::mlir::Dialect(getDialectNamespace(), context,
                        ::mlir::TypeID::get<MurphiDialect>()) {

    initialize();
  }
  void initialize();
  friend class ::mlir::MLIRContext;

public:
  static ::llvm::StringRef getDialectNamespace() { return "murphi"; }
  // add custom type printers/parsers
  //   Type parseType(DialectAsmParser &parser) const override;
  //   void printType(Type, DialectAsmPrinter &) const override;
};
} // namespace murphi
} // namespace mlir
