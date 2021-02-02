#include "Target/MurphiTemplates.h"
#include <string>

std::string MACH_cache = "\
MACH_cache: record \n\
  CL: array[Address] of ENTRY_cache;\n\
end; \n\
";

std::string MACH_directory = "\
MACH_directory: record \n\
  CL: array[Address] of ENTRY_directory; \n\
end; \n\
";

std::string OBJ_cache = "\
OBJ_cache : array[OBJSET_cache] of MACH_cache; \n\
";

std::string OBJ_directory = "\
OBJ_directory : array[OBJSET_directory] of MACH_directory; \n\
";

std::string OBJ_Ordered = "\
OBJ_Ordered: array[Machines] of array[0..O_NET_MAX-1] of Message; \n\
";

std::string OBJ_Orderedcnt = "\
OBJ_Orderedcnt: array[Machines] of 0..O_NET_MAX; \n\
";

std::string OBJ_Unordered = "\
OBJ_Unordered: array[Machines] of multiset[U_NET_MAX] of Message; \n\
";

std::string msg_constructor_template = "\
function {}(adr: Address; mtype: MessageType; src: Machines; dst: Machines {}) : Message;\n\
var msg: Message;\n\
begin\n\
\tmsg.adr := adr;\n\
\tmsg.mtype := mtype;\n\
\tmsg.src := src;\n\
\tmsg.dst := dst;\n\
{}\n\
\treturn msg;\n\
end;\n\
";

std::string unordered_send_proc_template = "\
procedure Send_{0}(msg:Message);\n\
\tAssert(MultiSetCount(i:{0}[msg.dst], true) < U_NET_MAX) \"Too many messages\";\n\
\tMultiSetAdd(msg, {0}[msg.dst]);\n\
end;\n\
";

std::string ordered_send_proc_template = "\
procedure Send_{0}(msg:Message);\n\
\tAssert(cnt_{0}[msg.dst] < O_NET_MAX) \"Too many messages\";\n\
\tfwd[msg.dst][cnt_{0}[msg.dst]] := msg;\n\
\tcnt_{0}[msg.dst] := cnt_{0}[msg.dst] + 1;\n\
end;\n\
";

std::string ordered_pop_proc_template = "\
procedure Pop_{0}(n:Machines);\n\
begin\n\
\tAssert(cnt_{0}[n] > 0) \"Trying to advance empty Q\";\n\
\tfor i := 0 to cnt_{0}[n]-1 do\n\
\t\tif i < cnt_{0}[n]-1 then\n\
\t\t\t{0}[n][i] := {0}[n][i+1];\n\
\t\telse\n\
\t\t\tundefine {0}[n][i];\n\
\t\tendif;\n\
\tendfor;\n\
\tcnt_{0}[n] := cnt_{0}[n] - 1;\n\
end;\n\
";

std::string unordered_ruleset_template = "\
ruleset n:Machines do\n\
\tchoose midx:{0}[n] do\n\
\t\talias mach:{0}[n] do\n\
\t\talias msg:mach[midx] do\n\
\t\t\trule \"Receive {0}\"\n\
\t\t\t\t!isundefined(msg.mtype)\n\
\t\t\t\t==>\n\
\t\t\tif IsMember(n, OBJSET_directory) then\n\
\t\t\t\tif Func_directory(msg, n) then\n\
\t\t\t\t\tMultiSetRemove(midx, mach);\n\
\t\t\t\tendif;\n\
\t\t\telse\n\
\t\t\t\tif Func_cache(msg, n) then\n\
\t\t\t\t\tMultiSetRemove(midx, mach);\n\
\t\t\t\tendif;\n\
\t\t\tendif;\n\
\t\t\tendrule;\n\
\t\tendalias;\n\
\t\tendalias;\n\
\tendchoose;\n\
endruleset;\n\
";

std::string ordered_ruleset_template = "\
ruleset n:Machines do\n\
\talias msg:{0}[n][0] do\n\
\trule \"Receive {0}\"\n\
\t\tcnt_{0}[n] > 0\n\
\t\t==>\n\
\t\tif IsMember(n, OBJSET_directory) then\n\
\t\t\tif Func_directory(msg, n) then\n\
\t\t\t\tPop_{0}(n);\n\
\t\t\tendif;\n\
\t\telse\n\
\t\t\tif Func_cache(msg, n) then\n\
\t\t\t\tPop_{0}(n);\n\
\t\t\tendif;\n\
\t\tendif;\n\
\tendrule;\n\
\tendalias;\n\
endruleset;\n\
";

std::string variable_template = "\
\t{} : {};\n\
";

std::string cache_load_store_proc_template = "\
procedure SEND_{0}_{1}(adr:Address; m:OBJSET_cache);\n\
var msg: Message;\n\
begin\n\
  alias cle: i_cache[m].CL[adr] do\n\
{2} \n\
endalias;\n\
end;\n\
\n\
";

std::string machine_handler_func_template = "\
function Func_{0}(inmsg:Message; m:OBJSET_{0}) : boolean;\n\
var msg: Message;\n\
begin\n\
  alias adr: inmsg.adr do\n\
  alias {0}_entry: i_{0}[m].CL[adr] do\n\
{1}\n\
endalias;\n\
endalias;\n\
return true;\n\
end;\n\
\n\
";

std::string switch_statement_template = "\
switch {0}:\n\
{1}\n\
endswitch;\n\
";

std::string switch_statement_else_false_template = "\
switch {0}:\n\
{1}\n\
  else return false;\n\
endswitch;\n\
";

