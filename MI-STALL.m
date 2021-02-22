const

	nrCaches : 3;
	VAL_COUNT : 1;
	ADR_COUNT : 1;
	O_NET_MAX : 12;
	U_NET_MAX : 12;
type

Access : enum {
	load,
	store,
	none
};
MessageType : enum {
	Fwd_GetM,
	GetM,
	GetM_Ack_D,
	PutM,
	Put_Ack
};
cache_state : enum {
	cache_I,
	cache_I_load,
	cache_I_store,
	cache_M,
	cache_M_evict,
	cache_I_evict
};
directory_state : enum {
	directory_I,
	directory_M
};
Address: scalarset(ADR_COUNT);
ClValue: 0..VAL_COUNT;
OBJSET_cache: scalarset(nrCaches);
OBJSET_directory : enum {
	directory
};
Machines: union{OBJSET_cache, OBJSET_directory};
ENTRY_cache: record
	State : cache_state;
	cl : ClValue;
	Perm : Access;
end;
ENTRY_directory: record
	State : directory_state;
	cl : ClValue;
	owner : Machines;
	Perm : Access;
end;
Message: record
	adr : Address;
	mtype : MessageType;
	src : Machines;
	dst : Machines;
	cl : ClValue;
end;
MACH_cache: record 
  CL: array[Address] of ENTRY_cache;
end; 
MACH_directory: record 
  CL: array[Address] of ENTRY_directory; 
end; 
OBJ_cache : array[OBJSET_cache] of MACH_cache; 
OBJ_directory : array[OBJSET_directory] of MACH_directory; 
OBJ_Ordered: array[Machines] of array[0..O_NET_MAX-1] of Message; 
OBJ_Orderedcnt: array[Machines] of 0..O_NET_MAX; 
OBJ_Unordered: array[Machines] of multiset[U_NET_MAX] of Message; 
CL_MUTEX: array[Address] of boolean;
var

	i_cache : OBJ_cache;
	i_directory : OBJ_directory;
	fwd : OBJ_Ordered;
	cnt_fwd : OBJ_Orderedcnt;
	resp : OBJ_Unordered;
	req : OBJ_Unordered;
	cl_mut : CL_MUTEX;
function Request(adr: Address; mtype: MessageType; src: Machines; dst: Machines ) : Message;
var msg: Message;
begin
	msg.adr := adr;
	msg.mtype := mtype;
	msg.src := src;
	msg.dst := dst;
	msg.cl := undefined;

	return msg;
end;
function Ack(adr: Address; mtype: MessageType; src: Machines; dst: Machines ) : Message;
var msg: Message;
begin
	msg.adr := adr;
	msg.mtype := mtype;
	msg.src := src;
	msg.dst := dst;
	msg.cl := undefined;

	return msg;
end;
function Resp(adr: Address; mtype: MessageType; src: Machines; dst: Machines ; cl: ClValue) : Message;
var msg: Message;
begin
	msg.adr := adr;
	msg.mtype := mtype;
	msg.src := src;
	msg.dst := dst;
	msg.cl := cl;

	return msg;
end;
function RespAck(adr: Address; mtype: MessageType; src: Machines; dst: Machines ; cl: ClValue) : Message;
var msg: Message;
begin
	msg.adr := adr;
	msg.mtype := mtype;
	msg.src := src;
	msg.dst := dst;
	msg.cl := cl;

	return msg;
end;


procedure Send_fwd(msg:Message);
	Assert(cnt_fwd[msg.dst] < O_NET_MAX) "Too many messages";
	fwd[msg.dst][cnt_fwd[msg.dst]] := msg;
	cnt_fwd[msg.dst] := cnt_fwd[msg.dst] + 1;
end;
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
procedure Send_resp(msg:Message);
	Assert(MultiSetCount(i:resp[msg.dst], true) < U_NET_MAX) "Too many messages";
	MultiSetAdd(msg, resp[msg.dst]);
end;
procedure Send_req(msg:Message);
	Assert(MultiSetCount(i:req[msg.dst], true) < U_NET_MAX) "Too many messages";
	MultiSetAdd(msg, req[msg.dst]);
end;
function Func_cache(inmsg:Message; m:OBJSET_cache) : boolean;
var msg: Message;
begin
  alias adr: inmsg.adr do
  alias cache_entry: i_cache[m].CL[adr] do


