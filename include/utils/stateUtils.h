#pragma once
#include "mlir/IR/Module.h"
#include <string>
#include <vector>

namespace utils {

bool isCpuEvent(std::string event);
std::vector<std::string> getAllMsgTypes(mlir::ModuleOp &mod);
std::vector<std::string> parseStateIntoTokens(std::string s);
std::string getLogicalStartState(std::string state);
bool doesHandlerExist(std::string state, std::string msgId, mlir::ModuleOp &mod);
bool doesStateExist(std::string state, mlir::ModuleOp &mod);
bool isTransientState(std::string state);
std::string getUniqueId();

} // namespace utils
