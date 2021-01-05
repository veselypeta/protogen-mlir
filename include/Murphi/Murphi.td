#ifndef MURPHI_DIALECT
#define MURPHI_DIALECT

include "mlir/IR/OpBase.td"
include "mlir/IR/SymbolInterfaces.td"
include "mlir/Interfaces/SideEffectInterfaces.td"
include "mlir/IR/RegionKindInterface.td"

//===----------------------------------------------------------------------===//
// Murphi dialect definition.
//===----------------------------------------------------------------------===//

def Murphi_Dialect : Dialect {
    let name = "murphi";
    let summary = "A Dialect for the Murphi language";
    let description = [{
        This Dialect is for representing code in the murphi model checker languager
    }];
    let cppNamespace = "::mlir::murphi";
}

//===----------------------------------------------------------------------===//
// Base Murphi operation definition.
//===----------------------------------------------------------------------===//
class Murphi_Op<string mnemonic, list<OpTrait> traits = []> :
        Op<Murphi_Dialect, mnemonic, traits>;


include "Types.td"
include "Ops.td"


#endif // MURPHI_DIALECT
