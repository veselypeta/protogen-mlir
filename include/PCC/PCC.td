#ifndef PCC_DIALECT
#define PCC_DIALECT

include "mlir/IR/OpBase.td"
include "mlir/IR/SymbolInterfaces.td"
include "mlir/Interfaces/SideEffectInterfaces.td"
include "mlir/IR/RegionKindInterface.td"

//===----------------------------------------------------------------------===//
// PCC dialect definition.
//===----------------------------------------------------------------------===//

def PCC_Dialect : Dialect {
    let name = "pcc";
    let summary = "A Dialect for the PCC language";
    let description = [{
        This Dialect is for representing code in the pcc languge
    }];
    let cppNamespace = "::mlir::pcc";
}

//===----------------------------------------------------------------------===//
// Base PCC operation definition.
//===----------------------------------------------------------------------===//

class PCC_Op<string mnemonic, list<OpTrait> traits = []> :
        Op<PCC_Dialect, mnemonic, traits>;


include "Types.td"
include "Ops.td"


#endif // PCC_DIALECT