#include "PCC/Types.h"
#include "mlir/IR/DialectImplementation.h"
#include "llvm/ADT/StringExtras.h"
#include "llvm/ADT/StringSwitch.h"
#include "llvm/ADT/TypeSwitch.h"

#define GET_TYPEDEF_CLASSES
#include "PCC/PCCTypes.cpp.inc"

// ----------------------------------------------
// PCC Types
// ----------------------------------------------

namespace mlir {
namespace pcc {
namespace detail {

// Class to represent internal storage of the Msg Type
struct MsgTypeStorage : public mlir::TypeStorage {
  // KeyTy is required to provide an interface to the storage instance. This
  // will be used when uniqing an instance of the type storage. For the message
  // type we will unique each instance structurally on the element types

  using KeyTy = llvm::ArrayRef<mlir::Type>;

  // constructor for the type storage object
  MsgTypeStorage(llvm::ArrayRef<mlir::Type> elementTypes)
      : elementTypes(elementTypes) {}

  // define comparison operator
  bool operator==(const KeyTy &key) const { return key == elementTypes; }

  // define a hash function for key type
  static llvm::hash_code hashKey(const KeyTy &key) {
    return llvm::hash_value(key);
  }

  // define construction function
  static KeyTy getKey(llvm::ArrayRef<mlir::Type> elementTypes) {
    return KeyTy(elementTypes);
  }

  // define a construction method
  static MsgTypeStorage *construct(mlir::TypeStorageAllocator &allocator,
                                   const KeyTy &key) {
    // copy the elements from the provided 'KeyTy' into the allocator
    llvm::ArrayRef<mlir::Type> elementTypes = allocator.copyInto(key);

    // allocate the storage instance and construct it
    return new (allocator.allocate<MsgTypeStorage>())
        MsgTypeStorage(elementTypes);
  }

  /// The following field contains the element types of the Msg Type.
  llvm::ArrayRef<mlir::Type> elementTypes;
};
} // namespace detail
} // namespace pcc
} // namespace mlir

mlir::pcc::MsgType mlir::pcc::MsgType::get(llvm::ArrayRef<mlir::Type> elementTypes) {
  assert(!elementTypes.empty() && "expected at least 1 element type");

  mlir::MLIRContext *ctx = elementTypes.front().getContext();
  return Base::get(ctx, elementTypes);
}

llvm::ArrayRef<mlir::Type> mlir::pcc::MsgType::getElementTypes() {
  // 'getImpl' returns a pointer to the internal storage instance.
  return getImpl()->elementTypes;
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