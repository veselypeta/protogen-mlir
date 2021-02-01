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
        %msg = "murphi.msg_constr"(){msgType="Request", parameters=["GetM", "ID", "directory.ID"]} : () -> i64
        // req.send(msg);
        "murphi.send"(%msg) {netId="req"} : (i64) -> ()
        "murphi.return" () :  () -> ()
    }){machine="cache", cur_state="cache_I", action="load"} : () -> ()
    // end_state & permission as extra attributes

    "murphi.function"()({
        // cl=GetM_Ack_D.cl;
        "murphi.set"(){id="cl", value="GetM_Ack_D.cl"} : () -> ()
        // State = M;
        "murphi.set"(){id="State", value="cache_M"} : () -> ()
        "murphi.return" () :  () -> ()
    }){machine="cache", cur_state="cache_I_load", action="GetM_Ack_D"} : () -> ()

    "murphi.function"()({
        // msg = Request(GetM, ID, directory.ID);
        %msg = "murphi.msg_constr"(){msgType="Request", parameters=["GetM", "ID", "directory.ID"]} : () -> i64
        // req.send(msg);
        "murphi.send"(%msg) {netId="req"} : (i64) -> ()
        "murphi.return" () :  () -> ()
    }){machine="cache", cur_state="cache_I", action="store"} : () -> ()

    "murphi.function"()({
        // cl=GetM_Ack_D.cl;
        "murphi.set" (){id="cl", value="GetM_Ack_D.cl"} : () -> ()
        // State = M;
        "murphi.set" (){id="State", value="cache_I"} : () -> ()
        "murphi.return" () :  () -> ()
    }){machine="cache", cur_state="cache_I_store", action="GetM_Ack_D"} : () -> ()

    // Do nothing
    "murphi.function"()({
        "murphi.return" () :  () -> ()
    }){machine="cache", cur_state="cache_M", action="load"} : () -> ()

    // Do nothing
    "murphi.function"()({
        "murphi.return" () :  () -> ()
    }){machine="cache", cur_state="cache_M", action="store"} : () -> ()


    "murphi.function"()({
        %msg = "murphi.msg_constr"(){msgType="Resp", parameters=["GetM_Ack_D", "ID", "Fwd_GetM.src", "cl"]} : () -> (i64)
        "murphi.send"(%msg) {netId="resp"} : (i64) -> ()
        "murphi.set"(){id="State", value="cache_I"} : () -> ()
        "murphi.return" () :  () -> ()
    }){machine="cache", cur_state="cache_M", action="Fwd_GetM"} : () -> ()

    "murphi.function"()({
        %msg = "murphi.msg_constr"(){msgType="Resp", parameters=["PutM", "ID", "directory.ID", "cl"]} : () -> i64
        "murphi.send"(%msg) {netId="req"} : (i64) -> ()
        "murphi.return" () :  () -> ()
    }){machine="cache", cur_state="cache_M", action="evict"} : () -> ()

    "murphi.function"()({
        "murphi.set"(){id="State", value="cache_I"} : () -> ()
        "murphi.return" () :  () -> ()
    }){machine="cache", cur_state="cache_M_evict", action="Put_Ack"} : () -> ()


    // DIRECTORY //
    "murphi.function"()({
        %msg = "murphi.msg_constr"(){msgType="Resp", parameters=["GetM_Ack_D", "ID", "GetM.src", "cl"]} : () -> i64
        "murphi.send"(%msg) {netId="resp"} : (i64) -> ()
        "murphi.set"(){id="owner", value="GetM.src"} : () -> ()
        "murphi.return" () :  () -> ()
    }){machine="directory", cur_state="directory_I", action="GetM"} : () -> ()

    "murphi.function"()({
        %msg = "murphi.msg_constr"(){msgType="Request", parameters=["Fwd_GetM", "GetM.src", "owner"]} : () -> i64
        "murphi.send"(%msg) {netId="fwd"} : (i64) -> ()
        "murphi.set"(){id="owner", value="GetM.src"} : () -> ()
        "murphi.return" () :  () -> ()
    }){machine="directory", cur_state="directory_M", action="GetM"} : () -> ()

    "murphi.function"()({
        %msg = "murphi.msg_constr"(){msgType="Ack", parameters=["Put_Ack", "ID", "PutM.src"]} : () -> i64
        "murphi.send"(%msg) {netId="fwd"} : (i64) -> ()
        "murphi.if"()({
            "murphi.set"(){id="State", value="directory_I"} : () -> ()
            "murphi.end_if"() : () -> ()
        }){lhs="owner", comparison="==", rhs="PutM.src"} : () -> ()
        "murphi.return" () :  () -> ()
    }){machine="directory", cur_state="directory_M", action="PutM"} : () -> ()

}