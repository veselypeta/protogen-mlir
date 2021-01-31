module {
    // Need to know defined constants in MLIR
    %nrCaches = "murphi.constant"(){id="nrCaches", value=3} : () -> i64

    // Specify size of Cache -- TODO
    "murphi.cache_definition" () {fields=["State", "cl"], types=["I", "Data"]} : () -> ()
    "murphi.directory_definition"() {fields=["State", "cl", "owner"], types=["I", "Data", "ID"]} : () -> ()

    "murphi.message_definition"() {id="Request", fields=[], types=[]} : () -> ()
    "murphi.message_definition"() {id="Ack", fields=[], types=[]} : () -> ()
    "murphi.message_definition"() {id="Response", fields=["cl"], types=["Data"]} : () -> ()
    "murphi.message_definition"() {id="RespAck", fields=["cl"], types=["Data"]} : () -> ()

    "murphi.network_decl"() {ordering ="Ordered", id="fwd"} : () -> ()
    "murphi.network_decl"() {ordering="Unordered", id="resp"} : () -> ()
    "murphi.network_decl"() {ordering="Unordered", id="req"} : () -> ()

    // CACHE //
    "murphi.function"()({
        // msg = Request(GetM, ID, directory.ID);
        // %msg = "murphi.msg_constr"(){params=["GetM", "ID", "directory.ID"]} : () -> i64
        // req.send(msg);
        // "murphi.send"(%msg) : (i64) -> ()
        "murphi.return" () :  () -> ()
    }){machine="cache", cur_state="cache_I", action="load"} : () -> ()
    // end_state & permission as extra attributes

    "murphi.function"()({
        "murphi.return" () :  () -> ()
    }){machine="cache", cur_state="cache_I_load", action="GetM_Ack_D"} : () -> ()

    "murphi.function"()({
        "murphi.return" () :  () -> ()
    }){machine="cache", cur_state="cache_I", action="store"} : () -> ()

    "murphi.function"()({
        // "murphi.set" (){id="cl", value="GetM_Ack_D.cl"} : () -> ()
        // "murphi.set" (){id="State", value="cache_I"} : () -> ()
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


    // DIRECTORY //
    "murphi.function"()({
        "murphi.return" () :  () -> ()
    }){machine="directory", cur_state="directory_I", action="GetM"} : () -> ()

    "murphi.function"()({
        "murphi.return" () :  () -> ()
    }){machine="directory", cur_state="directory_M", action="GetM"} : () -> ()

    "murphi.function"()({
        "murphi.return" () :  () -> ()
    }){machine="directory", cur_state="directory_M", action="PutM"} : () -> ()


}