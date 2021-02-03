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
extern std::string CL_MUTEX_template;
extern std::string operation_release_mutex_template;

std::string mutex_helper_function(std::string funId, std::string mutVar,
                                  std::string mutVal);
std::string unordered_send_proc(std::string netId);
std::string ordered_send_proc(std::string netId);
std::string ordered_pop_proc(std::string netId);
std::string unordered_ruleset(std::string netId);
std::string ordered_ruleset(std::string netId);
std::string message_constructor(std::string msgId, std::string msgParams,
                                std::string fieldDefs);
std::string variable_decl(std::string varId, std::string typeId);
std::string cache_load_store_proc(std::string curState, std::string cpuEvent,
                                  std::string funcBody);

std::string machine_handler(std::string machineId, std::string body);
std::string switch_statement(std::string switchField, std::string cases);
std::string switch_statement_else_false(std::string switchField,
                                        std::string cases);
std::string case_statement(std::string caseId, std::string body);

std::string cache_ruleset(std::string rules);
std::string cache_rule(std::string curState, std::string cpuEvent,
                       bool concurrent);

// Start State Templates
std::string start_state_defintion(std::string body);
std::string mach_start_state(std::string machId, std::string operations);
std::string start_state_assignment(std::string machId, std::string field,
                                   std::string value);
std::string start_state_unordered_network(std::string netId);
std::string start_state_ordered_network(std::string netId);
std::string mutex_start_state(std::string mutId);

std::string write_serialization();

// operations
std::string message_constructor(std::string constrId, std::string parameters);
std::string send_message(std::string netId);
std::string assign_value(std::string machId, std::string id, std::string value);
std::string if_statement(std::string lhs, std::string condition,
                         std::string rhs, std::string nestedOps);