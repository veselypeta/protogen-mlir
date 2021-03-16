module{
    // func @handle_cache_I(){
    //     return
    // }

    // "statemachine"()({
    //     "init"() : () -> ()

    //     ^cache_I:
    //         "transitions"() [^cache_I_load, ^cache_I_store] {actions=["load", "store"]} : () -> ()
        
    //     ^cache_I_load:
    //         "transitions"() [ ^cache_M] {actions=["GetM_Ack_D"]} : () -> ()


    //     ^cache_I_store:
    //         "transitions"() [^cache_M] {actions=["GetM_Ack_D"]} : () -> ()


    //     ^cache_M:
    //         "transitions"() [^cache_M, ^cache_M, ^cache_M_evict] {actions=["load", "store", "evict"]} : () -> ()


    //     ^cache_M_evict:
    //         "transitions"() [^cache_I] {actions=["evict"]} : () -> ()

    // }) : () -> ()
    

    // Trivial case - consider only the case when it will result in a single transaction

    // transaction from I -> M (load) - NOT CONCURRENT -> PCC INTERFACE DIALECT
    "transaction"()({
        "transition"() ({
            // Send message
            "await"()({
                "when"()({
                    "set"(){attr="State", value="M"} : () -> ()
                }){id="GetM_Ack_D"}: () -> ()
            }): () -> ()
            
        }) {startState="I", action="load"}: () -> ()

    }){startState="I", action="load"}: () -> ()


    // Introduce basic transient state
    "transaction"()({

            "transition"() ({
            }) {startState="I", action="load", finalstate=["I_load"]}: () -> ()

            "transition"() ({
            }) {startState="I_load", action="GetM_Ack_D", finalstate=["M"]}: () -> ()

    }){startState="I", finalstate=["M"], action="load"}: () -> ()



        // "transaction"()({
        //     ^entry(%directory: i64, %msg: i64):
        //         "transition"(%directory, %msg) ({
        //             // send messages
        //             %dirOwner = "access"(%directory) {attr="Owner"}: (i64) -> (i64)
        //             %msgSrc = "access"(%msg) {attr="src"}: (i64) -> i64
        //             %eq = "equals"(%dirOwner, %msgSrc) : (i64, i64) -> i1
        //             "if"(%eq) ({
        //                 "set"(%directory) {attr="State", value="M"} : (i64) -> ()
        //             }) : (i1) -> ()
        //             "end"(): ()->()        
        //         }) {startState="M", finalstate=["M", "I"], action="Put_M"}: (i64, i64) -> ()
        // }){startState="M", finalstate="State", action="Put_M"} : () -> ()

}
