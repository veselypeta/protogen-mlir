//===- MurphiDialect.td - Murphi dialect -----------*- tablegen -*-===//
//
// This file is licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef MURPHI_DIALECT
#define MURPHI_DIALECT

include "mlir/IR/OpBase.td"

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


#endif // MURPHI_DIALECT
