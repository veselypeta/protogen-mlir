#include "Murphi/Dialect.h"
#include "Murphi/Ops.h"
#include "PCC/Dialect.h"
#include "PCC/Ops.h"
#include "Passes/PCCtoMurphiPass/Passes.h"

#include "mlir/IR/Attributes.h"
#include "mlir/IR/Builders.h"
#include "mlir/IR/Function.h"
#include "mlir/IR/MLIRContext.h"
#include "mlir/IR/Module.h"
#include "mlir/IR/StandardTypes.h"
#include "mlir/IR/Verifier.h"
#include "mlir/InitAllDialects.h"
#include "mlir/Pass/Pass.h"
#include "mlir/Transforms/DialectConversion.h"
#include "mlir/Transforms/GreedyPatternRewriteDriver.h"
#include "mlir/Transforms/InliningUtils.h"
#include "llvm/ADT/Sequence.h"

#include <iostream>

using namespace mlir;

bool isCpuEvent(std::string event){
  return event == "load" || event == "store" || event == "evict";
}

namespace {
struct MutexPass : public mlir::AddMutexReleaseBase<MutexPass> {
  void getDependentDialects(mlir::DialectRegistry &registry) const override {
    registry.insert<mlir::murphi::MurphiDialect>();
    registry.insert<mlir::pcc::PCCDialect>();
  }
  void runOnOperation() override;
  void insertMutexRelease(mlir::pcc::FunctionOp funOp);
  void insertMutexRelease(mlir::pcc::AwaitOp awaitOp, mlir::OpBuilder &builder);
};
} // namespace

void MutexPass::runOnOperation() {

  mlir::ModuleOp moduleOp = getOperation();

  // for each function insert possible release mutex points
  for (mlir::Operation &op :
       moduleOp.getRegion().getBlocks().front().getOperations()) {
    // test if it's a function Op
    mlir::pcc::FunctionOp funOp = mlir::dyn_cast<mlir::pcc::FunctionOp>(op);
    if (funOp != nullptr) {
      // check if we are dealing with a cache
      std::string machine =
          funOp.getAttr("machine").cast<mlir::StringAttr>().getValue().str();
      if (machine == "cache") {
        insertMutexRelease(funOp);
      }
    }
  }
}

void MutexPass::insertMutexRelease(mlir::pcc::FunctionOp funOp) {
  // create an operation builder
  mlir::OpBuilder builder(&getContext());

  // check if there is an await in the function
  bool containsAwait = false;
  for (mlir::Operation &op :
       funOp.getRegion().getBlocks().front().getOperations()) {
    if (mlir::dyn_cast<mlir::pcc::AwaitOp>(op) != nullptr) {
      containsAwait = true;
    }
  }

  // we only release in cpu event functions
  std::string action = funOp.getAttr("action").cast<mlir::StringAttr>().getValue().str();
  if(!isCpuEvent(action)){
    return;
  }

  if (containsAwait) {
    // Release Mutex must be inserted somewhere in the await
    // for each await
    return;
  }
  // otherwise we insert a release mutex at the end of the funciton

  // find the last operation
  mlir::Operation *lastOp = nullptr;
  for (mlir::Operation &op :
       funOp.getRegion().getBlocks().front().getOperations()) {
    if (mlir::dyn_cast<mlir::pcc::ReturnOp>(op)) {
      break;
    }
    lastOp = &op;
  }
  // if the function contains no operations -- other than return
  if (lastOp == nullptr) {
    // Set Insertion point to start of the entry block
    builder.setInsertionPointToStart(&funOp.getRegion().getBlocks().front());
  } else {
    builder.setInsertionPointAfter(lastOp);
  }

  builder.create<mlir::murphi::ReleaseMutexOp>(builder.getUnknownLoc());
}

// this is a function that returns the created pass
std::unique_ptr<::mlir::Pass> mlir::createMutexReleasePass() {
  return std::make_unique<MutexPass>();
}