#include "mlir/InitAllTranslations.h"
#include "mlir/Support/LogicalResult.h"
#include "mlir/Translation.h"
#include "Murphi/Dialect.h"
#include "Target/TranslateToMurphi.h"

int main(int argc, char **argv){
    mlir::registerAllTranslations();

    mlir::registerToMurphiTranslation();

    return failed(
        mlir::mlirTranslateMain(argc, argv, "Murphi Translation Tool")
    );
}