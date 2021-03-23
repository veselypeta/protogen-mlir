#ifndef PCC_OPS
#define PCC_OPS
// Add ConstantLike
def ConstantOp : PCC_Op<"constant", []> {
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
            }]>,
            OpBuilderDAG<(ins "std::string":$id, "int":$integerValue), [{
                    build($_builder,$_state, $_builder.getStringAttr(id), $_builder.getI64IntegerAttr(integerValue));
            }]>,
            OpBuilderDAG<(ins "std::string":$id, "bool":$booleanValue), [{
                    build($_builder,$_state, $_builder.getStringAttr(id), $_builder.getBoolAttr(booleanValue));
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
        let results = (outs AnyType);

        // let builders = [
        //         OpBuilderDAG<(ins "std::string":$netId, "std::string":$ordering), [{
        //                 build($_builder, $_state, mlir::pcc::NetType::get($_builder.getContext(), ordering), $_builder.getStringAttr(netId), $_builder.getStringAttr(ordering));
        //         }]>
        // ];

}

def ReturnOp : PCC_Op<"return", [NoSideEffect, Terminator]> {
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
  let builders = [
        OpBuilderDAG<(ins ), [{
                mlir::Value v;
                build($_builder, $_state, v);
        }]>
  ];
}


def FunctionOp : PCC_Op<"function">{
        let summary = "represent a PCC function";
        let description = [{}];

        let arguments = (ins AnyAttr:$machine, AnyAttr:$cur_state, AnyAttr:$action, OptionalAttr<AnyAttr>:$end_state);

        let regions = (region SizedRegion<1>:$region);

        let builders = [
                OpBuilderDAG<(ins "std::string":$machine, "std::string":$cur_state, "std::string":$action), [{
                        $_state.addAttribute("machine", $_builder.getStringAttr(machine));
                        $_state.addAttribute("cur_state", $_builder.getStringAttr(cur_state));
                        $_state.addAttribute("action", $_builder.getStringAttr(action));
                        $_state.addRegion();
                }]>,
                OpBuilderDAG<(ins "std::string":$machine, "std::string":$cur_state, "std::string":$action, "std::string":$end_state), [{
                        $_state.addAttribute("machine", $_builder.getStringAttr(machine));
                        $_state.addAttribute("cur_state", $_builder.getStringAttr(cur_state));
                        $_state.addAttribute("action", $_builder.getStringAttr(action));
                        $_state.addAttribute("end_state", $_builder.getStringAttr(end_state));
                        $_state.addRegion();
                }]>
        ];
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

        // let arguments = (ins 
        //         PCC_NetType:$network,
        //         PCC_MsgType:$msg
        // );

        let arguments = (ins AnyType:$msg, AnyAttr:$netId);
}

// Add ConstantLike
def MsgConstrOp : PCC_Op<"msg_constr", [NoSideEffect]>{
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

        let arguments = (ins ArrayAttr:$params, AnyAttr:$msgType);
        let results = (outs AnyType:$out);

        // let arguments = (ins ArrayAttr:$value);
        // let results = (outs PCC_MsgType:$output);
}

// Add ConstantLike
def GlobalNetworkOp : PCC_Op<"global_network", []>{

        let summary = "get a reference to a global network";
        let description = [{
                This Operation returns and SSA value that references
                a global network
        }];

        let arguments = (ins StrAttr:$netId);
        let results = (outs PCC_NetType);
        
        let builders = [
                OpBuilderDAG<(ins "std::string":$netId), [{
                        build($_builder, $_state, mlir::pcc::NetType::get($_builder.getContext(), "Unordered"), $_builder.getStringAttr(netId));
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

def WhenOp: PCC_Op<"when", []>{
        let summary = "Start of a When Operation";
        let description = [{}];

        let regions = (region 
                SizedRegion<1>:$body
        );

        let arguments = (ins 
                StrAttr:$msgId
        );

        let builders = [
                OpBuilderDAG<(ins "std::string":$msgId), [{
                        build($_builder,$_state, $_builder.getStringAttr(msgId));
                }]>
        ];
}

def BreakOp: PCC_Op<"break", [NoSideEffect, HasParent<"WhenOp">, Terminator]>{
        let summary = "Break out of a WhenOp";
        let description = [{}];
}

def SetOp: PCC_Op<"set", []>{
        let summary = "Assign an SSA value to a global";
        let description = [{}];

        let arguments = (ins AnyAttr:$id, AnyAttr:$value);

        let builders = [
                OpBuilderDAG<(ins "std::string":$id, "std::string":$value) , [{
                        $_state.addAttribute("id", $_builder.getStringAttr(id));
                        $_state.addAttribute("value", $_builder.getStringAttr(value));
                }]>
        ];
}

def IfOp: PCC_Op<"if", []>{
        let summary = "If Operation for generaing if condition";
        let description = [{}];

        let arguments = (ins AnyAttr:$lhs, AnyAttr:$comparison, AnyAttr:$rhs);

        let regions = (region 
                SizedRegion<1>:$body
        );

        let builders = [
                OpBuilderDAG<(ins "std::string":$lhs, "std::string":$comparison, "std::string":$rhs) , [{
                        $_state.addAttribute("lhs", $_builder.getStringAttr(lhs));
                        $_state.addAttribute("comparison", $_builder.getStringAttr(comparison));
                        $_state.addAttribute("rhs", $_builder.getStringAttr(rhs));
                        $_state.addRegion();
                }]>
        ];
}

def ExIfOp: PCC_Op<"ifelse", [SingleBlockImplicitTerminator<"pcc::ReturnOp">, NoRegionArguments]>{
        let summary = "If op that operates on operand";
        let description = [{}];

        let arguments = (ins I1:$condition);

        let regions = (region 
                SizedRegion<1>:$thenRegion,
                AnyRegion:$elseRegion
                );

        let builders = [
                OpBuilderDAG<(ins "Value":$cond, "bool":$withElseRegion)>
        ];

        let extraClassDeclaration = [{
                mlir::Region &getThenRegion(){
                        return getRegion(0);
                }
                mlir::Region &getElseRegion(){
                        return getRegion(1);
                }
        }];

}

def ObjRefOp: PCC_Op<"obj_ref", []>{
        let summary = "reference a global object";
        let description = [{}];

        let arguments = (ins StrAttr:$objId, OptionalAttr<StrAttr>:$ident);
        let results = (outs AnyType);
}


def EnfIfOp: PCC_Op<"end_if", [Terminator, HasParent<"IfOp">]>{
        let summary = "end if op";
        let description = [{}];

}

def CompareOp: PCC_Op<"compare", []>{
        let summary = "compare two SSA values";
        let description = [{}];

        let arguments = (ins AnyType:$lhs, AnyType:$rhs, StrAttr:$oper, StrAttr:$id);
        let results = (outs I1);
}

def MathOp: PCC_Op<"math", []>{
        let summary = "perfomr math op";
        let description = [{}];
        let arguments = (ins AnyType:$lhs, AnyType:$rhs, StrAttr:$op, StrAttr:$id);
        let results = (outs AnyType);
}

// Set Operations
def SetAddOp: PCC_Op<"set_add", []>{
        let summary = "add an element to a set";
        let description = [{}];
        let arguments = (ins AnyType:$set, AnyType:$elem);
        // No results
}
// TO implement rest

def SetContainsOp: PCC_Op<"set_contains", []>{
        let summary = "set contains element";
        let description = [{}];
        let arguments = (ins AnyType:$set, AnyType:$elem);
        let results = (outs I1);
}

#endif // PCC_OPS
