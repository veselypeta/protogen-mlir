module {


    %nrCaches = "murphi.constant"() {value = 32: i64, id = "nrCaches"} : () -> i64
    %VAL_COUNT = "murphi.constant"() {value = 1: i64, id = "VAL_COUNT"} : () -> i64
    %ADR_COUNT = "murphi.constant"() {value = 1: i64, id = "ADR_COUNT"} : () -> i64

    %O_NET_MAX = "murphi.constant"() {value = 12: i64, id = "O_NET_MAX"} : () -> i64
    %U_NET_MAX = "murphi.constant"() {value = 12: i64, id = "U_NET_MAX"} : () -> i64

    %ZERO = "murphi.constant"() {value = 0: i64, id = "ZERO"}: () -> i64


    %Access = "murphi.enum"() {id="Access", values=["none", "load", "store"]} : () -> i64
    %MessageType = "murphi.enum"() {id="MessageType", values=["GetM", "Fwd_GetM", "GetM_Ack_D", "PutM", "Put_Ack"]} : () -> i64
    %Address = "murphi.scalarset"(%ADR_COUNT){id="Address"} : (i64) -> i64
    %ClValue = "murphi.subrange"(%ZERO, %VAL_COUNT){id="ClValue"} : (i64, i64) -> i64


    %OBJSET_cache = "murphi.scalarset"(%nrCaches){id="OBJSET_cache"} : (i64) -> i64

    %OBJSET_directory = "murphi.enum"(){id="OBJSET_directory", values=["directory"]} : () -> i64

    %Machines = "murphi.union" (%OBJSET_cache, %OBJSET_directory) {id="Machines"} : (i64, i64) -> i64


    %Message = "murphi.record"(%Address, %MessageType, %Machines, %Machines, %ClValue) {id="Message", valueIds=["adr", "mtype", "src", "dst", "cl"]} : (i64, i64, i64, i64, i64) -> i64
    
    %MyArray = "murphi.array"(%Machines, %Message) {id="MyArray"} : (i64, i64) -> i64

    %MyMultiset = "murphi.multiset"(%U_NET_MAX, %Message) {id="MyMultiset"} : (i64, i64) -> i64

    %myVar = "murphi.var_decl"(%OBJSET_cache) {id = "i_cache"} : (i64) -> i64

    %Request = "murphi.function"(%Address, %MessageType, %Machines, %Machines, %Message)({
        %msg = "murphi.var_decl"(%Message) {id = "msg"} : (i64) -> i64
        // "murphi.assign"(%msg){index="adr", assignValue="dst"} : (i64, i64) -> ()

        "murphi.return" (%msg) : (i64) -> ()
    }){id="Request", params=["adr", "mtype", "src", "dst"]} : (i64, i64, i64, i64, i64) -> i64

    func @directory_M_PutM(%input: i64) -> i64 {
      "murphi.return"(%input): (i64)->()
    }


}