switch cache_entry.State

    case cache_I:
		return false;

    case cache_I_load: 
        switch inmsg.mtype
            case GetM_Ack_D: 
                cache_entry.cl := inmsg.cl;
                cache_entry.State := cache_M;
            else return false;
        endswitch;


    case cache_I_store: 
        switch inmsg.mtype
            case GetM_Ack_D: 
                cache_entry.cl := inmsg.cl;
                cache_entry.State := cache_M;
            else return false;
        endswitch;


    case cache_M: 
        switch inmsg.mtype
            case Fwd_GetM: 
                msg := Resp(adr, GetM_Ack_D, m, inmsg.src, cache_entry.cl);
                Send_resp(msg); 
                cache_entry.State := cache_I;

            else return false;
        endswitch;


    case cache_M_evict: 
        switch inmsg.mtype
            case Put_Ack: 
                cache_entry.State := cache_I;
            
            -- handle case which could arrive in M state
            case Fwd_GetM:
                -- This happens when eviction loses the race
                msg := Resp(adr, GetM_Ack_D, m, inmsg.src, cache_entry.cl);
                Send_resp(msg); 
                cache_entry.State := cache_I_evict;

            else return false;
        endswitch;
	
	case cache_I_evict:
		switch inmsg.mtype
			case Put_Ack:
				cache_entry.State := cache_I;
			
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
    case directory_I: 
        switch inmsg.mtype
            case GetM: 
                msg := Resp(adr, GetM_Ack_D, m, inmsg.src, directory_entry.cl);
                Send_resp(msg); 
                directory_entry.owner := inmsg.src;
				directory_entry.State := directory_M;
            else return false;
        endswitch;


    case directory_M:

        switch inmsg.mtype
            case GetM: 
                msg := Request(adr, Fwd_GetM, inmsg.src, directory_entry.owner);
                Send_fwd(msg); 
                directory_entry.owner := inmsg.src;

            case PutM:
				msg := Ack(adr, Put_Ack, m, inmsg.src);
				Send_fwd(msg);
				if directory_entry.owner = inmsg.src then
					directory_entry.State := directory_I;
				endif;

            else return false;
        endswitch;
    

endswitch;

endalias;
endalias;
return true;
end;

procedure SEND_cache_I_load(adr:Address; m:OBJSET_cache);
var msg: Message;
begin
  alias cache_entry: i_cache[m].CL[adr] do

msg := Request(adr, GetM, m, directory);
Send_req(msg); 
cache_entry.State := cache_I_load;

endalias;
end;

procedure SEND_cache_I_store(adr:Address; m:OBJSET_cache);
var msg: Message;
begin
  alias cache_entry: i_cache[m].CL[adr] do

msg := Request(adr, GetM, m, directory);
Send_req(msg); 
cache_entry.State := cache_I_store;

endalias;
end;

procedure SEND_cache_M_load(adr:Address; m:OBJSET_cache);
var msg: Message;
begin
  alias cache_entry: i_cache[m].CL[adr] do

cache_entry.State := cache_M;

endalias;
end;

procedure SEND_cache_M_store(adr:Address; m:OBJSET_cache);
var msg: Message;
begin
  alias cache_entry: i_cache[m].CL[adr] do

cache_entry.State := cache_M;

endalias;
end;

procedure SEND_cache_M_evict(adr:Address; m:OBJSET_cache);
var msg: Message;
begin
  alias cache_entry: i_cache[m].CL[adr] do

msg := Resp(adr, PutM, m, directory, cache_entry.cl);
Send_req(msg); 
cache_entry.State := cache_M_evict;

endalias;
end;

ruleset m:OBJSET_cache do
    ruleset adr:Address do
        alias cle:i_cache[m].CL[adr] do


rule "cache_I_load"
    cle.State = cache_I 
        ==>
    SEND_cache_I_load(adr, m);
endrule;


rule "cache_I_store"
    cle.State = cache_I 
        ==>
    SEND_cache_I_store(adr, m);
endrule;


rule "cache_M_load"
    cle.State = cache_M 
        ==>
    SEND_cache_M_load(adr, m);
endrule;


rule "cache_M_store"
    cle.State = cache_M 
        ==>
    SEND_cache_M_store(adr, m);
endrule;


rule "cache_M_evict"
    cle.State = cache_M 
        ==>
    SEND_cache_M_evict(adr, m);
endrule;


        endalias;
    endruleset;
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

-- Setup Start States
startstate

    -- setup the cache
    for i:OBJSET_cache do
        for a:Address do

		i_cache[i].CL[a].State := cache_I; 
		i_cache[i].CL[a].cl := 0; 
		i_cache[i].CL[a].Perm := none; 

        endfor;
    endfor;
    -- setup the directory
    for i:OBJSET_directory do
        for a:Address do

		i_directory[i].CL[a].State := directory_I; 
		i_directory[i].CL[a].cl := 0; 
		i_directory[i].CL[a].Perm := none; 

        endfor;
    endfor;
undefine fwd;
for n:Machines do
        cnt_fwd[n] := 0;
    endfor;
  undefine resp;
  undefine req;
for a:Address do
    cl_mut[a] := false;
endfor;

endstartstate;
