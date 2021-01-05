#include "Target/TranslateToMurphi.h"
#include "Murphi/Dialect.h"

#include "mlir/Translation.h"
#include "mlir/Target/LLVMIR/ModuleTranslation.h"
#include "mlir/Dialect/StandardOps/IR/Ops.h"

#include <iostream>

// Perform house keeping tasks here -- setup the file correctly
void housekeeping(mlir::raw_ostream &output){

}

/// Convert MLIR to Murphi
void mlir::target::ModuleToMurphi(mlir::ModuleOp op, mlir::raw_ostream &output){
    output << "-- Starting the translation \n";

    op.walk([&](mlir::murphi::ConstantOp constOp) {
        auto value = constOp.getAttr("value").cast<mlir::IntegerAttr>().getInt();
        auto id = constOp.getAttr("id").cast<mlir::StringAttr>().getValue();
        output << "const " << id << " : " << value << "; \n";
    });
}


namespace mlir
{
    void registerToMurphiTranslation(){
        mlir::TranslateFromMLIRRegistration registration(
            "mlir-to-murphi",
            [](mlir::ModuleOp op, mlir::raw_ostream &output) {
                // TODO -- Run work here;
                mlir::target::ModuleToMurphi(op, output);
                return mlir::success();
            },
            [](mlir::DialectRegistry &registry){
                registry.insert<mlir::murphi::MurphiDialect>();
            }
        );
    }    
} // namespace mlir
