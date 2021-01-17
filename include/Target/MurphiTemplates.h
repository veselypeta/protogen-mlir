#pragma once
#include <fmt/core.h>
#include <iostream>

extern std::string MACH_cache;
extern std::string MACH_directory;
extern std::string OBJ_cache;
extern std::string OBJ_directory;
extern std::string OBJ_Ordered;
extern std::string OBJ_Orderedcnt;
extern std::string OBJ_Unordered;

std::string unordered_send_proc(std::string netId);
std::string ordered_send_proc(std::string netId);
std::string ordered_pop_proc(std::string netId);
std::string unordered_ruleset(std::string netId);
std::string ordered_ruleset(std::string netId);
std::string message_constructor(std::string msgId, std::string msgParams, std::string fieldDefs);
std::string variable_decl(std::string varId, std::string typeId);