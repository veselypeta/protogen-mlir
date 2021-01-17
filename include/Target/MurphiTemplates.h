#pragma once
#include <fmt/core.h>
#include <iostream>

extern std::string boiler_plate_definitions;

// extern std::string unordered_send_proc_template;

// extern std::string ordered_send_proc_template;

std::string unordered_send_proc(std::string netId);
std::string ordered_send_proc(std::string netId);
std::string ordered_pop_proc(std::string netId);
std::string unordered_ruleset(std::string netId);
std::string ordered_ruleset(std::string netId);
std::string message_constructor(std::string msgId, std::string msgParams, std::string fieldDefs);