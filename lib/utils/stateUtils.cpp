#include "utils/stateUtils.h"
#include "PCC/Dialect.h"
#include "PCC/Ops.h"
#include <set>

bool utils::isCpuEvent(std::string event) {
  return event == "load" || event == "store" || event == "evict";
}

std::vector<std::string> utils::getAllMsgTypes(mlir::ModuleOp &mod) {
  std::set<std::string> msgTypes;

  mod.walk([&](mlir::pcc::MsgConstrOp msgConstr) {
    mlir::ArrayAttr params =
        msgConstr.getAttr("params").cast<mlir::ArrayAttr>();
    std::string msgId = params[0].cast<mlir::StringAttr>().getValue().str();
    msgTypes.insert(msgId);
  });

  std::vector<std::string> v(msgTypes.begin(), msgTypes.end());
  return v;
}

std::vector<std::string> utils::parseStateIntoTokens(std::string s) {
  std::string delim = "_";
  std::vector<std::string> tokens;

  auto start = 0U;
  auto end = s.find(delim);

  while (end != std::string::npos) {
    std::string token = s.substr(start, end - start);
    tokens.push_back(token);
    start = end + delim.length();
    end = s.find(delim, start);
  }
  std::string token = s.substr(start, end);
  tokens.push_back(token);
  return tokens;
}

std::string utils::getLogicalStartState(std::string state){
  std::vector<std::string> tokens = utils::parseStateIntoTokens(state);
  return tokens[0] + "_" + tokens[1];
}

bool utils::doesHandlerExist(std::string state, std::string msgId,
                             mlir::ModuleOp &mod) {
  // std::cout << "attempting to find hander for state : " << state << " msgId
  // : " << msgId << std::endl;
  bool found = false;
  mod.walk([&](mlir::pcc::FunctionOp fun) {
    std::string action =
        fun.getAttr("action").cast<mlir::StringAttr>().getValue().str();
    std::string cur_state =
        fun.getAttr("cur_state").cast<mlir::StringAttr>().getValue().str();

    if (cur_state == state && action == msgId) {
      found = true;
    }
  });
  // std::cout << "Found completed with result " << found << std::endl;
  return found;
}

bool utils::doesStateExist(std::string state, mlir::ModuleOp &mod){
  bool exists = false;
  mod.walk([&](mlir::pcc::FunctionOp fun) {
    std::string cur_state = fun.getAttr("cur_state").cast<mlir::StringAttr>().getValue().str();
    if (cur_state == state){
      exists = true;
    }
  });
  return exists;
}

bool utils::isTransientState(std::string state){
  std::vector<std::string> tokens = utils::parseStateIntoTokens(state);
  return tokens.size() > 2;
}