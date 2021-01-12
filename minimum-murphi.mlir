module {
    // Need to know defined constants in MLIR
    %nrCaches = "murphi.constant"(){id="nrCaches", value=3} : () -> i64

    // Need to know all the message ids
    %MessageType = "murphi.enum"() {id="MessageType", values=["GetM", "Fwd_GetM", "GetM_Ack_D", "PutM", "Put_Ack"]} : () -> i64

    %cache_state = "murphi.enum"() {id="MessageType", values=["cache_M", "cache_I_M_D", "cache_I", "cache_M_I_Ack"]} : () -> i64
    %directory_state = "murphi.enum"() {id="MessageType", values=["directory_I", "directory_M"]} : () -> i64

    // %Request = "murphi.message_decl"(){id="Request", types=[]} : () -> i64
    // %Ack = "murphi.message_decl"(){id="Ack", types=[]} : () -> i64
    // %Response = "murphi.message_decl"(){id="Response", types=["Data:cl"]} : () -> i64
    // %ResponseAck = "murphi.message_decl"(){id="ResponseAck", type=["Data:cl"]}: () -> i64


    // Need to know Cache and Directory States (inc transient states)
    // %cacheState = "murphi.enum"(){} : () -> ()
    // %directoryState = "murphi.enum"(){} : () -> ()

    // Need the structure of Cache and Directory

}