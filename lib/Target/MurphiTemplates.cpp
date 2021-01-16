#include "Target/MurphiTemplates.h"
#include <string>


std::string boiler_plate_definitions= " \
-- create a cache entry for every block of the address space \n\
MACH_cache: record \n\
  CL: array[Address] of ENTRY_cache;\n\
end; \n\
-- create directory entry for every block in the address space \n\
MACH_directory: record \n\
  CL: array[Address] of ENTRY_directory; \n\
end; \n\
\n\
-- all cache and directory objects \n\
OBJ_cache : array[OBJSET_cache] of MACH_cache; \n\
OBJ_directory : array[OBJSET_directory] of MACH_directory; \n\
\n\
-- an array for every machine with an array of messages (message queue) \n\
OBJ_Ordered: array[Machines] of array[0..O_NET_MAX-1] of Message; \n\
OBJ_Orderedcnt: array[Machines] of 0..O_NET_MAX; \n\
OBJ_Unordered: array[Machines] of multiset[U_NET_MAX] of Message; \n\
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

std::string unordered_send_proc(std::string netId) {
  return fmt::format(unordered_send_proc_template, netId);
}

std::string ordered_send_proc(std::string netId) {
  return fmt::format(ordered_send_proc_template, netId);
}