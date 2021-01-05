-- const declarations

const 
    NrCaches : 3;

    -- value the cl can hold
    VAL_COUNT: 1;

    -- number of addresses - i.e. cache blocks in the system
    ADR_COUNT: 1;

    -- max number of messages in an (un)ordered network 
    O_NET_MAX: 12;
    U_NET_MAX: 12;


-- Type declarations
type 

Access: enum {
    none,
    load,
    store
};

MessageType : enum {
    GetM,
    Fwd_GetM,
    GetM_Ack_D,
    PutM,
    Put_Ack
};

cache_state: enum {
    cache_M,
    cache_I_M_D,
    cache_I,
    cache_M_I_Ack
};

directory_state: enum {
    directory_I,
    directory_M
};

Address: scalarset(ADR_COUNT);
ClValue: 0..VAL_COUNT;


-- create all the caches based on the number
OBJSET_cache: scalarset(NrCaches);
-- create the directory
OBJSET_directory: enum{directory};
-- all machines in the system
Machines: union{OBJSET_cache, OBJSET_directory};

-- type to represent a message
Message: record
  adr: Address;
  mtype: MessageType;
  src: Machines;
  dst: Machines;
  cl: ClValue;
end;


-- a record for what a cache knows about a cl
ENTRY_cache: record
  State: cache_state;
  Perm: Access;
  cl: ClValue;
end;


-- a record for what the directory knows about a cl
ENTRY_directory: record
  State: directory_state;
  Perm: Access;
  cl: ClValue;
  owner: Machines;
end;

-- create a cache entry for every block of the address space
MACH_cache: record
  CL: array[Address] of ENTRY_cache;
end;
-- create directory entry for every block in the address space
MACH_directory: record
  CL: array[Address] of ENTRY_directory;
end;

-- all cache and directory objects
OBJ_cache : array[OBJSET_cache] of MACH_cache;
OBJ_directory : array[OBJSET_directory] of MACH_directory;

-- an array for every machine with an array of messages (message queue)
OBJ_Ordered: array[Machines] of array[0..O_NET_MAX-1] of Message;
OBJ_Orderedcnt: array[Machines] of 0..O_NET_MAX;
OBJ_Unordered: array[Machines] of multiset[U_NET_MAX] of Message;

-- for each address create a mutex
CL_MUTEX: array[Address] of boolean;


var 
    i_cache: OBJ_cache;
    i_directory: OBJ_directory;

    -- only fwd network is ordered and we have to maintain the number of elements
    fwd: OBJ_Ordered;
    cnt_fwd: OBJ_Orderedcnt;
    resp: OBJ_Unordered;
    req: OBJ_Unordered;

    -- create the mutex
    cl_mut: CL_MUTEX;

----------------------------------/
----/ Message Object Factories----/
----------------------------------/

-- Create Request
function Request(adr: Address; mtype: MessageType; src: Machines; dst: Machines) : Message;
var msg: Message;
begin
  msg.adr := adr;
  msg.mtype := mtype;
  msg.src := src;
  msg.dst := dst;
  msg.cl := undefined;
  return msg;
end;

-- Create an Acknowledgement
function Ack(adr: Address; mtype: MessageType; src: Machines; dst: Machines) : Message;
var msg: Message;
begin
  msg.adr := adr;
  msg.mtype := mtype;
  msg.src := src;
  msg.dst := dst;
  msg.cl := undefined;
  return msg;
end;

-- Create a Response
function Resp(adr: Address; mtype: MessageType; src: Machines; dst: Machines; cl: ClValue) : Message;
var msg: Message;
begin
  msg.adr := adr;
  msg.mtype := mtype;
  msg.src := src;
  msg.dst := dst;
  msg.cl := cl;
  return msg;
end;

-- Create a RespAck
function RespAck(adr: Address; mtype: MessageType; src: Machines; dst: Machines; cl: ClValue) : Message;
var msg: Message;
begin
  msg.adr := adr;
  msg.mtype := mtype;
  msg.src := src;
  msg.dst := dst;
  msg.cl := cl;
  return msg;
end;



----------------------
-- Helper Functions --
----------------------
procedure Aquire_Mutex(adr: Address);
    cl_mut[adr] := true;
end;

procedure Release_Mutex(adr: Address);
    cl_mut[adr] := false;
end;

procedure Send_req(msg:Message);
  Assert(MultiSetCount(i:req[msg.dst], true) < U_NET_MAX) "Too many messages";
  MultiSetAdd(msg, req[msg.dst]);
end;

