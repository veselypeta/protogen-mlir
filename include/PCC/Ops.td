#ifndef PCC_OPS
#define PCC_OPS

def ConstantOp : PCC_Op<"constant", [ConstantLike, NoSideEffect]> {
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
            OpBuilder<"Attribute id, Attribute value", [{
                    build($_builder, $_state, value.getType(), id, value);
            }]>
    ];
}

def NetworkDeclOp: PCC_Op<"network_decl", []> {

        let summary = "operation to declare global network";

        let description = [{
                Network Declaration Operation - produces and SSA value 
                to represent a global network, accessible throughout the code.

                Example:
                ```mlir
                        %0 = "pcc.network_decl"() {ordering: "Ordered", id: "fwd"} : () -> ()
                ```
        }];

        let arguments = (ins AnyAttr:$id, AnyAttr:$ordering);

        let results = (outs NetworkType:$output);
}

def SendOp: PCC_Op<"send", []>{
        let summary = "Operation to send a message along a network";

        let description = [{
                Send Operations - takes two parameters. 1st parameter is the Network
                Object along which to send the Message, 2nd parameter is the Message object.
                Example:
                ```mlir
                        %0 = "pcc.send"(%0: Network, %1: Msg): (Network, Msg) -> ()
                ```
        }];

        let arguments = (ins 
                AnyType:$network,
                AnyType:$msg
        );
}

def MsgConstrOp : PCC_Op<"msg_constr", [ConstantLike, NoSideEffect]>{
        let summary = "message constructor";
        let description = [{
                Construction Operation truns a literal message value into an SSA value. The data
                is attached to the operation as attribute. The Msg constant is encoded as an
                array of other constant values.
                ```mlir
                %0 = pcc.msg_constr [
                        32: i64
                ] : !pcc.msg<tensor<*xf64>>
                ```
        }];

        let arguments = (ins ArrayAttr:$value);
        let results = (outs PCC_MsgType:$output);

        // let assemblyFormat = "$value attr-dict `:` type($output)";

}

#endif // PCC_OPS
