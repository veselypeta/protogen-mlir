module {

    func @directory(%message: pcc<"Message">, %state: pcc<"Directory">) {
        ^get_state
            cond_br %state, ^directory_i
            cond_br %state, ^directory_m

        ^directory_i
            %m = "pcc.message"(GetM_Ack_D: pcc<"FWD">, ID: pcc<"ID">, GetM.src , cl)
            "pcc.send"(%m): (Message) -> ()
            // transition // needs to wait for message

        ^directory_m
            // do some other stuff
    }


    // optionally - event driven
    // this representation represents a cache

    func @onCacheReceiveLoad(){}

    func @onCacheReceiveStore(){}

    func @onCacheReceiveEvict(){}

    func @onCacheReceiveGetM(){}

    func @onCacheReceiveGetM_Ack_D(){}

    func @onCacheRecieveFwd_GetM(){}
    ...

    // fine as a representation, but does not quantify a flow of execution
    // i.e. what is creating the events.


}