procedure Send_resp(msg:Message);
  Assert (MultiSetCount(i:resp[msg.dst], true) < U_NET_MAX) "Too many messages";
  MultiSetAdd(msg, resp[msg.dst]);
end;

procedure Send_fwd(msg:Message);
  Assert(cnt_fwd[msg.dst] < O_NET_MAX) "Too many messages";
  fwd[msg.dst][cnt_fwd[msg.dst]] := msg;
  cnt_fwd[msg.dst] := cnt_fwd[msg.dst] + 1;
end;

-- remove from from of queue
procedure Pop_fwd(n:Machines);
begin
  Assert(cnt_fwd[n] > 0) "Trying to advance empty Q";
  for i := 0 to cnt_fwd[n]-1 do
    if i < cnt_fwd[n]-1 then
      fwd[n][i] := fwd[n][i+1];
    else
      undefine fwd[n][i];
    endif;
  endfor;
  cnt_fwd[n] := cnt_fwd[n] - 1;
end;


-- define the behaviour of a cache
function Func_cache(inmsg:Message; m:OBJSET_cache) : boolean;
var msg: Message;
begin
  alias adr: inmsg.adr do
  alias cache_entry: i_cache[m].CL[adr] do
switch cache_entry.State

    -- define rules what cache does at each state

    -- State I - do nothing - return false
    case cache_I:
        return false;

    -- M state
    case cache_M:
        switch inmsg.mtype
            -- Invalidate Self, send CL to requestor
            case Fwd_GetM:
                msg := Resp(adr,GetM_Ack_D,m,inmsg.src,cache_entry.cl);
                Send_resp(msg);
                cache_entry.State := cache_I;
                cache_entry.Perm := none;
            else return false;
        endswitch;


    -- I_M_D state -- 
    case cache_I_M_D:
        switch inmsg.mtype
            case GetM_Ack_D:
                cache_entry.cl := inmsg.cl;
                cache_entry.State := cache_M;
                cache_entry.Perm := store;
                Release_Mutex(adr);
            
            else return false;

        endswitch;

    -- M_I_Ack -- transition state for PutM 
    case cache_M_I_Ack:
        switch inmsg.mtype
            case Put_Ack:
                cache_entry.State := cache_I;
                cache_entry.Perm := none;
                Release_Mutex(adr);
            else return false;
        endswitch;
    

endswitch;
endalias;
endalias;
return true;
end;



function Func_directory(inmsg:Message; m:OBJSET_directory) : boolean;
var msg: Message;
begin
  alias adr: inmsg.adr do
  alias directory_entry: i_directory[m].CL[adr] do

switch directory_entry.State
    case directory_M:
        switch inmsg.mtype
            case GetM:
                msg := Request(adr,Fwd_GetM,inmsg.src,directory_entry.owner);
                Send_fwd(msg);
                directory_entry.owner := inmsg.src;
                directory_entry.State := directory_M;
                directory_entry.Perm := none;
            case PutM:
                msg := Ack(adr,Put_Ack,m,inmsg.src);
                Send_fwd(msg);
                directory_entry.cl := inmsg.cl;
                directory_entry.State := directory_I;
                directory_entry.Perm := none;
            else return false;
        endswitch;

    case directory_I:
        switch inmsg.mtype
            case GetM:
                msg := Resp(adr,GetM_Ack_D,m,inmsg.src,directory_entry.cl);
                Send_resp(msg);
                directory_entry.owner := inmsg.src;
                directory_entry.State := directory_M;
                directory_entry.Perm := none;
            
            else return false;
        endswitch;
endswitch;

endalias;
endalias;
return true;
end;



-- Procedures --

procedure SEND_cache_I_load(adr:Address; m:OBJSET_cache);
var msg: Message;
begin
  alias cle: i_cache[m].CL[adr] do
    msg := Request(adr,GetM,m,directory);
    Send_req(msg);
    cle.State := cache_I_M_D;
    cle.Perm := none;
endalias;
end;

procedure SEND_cache_I_store(adr:Address; m:OBJSET_cache);
var msg: Message;
begin
  alias cle: i_cache[m].CL[adr] do
    msg := Request(adr,GetM,m,directory);
    Send_req(msg);
    cle.State := cache_I_M_D;
    cle.Perm := none;
endalias;
end;

procedure SEND_cache_M_load(adr:Address; m:OBJSET_cache);
var msg: Message;
begin
  alias cle: i_cache[m].CL[adr] do
    cle.State := cache_M;
    cle.Perm := store;
endalias;
end;

procedure SEND_cache_M_store(adr:Address; m:OBJSET_cache);
var msg: Message;
begin
    alias cle: i_cache[m].CL[adr] do
        cle.State := cache_M;
        cle.Perm := store;
