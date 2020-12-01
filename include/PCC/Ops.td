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
            OpBuilderDAG<(ins "Attribute":$id, "Attribute":$value), [{
                    build($_builder,$_state, value.getType(), id, value);
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
        let results = (outs PCC_NetType:$output);

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
                PCC_NetType:$network,
                PCC_MsgType:$msg
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
}

def GlobalNetworkOp : PCC_Op<"global_network", [ConstantLike]>{

        let summary = "get a reference to a global network";
        let description = [{
                This Operation returns and SSA value that references
                a global network
        }];

        let arguments = (ins StrAttr:$netId);
        let results = (outs PCC_NetType);
        
        let builders = [
                OpBuilderDAG<(ins "std::string":$netId), [{
                        build($_builder, $_state, mlir::pcc::NetType::get($_builder.getContext()), $_builder.getStringAttr(netId));
                }]>
        ];
}

def AwaitOp: PCC_Op<"await"> {

        let summary = "Start transaction Operation";
        let description =[{}];
        let regions = (region
                SizedRegion<1>:$body
        );
}

def AwaitReturnOp: PCC_Op<"await_return", [NoSideEffect, HasParent<"AwaitOp">, Terminator]>{
        let summary = "Await Return Operation";
        let description = [{}];
}

def WhenOp: PCC_Op<"when">{
        let summary = "Start of a When Operation";
        let description = [{}];

        let regions = (region 
                SizedRegion<1>:$body
        );
}

def BreakOp: PCC_Op<"break", [NoSideEffect, HasParent<"WhenOp">, Terminator]>{
        let summary = "Break out of a WhenOp";
        let description = [{}];
}

#endif // PCC_OPS
