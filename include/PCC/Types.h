#pragma once

#include "mlir/IR/Types.h"

#define GET_TYPEDEF_CLASSES
#include "PCC/PCCTypes.h.inc"

namespace mlir {
namespace pcc {
namespace detail {
struct MsgTypeStorage;
struct NetTypeStorage;
} // namespace detail

// Define the Msg Type
class MsgType
    : public mlir::Type::TypeBase<MsgType, mlir::Type, detail::MsgTypeStorage> {
public:
  // Inherit some necessary constructors from 'TypeBase'.
  using Base::Base;

  static MsgType get(llvm::ArrayRef<mlir::Type> elementTypes);

  llvm::ArrayRef<mlir::Type> getElementTypes();

  size_t getNumElementTypes() { return getElementTypes().size(); }
};

class NetType
    : public mlir::Type::TypeBase<NetType, mlir::Type, detail::NetTypeStorage> {
public:
  using Base::Base;

  static NetType get(mlir::MLIRContext *ctx, std::string ordering);

  std::string getOrdering();
};

class DataType
    : public mlir::Type::TypeBase<DataType, mlir::Type, mlir::TypeStorage> {
public:
  using Base::Base;
};
} // namespace pcc
} // namespace mlir