endalias;
end;

procedure SEND_cache_M_evict(adr:Address; m:OBJSET_cache);
var msg: Message;
begin
    alias cle: i_cache[m].CL[adr] do
        msg := Request(adr, PutM, m, directory);
        Send_req(msg);
        cle.State := cache_M_I_Ack;
        cle.Perm := none;
endalias;
end;

--------------------------/
----/ Create rulesets ----/
--------------------------/


-- for each cache and for each address (cache blocks) -- only issue load/store/evict if mutex is false
ruleset m:OBJSET_cache do
    ruleset adr:Address do
        alias cle:i_cache[m].CL[adr] do

            rule "cache_I_load"
                cle.State = cache_I 
                & 
                cl_mut[adr] = false
                    ==>
                Aquire_Mutex(adr);
                SEND_cache_I_load(adr, m);
            endrule;

            rule "cache_I_store"
                cle.State = cache_I
                & 
                cl_mut[adr] = false
                    ==>
                Aquire_Mutex(adr);
                SEND_cache_I_store(adr, m);
            endrule;

            rule "cache_M_load"
                cle.State = cache_M
                & 
                cl_mut[adr] = false
                    ==>
                SEND_cache_M_load(adr, m);
            endrule;

            rule "cache_M_store"
                cle.State = cache_M
                & 
                cl_mut[adr] = false
                    ==>
                SEND_cache_M_store(adr, m);
            endrule;

            rule "cache_M_evict"
                cle.State = cache_M
                & 
                cl_mut[adr] = false
                    ==>
                Aquire_Mutex(adr);
                SEND_cache_M_evict(adr, m);
            endrule;

        endalias;
    endruleset;
endruleset;

-- define rules for messages on the response network
ruleset n:Machines do
    choose midx:resp[n] do
        alias mach:resp[n] do
        alias msg:mach[midx] do
            rule "Receive resp"
                !isundefined(msg.mtype)
                ==>
            if IsMember(n, OBJSET_directory) then
                if Func_directory(msg, n) then
                    MultiSetRemove(midx, mach);
                endif;
            else
                if Func_cache(msg, n) then
                    MultiSetRemove(midx, mach);
                endif;
            endif;
            endrule;
        endalias;
        endalias;
    endchoose;
endruleset;

-- define rules for messages on the request network
ruleset n:Machines do
    choose midx:req[n] do
        alias mach:req[n] do
        alias msg:mach[midx] do
            rule "Receive req"
                !isundefined(msg.mtype)
            ==>
            if IsMember(n, OBJSET_directory) then
                if Func_directory(msg, n) then
                    MultiSetRemove(midx, mach);
                endif;
            else
                if Func_cache(msg, n) then
                    MultiSetRemove(midx, mach);
                endif;
            endif;
          endrule;
        endalias;
        endalias;
    endchoose;

endruleset;


ruleset n:Machines do
    alias msg:fwd[n][0] do
        rule "Receive fwd"
            cnt_fwd[n] > 0
        ==>
        if IsMember(n, OBJSET_directory) then
            if Func_directory(msg, n) then
                Pop_fwd(n);
            endif;
        else
            if Func_cache(msg, n) then
                Pop_fwd(n);
            endif;
        endif;
      endrule;
    endalias;
endruleset;

-- Setup Start States
startstate
    -- setup the directory
    for i:OBJSET_directory do
        for a:Address do
            i_directory[i].CL[a].State := directory_I;
            i_directory[i].CL[a].cl := 0;
            i_directory[i].CL[a].Perm := none;
        endfor;
    endfor;
    
    -- setup the caches
    for i:OBJSET_cache do
        for a:Address do
            i_cache[i].CL[a].State := cache_I;
            i_cache[i].CL[a].cl := 0;
            i_cache[i].CL[a].Perm := none;
        endfor;
    endfor;

    -- setup the mutex as available
    for a:Address do
        cl_mut[a] := false;
    endfor;

    undefine resp;
    undefine req;
    undefine fwd;

    -- fwd count is zero initially
    for n:Machines do
        cnt_fwd[n] := 0;
    endfor;
endstartstate;


-- SWMR -- No two caches both have store permissions
invariant "Write Serialization"
    forall c1:OBJSET_cache do
        forall c2:OBJSET_cache do
            forall a:Address do
                ( c1 != c2
                & i_cache[c1].CL[a].Perm = store )
                ->
                ( i_cache[c2].CL[a].Perm != store )
            endforall
        endforall
    endforall;