std::string case_statement_template = "\
case {0}: \n\
{1}\n\
\n\
";

std::string cache_ruleset_template = "\
ruleset m:OBJSET_cache do\n\
    ruleset adr:Address do\n\
        alias cle:i_cache[m].CL[adr] do\n\
\n\
{0}\n\
        endalias;\n\
    endruleset;\n\
endruleset;\n\
\n\
";

std::string cache_rule_template = "\
\n\
rule \"{0}_{1}\"\n\
    cle.State = {0} \n\
    & \n\
    cl_mut[adr] = false\n\
        ==>\n\
    SEND_{0}_{1}(adr, m);\n\
endrule;\n\
\n\
";

std::string write_serialization_template = "\
invariant \"Write Serialization\"\n\
    forall c1:OBJSET_cache do\n\
        forall c2:OBJSET_cache do\n\
            forall a:Address do\n\
                ( c1 != c2\n\
                & i_cache[c1].CL[a].Perm = store )\n\
                ->\n\
                ( i_cache[c2].CL[a].Perm != store )\n\
            endforall\n\
        endforall\n\
    endforall;\n\
\n\
";

std::string start_state_template = "\
\n\
-- Setup Start States\n\
startstate\n\
\n\
{0}\n\
\n\
endstartstate;\n\
";

std::string mach_start_state_def_template = "\
    -- setup the {0}\n\
    for i:OBJSET_{0} do\n\
        for a:Address do\n\
\n\
{1}\n\
\n\
        endfor;\n\
    endfor;\n\
";

std::string start_state_assign_template = "\
\t\ti_{0}[i].CL[a].{1} := {2}; \n\
";

std::string unord_net_start_state_template = "\
  undefine {0};\n\
";

std::string ord_net_start_state_temlate = "\
undefine {0};\n\
for n:Machines do\n\
        cnt_{0}[n] := 0;\n\
    endfor;\n\
";

std::string msg_constr_template = "\
msg := {0}(adr, {1});\n\
";

std::string call_send_template = "\
Send_{0}(msg); \n\
";

std::string aux_state_assignment = "\
{0}_entry.{1} := {2};\n\
";

std::string if_statement_templates = "\
if {0} {1} {2} then \n\
\n\
{3}\n\
\n\
endif\n\
";

std::string unordered_send_proc(std::string netId) {
  return fmt::format(unordered_send_proc_template, netId);
}

std::string ordered_send_proc(std::string netId) {
  return fmt::format(ordered_send_proc_template, netId);
}

std::string ordered_pop_proc(std::string netId) {
  return fmt::format(ordered_pop_proc_template, netId);
}

std::string unordered_ruleset(std::string netId) {
  return fmt::format(unordered_ruleset_template, netId);
}

std::string ordered_ruleset(std::string netId) {
  return fmt::format(ordered_ruleset_template, netId);
}

std::string message_constructor(std::string msgId, std::string msgParams,
                                std::string fieldDefs) {
  return fmt::format(msg_constructor_template, msgId, msgParams, fieldDefs);
}

std::string variable_decl(std::string varId, std::string typeId) {
  return fmt::format(variable_template, varId, typeId);
}

std::string cache_load_store_proc(std::string curState, std::string cpuEvent,
                                  std::string funcBody) {
  return fmt::format(cache_load_store_proc_template, curState, cpuEvent,
                     funcBody);
}

std::string machine_handler(std::string machineId, std::string body){
  return fmt::format(machine_handler_func_template, machineId, body);
}

std::string switch_statement(std::string switchField, std::string cases){
  return fmt::format(switch_statement_template, switchField, cases);
}

std::string switch_statement_else_false(std::string switchField, std::string cases){
  return fmt::format(switch_statement_else_false_template, switchField, cases);
}

std::string case_statement(std::string caseId, std::string body){
  return fmt::format(case_statement_template, caseId, body);
}

std::string cache_ruleset(std::string rules){
  return fmt::format(cache_ruleset_template, rules);
}

// Generate a rule within a cache ruleset
std::string cache_rule(std::string curState, std::string cpuEvent){
  return fmt::format(cache_rule_template, curState, cpuEvent);
}

// Create a Startstate definition, and insert the body in appropriate place
std::string start_state_defintion(std::string body){
  return fmt::format(start_state_template, body);
}

// Generate the machine startstate definitions
std::string mach_start_state(std::string machId, std::string operations){
  return fmt::format(mach_start_state_def_template, machId, operations);
}

// Generate Assignment Operation
std::string start_state_assignment(std::string machId, std::string field, std::string value){
  return fmt::format(start_state_assign_template, machId, field, value);
}

// Generate the StartState for an unordered network
std::string start_state_unordered_network(std::string netId){
  return fmt::format(unord_net_start_state_template, netId);
}

// Generate the StartState for an ordered network
std::string start_state_ordered_network(std::string netId){
  return fmt::format(ord_net_start_state_temlate, netId);
}

// Generate the WriteSerialization result
std::string write_serialization(){
  return write_serialization_template;
}


/// =================== ///
// Operations Templates ///
/// =================== ///

std::string message_constructor(std::string constrId, std::string parameters){
  return fmt::format(msg_constr_template, constrId, parameters);
}

std::string send_message(std::string netId){
  return fmt::format(call_send_template, netId);
}

std::string assign_value(std::string machId, std::string id, std::string value){
  return fmt::format(aux_state_assignment, machId, id, value);
}

std::string if_statement(std::string lhs, std::string condition, std::string rhs, std::string nestedOps){
  return fmt::format(if_statement_templates, lhs, condition, rhs, nestedOps);
}
