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

def EnumOp : Murphi_Op<"enum"> {
        let summary = "declare an enum";
        let description = [{}];

        let arguments = (ins AnyAttr: $id, ArrayAttr:$values);
        let results = (outs AnyType);
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
  let arguments = (ins Optional<AnyType>:$ret);
}


def FunctionOp : Murphi_Op<"function">{
        let summary = "represent a murphi function";
        let description = [{}];

        let arguments = (ins AnyAttr:$machine, AnyAttr:$cur_state, AnyAttr:$action);

        let regions = (region SizedRegion<1>:$region);
}

def CacheDefOp : Murphi_Op<"cache_definition">{
        let summary = "definition of a cache";
        let description = [{}];

        let arguments = (ins ArrayAttr:$fields, ArrayAttr:$types);
}

def DirectoryDefOp : Murphi_Op<"directory_definition">{
        let summary = "definition of a directory";
        let description = [{}];

        let arguments = (ins ArrayAttr:$fields, ArrayAttr:$types);
}

def MessageDefOp : Murphi_Op<"message_definition">{
        let summary = "message defintion";
        let description = [{}];

        let arguments = (ins AnyAttr:$id, ArrayAttr:$fields, ArrayAttr:$types);
}

def NetworkDeclOp: Murphi_Op<"network_decl", []> {

        let summary = "operation to declare global network";

        let description = [{

                Example:
                ```mlir
                        "pcc.network_decl"() {ordering: "Ordered", id: "fwd"} : () -> ()
                ```
        }];

        let arguments = (ins AnyAttr:$id, AnyAttr:$ordering);
        
        
}

def MsgConstrOp : Murphi_Op<"msg_constr", [NoSideEffect]>{
        let summary = "message constructor";
        let description = [{}];
        let arguments = (ins ArrayAttr:$parameters);
        let results = (outs AnyType:$output);
}





// def TypeDeclOp : Murphi_Op<"type_decl"> {
//         let summary = "Group all Type Declaration";
//         let description = [{"In Murphi Types are group with the type keyword:
//                 type
//                         Access: enum {
//                                 none,
//                                 load,
//                                 store
//                         };

//                         MessageType : enum {
//                                 GetM,
//                                 Fwd_GetM,
//                                 GetM_Ack_D,
//                                 PutM,
//                                 Put_Ack
//                         };

                
//                 Example:
//                 ```mlir
//                         "murphi.type_decl() ( {
                                
//                         })
//                 ```

//         "}];
//         let regions = (region SizedRegion<1>:$region);
// }



// def ScalarsetOp : Murphi_Op<"scalarset">{
//         let summary = "declare a scalarset operation";
//         let description = [{}];

//         let arguments = (ins AnyAttr:$id, AnyType:$value);
//         let results = (outs AnyType);
// }

// def SubrangeOp : Murphi_Op<"subrange">{
//         let summary = "define an integer subrange";
//         let description = [{}];

//         let arguments = (ins AnyType:$start, AnyType:$end, AnyAttr:$id);
//         let results = (outs AnyType);
// }

// def UnionOp : Murphi_Op<"union">{
//         let summary = "define a union of enums";
//         let description = [{}];

//         let arguments = (ins Variadic<AnyType>:$input, AnyAttr:$id);

//         let results = (outs AnyType);
// }

// def RecordOp : Murphi_Op<"record">{
//         let summary = "define a record/object";
//         let description = [{}];

//         let arguments = (ins Variadic<AnyType>:$input, AnyAttr:$id, ArrayAttr:$valueIds);
//         let results = (outs AnyType);
// }

// def ArrayOp : Murphi_Op<"array">{
//         let summary = "define an array in murphi";

//         let description = [{}];

//         let arguments = (ins AnyType:$arrySize, AnyType:$arrayType, AnyAttr:$id);
//         let results = (outs AnyType);
// }

// def MultisetOp : Murphi_Op<"multiset">{
//         let summary = "define multiset Op";
//         let description = [{}];

//         let arguments = (ins AnyType:$size, AnyType:$type, AnyAttr:$id);
//         let results = (outs AnyType);
// }

// def VarDeclOp : Murphi_Op<"var_decl">{
//         let summary = "declare a variable";
//         let description = [{}];

//         let arguments = (ins AnyType:$typeExpr, AnyAttr:$id);
//         let results = (outs AnyType);
// }


// def ConstantDecl: Murphi_Op<"constant_decl"> {
//         let summary = "group all contant operation";
//         let description = [{"In Murphi Constants are group with the const keyword:
//                 const
//                         nrCache : 3;
//                         ADR_COUNT : 1;

                
//                 Example:
//                 ```mlir
//                         "murphi.constant_decl() ( {
//                                 %0 = "murphi.constant" () {value = 3, id = "nrCaches"} : () -> ()
//                                 %1 = "murphi.constant" () {value = 1, id = "ADR_COUNT"} : () -> ()
//                         })
//                 ```

//         "}];

//         let regions = (region SizedRegion<1>:$region);
// }


#endif // MURPHI_OPS
