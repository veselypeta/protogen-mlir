//===- StandaloneOps.td - Standalone dialect ops -----------*- tablegen -*-===//
//
// This file is licensed under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

#ifndef MURPHI_OPS
#define MURPHI_OPS
// Add ConstantLike
def ConstantOp : Murphi_Op<"constant", [NoSideEffect]> {
    let summary = "constant";
    let description = [{
            Constant operation produces an SSA value of some constant value
            in a value attribute.

            Example:
            ```mlir
            %0 = "pcc.constant"() {value = 32: i32, id = "nrCaches"} : () -> i32
            ```
    }];

    let arguments = (ins AnyAttr: $id, AnyAttr:$value);
    let results = (outs AnyType);

    let builders = [
            OpBuilderDAG<(ins "Attribute":$id, "Attribute":$value), [{
                    build($_builder,$_state, value.getType(), id, value);
            }]>
    ];
}

def ConstantDecl: Murphi_Op<"constant_decl"> {
        let summary = "group all contant operation";
        let description = [{"a descriptions"}];

        let regions = (region SizedRegion<1>:$region);

}

def ReturnOp : Murphi_Op<"return", [NoSideEffect, Terminator]> {
  let summary = "return operation";
  let description = [{
    The `return` operation represents a return operation within a function.
    The operation takes variable number of operands and produces no results.
    The operand number and types must match the signature of the function
    that contains the operation.

    Example:

    ```mlir
    "murphi.constant_decl"()({
            "murphi.return"(): () -> ()
    }): () -> ()
    ```
  }];
}


#endif // MURPHI_OPS
