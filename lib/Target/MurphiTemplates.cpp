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