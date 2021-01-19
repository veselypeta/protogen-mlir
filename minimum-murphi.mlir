module {
    // Need to know defined constants in MLIR
    %nrCaches = "murphi.constant"(){id="nrCaches", value=3} : () -> i64

    // Need to know all the message ids
    %MessageType = "murphi.enum"() {id="MessageType", values=["GetM", "Fwd_GetM", "GetM_Ack_D", "PutM", "Put_Ack"]} : () -> i64

    %cache_state = "murphi.enum"() {id="cache_state", values=["cache_M", "cache_I_M_D", "cache_I", "cache_M_I_Ack"]} : () -> i64
    %directory_state = "murphi.enum"() {id="directory_state", values=["directory_I", "directory_M"]} : () -> i64

    "murphi.cache_definition" () {fields=["State", "cl"], types=["I", "Data"]} : () -> ()
    "murphi.directory_definition"() {fields=["State", "cl", "owner"], types=["I", "Data", "ID"]} : () -> ()

    "murphi.message_definition"() {id="Request", fields=[], types=[]} : () -> ()
    "murphi.message_definition"() {id="Ack", fields=[], types=[]} : () -> ()
    "murphi.message_definition"() {id="Response", fields=["cl"], types=["Data"]} : () -> ()
    "murphi.message_definition"() {id="RespAck", fields=["cl"], types=["Data"]} : () -> ()

    "murphi.network_decl"() {ordering ="Ordered", id="fwd"} : () -> ()
    "murphi.network_decl"() {ordering="Unordered", id="resp"} : () -> ()
    "murphi.network_decl"() {ordering="Unordered", id="req"} : () -> ()


    "murphi.function"()({
        // msg = Request(GetM, ID, directory.ID);
        // %msg = "murphi.msg_constr"(){params=["GetM", "ID", "directory.ID"]} : () -> i64
        // req.send(msg);
        // "murphi.send"(%msg) : (i64) -> ()
        "murphi.return" () :  () -> ()
    }){machine="cache", cur_state="cache_I", action="load"} : () -> ()

    "murphi.function"()({
        "murphi.return" () :  () -> ()
    }){machine="cache", cur_state="cache_I_load", action="GetM_Ack_D"} : () -> ()

    "murphi.function"()({
        "murphi.return" () :  () -> ()
    }){machine="cache", cur_state="cache_I", action="store"} : () -> ()

    "murphi.function"()({
        "murphi.return" () :  () -> ()
    }){machine="cache", cur_state="cache_I_store", action="GetM_Ack_D"} : () -> ()

    "murphi.function"()({
        "murphi.return" () :  () -> ()
    }){machine="cache", cur_state="cache_I_store", action="GetM_Ack_D"} : () -> ()


    "murphi.function"()({
        "murphi.return" () :  () -> ()
    }){machine="cache", cur_state="cache_M", action="load"} : () -> ()

    "murphi.function"()({
        "murphi.return" () :  () -> ()
    }){machine="cache", cur_state="cache_M", action="store"} : () -> ()

    "murphi.function"()({
        "murphi.return" () :  () -> ()
    }){machine="cache", cur_state="cache_M", action="Fwd_GetM"} : () -> ()

    "murphi.function"()({
        "murphi.return" () :  () -> ()
    }){machine="cache", cur_state="cache_M", action="evict"} : () -> ()

    "murphi.function"()({
        "murphi.return" () :  () -> ()
    }){machine="cache", cur_state="cache_M_evict", action="Put_Ack"} : () -> ()



   
}