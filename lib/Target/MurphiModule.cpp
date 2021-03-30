#include "Target/MurphiModule.h"
#include "Target/MurphiTemplates.h"
#include "utils/murphiUtils.h"
#include "llvm/Support/raw_ostream.h"
#include <algorithm>
#include <sstream>

// ------- Murphi Module ------- //

bool target::murphi::Module::addConstant(target::murphi::Constant *constDecl) {
  constantsList.push_back(constDecl);
  return true;
}

bool target::murphi::Module::addEnum(target::murphi::Enum *enumDecl) {
  enumList.push_back(enumDecl);
  typeDefs.push_back(enumDecl);
  return true;
}
bool target::murphi::Module::addScalarset(
    target::murphi::Scalarset *scalarsetDeclaration) {
  scalarsetList.push_back(scalarsetDeclaration);
  typeDefs.push_back(scalarsetDeclaration);
  return true;
}

bool target::murphi::Module::addValRange(
    target::murphi::ValRange *valRangeDecl) {
  valRangeList.push_back(valRangeDecl);
  typeDefs.push_back(valRangeDecl);
  return true;
}

bool target::murphi::Module::addUnion(target::murphi::Union *unionDefinition) {
  unionList.push_back(unionDefinition);
  typeDefs.push_back(unionDefinition);
  return true;
}

bool target::murphi::Module::addRecord(
    target::murphi::Record *recordDefinition) {
  recordList.push_back(recordDefinition);
  typeDefs.push_back(recordDefinition);
  return true;
}

bool target::murphi::Module::addBoilerplate(
    target::murphi::Boilerplate *boilerplate) {
  typeDefs.push_back(boilerplate);
  return true;
}

bool target::murphi::Module::addVariable(target::murphi::Variable *var) {
  variables.push_back(var);
  return true;
}

bool target::murphi::Module::addMessageConstructor(
    target::murphi::MessageContructor *msgConstr) {
  msgContructors.push_back(msgConstr);
  return true;
}

bool target::murphi::Module::addMutexHelperFunction(
    target::murphi::MutexHelperFunction *helperFunction) {
  mutHelpFuns.push_back(helperFunction);
  return true;
}

bool target::murphi::Module::addSendFunction(
    target::murphi::SendFunction *sendFunc) {
  sendFunctions.push_back(sendFunc);
  return true;
}

bool target::murphi::Module::addMachineHandleFunction(
    target::murphi::MachineHandlerFunction f) {
  machHandleFuncs.push_back(f);
  return true;
}

bool target::murphi::Module::addCacheCPUEventFunction(
    target::murphi::CacheCPUEventFunction *cacheFunc) {
  cacheCpuEventFunctions.push_back(cacheFunc);
}

bool target::murphi::Module::addMessageHanlderFunction(
    target::murphi::MachineMessageHanlderFunc f) {
  messageHandlerFunctions.push_back(f);
  return true;
}

bool target::murphi::Module::addNetworkRuleset(
    target::murphi::NetworkRuleset rs) {
  netRulesets.push_back(rs);
  return true;
}

bool target::murphi::Module::addStartState(target::murphi::StartState ss) {
  this->startState = ss;
  return true;
}

void target::murphi::Module::print(mlir::raw_ostream &stream) {
  stream << getModule();
}

target::murphi::LanguageConstruct *
target::murphi::Module::findReference(std::string id) {
  // Search the Typedefs
  for (auto lc : this->typeDefs) {
    if (lc->getDefiningId() == id) {
      return lc;
    }
  }
  // Search the constants
  for (auto cd : this->constantsList) {
    if (cd->getDefiningId() == id) {
      return cd;
    }
  }
  // Search Variables
  for (auto var : this->variables) {
    if (var->getDefiningId() == id) {
      return var;
    }
  }
  // Search Message Constructors
  for (auto mc : this->msgContructors) {
    if (mc->getDefiningId() == id) {
      return mc;
    }
  }
  // Search Mutex Helper Functions
  for (auto hf : this->mutHelpFuns) {
    if (hf->getDefiningId() == id) {
      return hf;
    }
  }

  // Search Send Functions
  for (auto sf : this->sendFunctions) {
    if (sf->getDefiningId() == id) {
      return sf;
    }
  }
  // Search Cache CPU Event Functions
  for (auto ef : this->cacheCpuEventFunctions) {
    if (ef->getDefiningId() == id) {
      return ef;
    }
  }
  return nullptr;
}

// ------- MurphiConstantDeclaration ------- //
void target::murphi::Constant::print(mlir::raw_ostream &stream) {
  stream << "\t" << getDefiningId() << " : " << value << ";\n";
}

// ------- MurphiEnumDefinition ------- //
void target::murphi::Enum::print(mlir::raw_ostream &stream) {
  stream << getDefiningId() << " : enum {\n\t";
  llvm::interleave(enums, stream, ",\n\t");
  stream << "\n};\n";
};

// ------- MurphiScalarsetDefinition ------- //
void target::murphi::Scalarset::print(mlir::raw_ostream &stream) {
  if (this->intReference == nullptr) {
    stream << this->getDefiningId() << ": scalarset(" << intValue << ");\n";
  } else {
    stream << this->getDefiningId() << ": scalarset("
           << intReference->getDefiningId() << ");\n";
  }
}

// ------- MurphiValRangeDeclaration ------- //
void target::murphi::ValRange::print(mlir::raw_ostream &stream) {
  if (this->startReference == nullptr && this->endReference == nullptr) {
    stream << getDefiningId() << ": " << startValue << ".." << endValue
           << ";\n";
  } else if (this->startReference == nullptr && this->endReference != nullptr) {
    stream << getDefiningId() << ": " << startValue << ".."
           << endReference->getDefiningId() << ";\n";
  } else if (this->startReference != nullptr && this->endReference != nullptr) {
    stream << getDefiningId() << ": " << startReference->getDefiningId() << ".."
           << endReference->getDefiningId() << ";\n";
  }
}

// ------- Union ------- //
void target::murphi::Union::print(mlir::raw_ostream &stream) {
  stream << getDefiningId() << ": union{" << unions[0]->getDefiningId() << ", "
         << unions[1]->getDefiningId() << "};\n";
}

// ------- Record ------- //
void target::murphi::Record::print(mlir::raw_ostream &stream) {
  stream << getDefiningId() << ": record\n";
  for (auto elem : elements) {
    stream << "\t" << elem.first << " : " << elem.second->getDefiningId()
           << ";\n";
  }
  stream << "end;\n";
}

// ------- Boilerplate ------- //
void target::murphi::Boilerplate::print(mlir::raw_ostream &stream) {
  stream << printTemplate;
}

// ------- Variable ------- //
void target::murphi::Variable::print(mlir::raw_ostream &stream) {
  stream << variable_decl(id, typeId->getDefiningId());
}

// ------- MessageConstructor ------- //
void target::murphi::MessageContructor::print(mlir::raw_ostream &stream) {
  target::murphi::Record *messageRecord =
      dynamic_cast<target::murphi::Record *>(messageDef);
  std::string msgParams;
  std::string fieldDefs;

  // For the defined extra field add a new parameter to the function with the
  // correct type
  for (std::string ef : extraFields) {
    msgParams += "; ";
    msgParams += ef;
    msgParams += ": ";
    msgParams += messageRecord->findEntry(ef).second->getDefiningId();
  }

  auto elements = messageRecord->getElements();
  for (int i = 4; i < (int)elements.size(); i++) {
    std::string fieldName = elements[i].first;
    fieldDefs += "\tmsg.";
    fieldDefs += fieldName;
    fieldDefs += " := ";
    fieldDefs += std::find(extraFields.begin(), extraFields.end(), fieldName) !=
                         extraFields.end()
                     ? fieldName
                     : "undefined";
    fieldDefs += ";\n";
  }
  stream << message_constructor(id, msgParams, fieldDefs);
}

// ------- MutexHelperFunction ------- //
void target::murphi::MutexHelperFunction::print(mlir::raw_ostream &stream) {
  stream << mutex_helper_function(id, clVar->getDefiningId(),
                                  mutValue ? "true" : "false");
}

// ------- SendFunction ------- //
void target::murphi::SendFunction::print(mlir::raw_ostream &stream) {
  switch (ordering) {
  case target::murphi::NetworkOrder::Ordered:
    stream << ordered_send_proc(netId);
    stream << ordered_pop_proc(netId);
    break;

  case target::murphi::NetworkOrder::Unordered:
    stream << unordered_send_proc(netId);
    break;
  }
}

// ------- Machine Message Hanlder ------- //
void target::murphi::MachineMessageHanlderFunc::print(
    mlir::raw_ostream &stream) {
  stream << make_handle_message_procedure(state, msgId, mach, localVars,
                                          procBody);
}

std::string
generateMurphiCodeFromOperation(mlir::Operation &op,
                                target::murphi::MachineMessageHanlderFunc &hf) {
  // ConstantOp
  if (auto constOp = mlir::dyn_cast<mlir::murphi::ConstantOp>(op)) {
    // forward declare the variable
    std::string id =
        constOp.getAttr("id").cast<mlir::StringAttr>().getValue().str();
    int value = constOp.getAttr("value").cast<mlir::IntegerAttr>().getInt();
    hf.localVars += make_local_var_decl(id, "integer");
    // add the Operation to the body of the function
    return id + " := " + std::to_string(value) + ";\n";
  }

  // ObjRefOp
  if (auto objRef = mlir::dyn_cast<mlir::murphi::ObjRefOp>(op)) {
    std::string objId =
        objRef.getAttrOfType<mlir::StringAttr>("objId").getValue().str();
    std::string ident =
        objRef.getAttrOfType<mlir::StringAttr>("ident").getValue().str();
    std::string id =
        objRef.getAttrOfType<mlir::StringAttr>("id").getValue().str();

    // Forward declare the local variable
    hf.localVars += make_local_var_decl(id, "unknown");

    // TODO -- insert the assignment op
    std::string rhsAssignment = objId + "_entry" + "." + ident;
    return make_general_assignment_statement(id, rhsAssignment);
  }

  // Compare Op
  if (auto compOp = mlir::dyn_cast<mlir::murphi::CompareOp>(op)) {
    std::string id = op.getAttrOfType<mlir::StringAttr>("id").getValue().str();

    // forward declare the local variable
    hf.localVars += make_local_var_decl(id, "boolean");

    std::string lhsId = op.getOperand(0)
                            .getDefiningOp()
                            ->getAttrOfType<mlir::StringAttr>("id")
                            .getValue()
                            .str();
    std::string rhsId = op.getOperand(1)
                            .getDefiningOp()
                            ->getAttrOfType<mlir::StringAttr>("id")
                            .getValue()
                            .str();
    std::string compareOp =
        op.getAttrOfType<mlir::StringAttr>("oper").getValue().str();

    // declare the compare OP
    std::string rhsOfAssignment = lhsId + " " + getMurphiOperand(compareOp) + " " + rhsId;
    return make_general_assignment_statement(id, rhsOfAssignment);
  }

  // If Op
  if (auto ifOp = mlir::dyn_cast<mlir::murphi::ExIfOp>(op)) {
    std::string boolRef = ifOp.getOperand()
                              .getDefiningOp()
                              ->getAttrOfType<mlir::StringAttr>("id")
                              .getValue()
                              .str();
    std::string thenOps;
    std::string elseOps;

    // generate ops for the then regions
    for (auto &thenOp : ifOp.getThenRegion().getBlocks().front()) {
      thenOps += generateMurphiCodeFromOperation(thenOp, hf);
    }

    // generate ops for the else regions
    for (auto &elseOp : ifOp.getElseRegion().getBlocks().front()) {
      elseOps += generateMurphiCodeFromOperation(elseOp, hf);
    }
    return make_if_else_statement(boolRef, thenOps, elseOps);
  }

  // MsgConstrOp
  if (auto msgConstrOp = mlir::dyn_cast<mlir::murphi::MsgConstrOp>(op)) {
    std::string msgType =
        msgConstrOp.getAttrOfType<mlir::StringAttr>("msgType").getValue().str();

    return message_constructor_call(msgType, "", "msg");
  }

  // SendOp
  if (auto sendOp = mlir::dyn_cast<mlir::murphi::SendOp>(op)) {
    std::string msgRef = "msg"; // TODO - improve
    std::string netRef = op.getOperand(1)
                             .getDefiningOp()
                             ->getAttrOfType<mlir::StringAttr>("id")
                             .getValue()
                             .str();
    return send_message(netRef);
  }

  // SetOp
  if (auto setOp = mlir::dyn_cast<mlir::murphi::SetOp>(op)){
    std::string id = setOp.getAttrOfType<mlir::StringAttr>("id").getValue().str();
    std::string value = setOp.getAttrOfType<mlir::StringAttr>("value").getValue().str();
    return make_general_assignment_statement(id, value);

  }

  if(auto mathOp = mlir::dyn_cast<mlir::murphi::MathOp>(op)){
    std::string lhs = mathOp.getOperand(0).getDefiningOp()->getAttrOfType<mlir::StringAttr>("id").getValue().str();
    std::string rhs = mathOp.getOperand(1).getDefiningOp()->getAttrOfType<mlir::StringAttr>("id").getValue().str();
    std::string op = mathOp.getAttrOfType<mlir::StringAttr>("op").getValue().str();
    std::string id = mathOp.getAttrOfType<mlir::StringAttr>("id").getValue().str();
    std::string rhsOfAssignment = lhs + " " + op + " " + rhs;
    return make_general_assignment_statement(id, rhsOfAssignment);
  }
  return "";
}

/// GENERATE BODY OF MESSAGE HANDLER FUNCTION ///
void target::murphi::MachineMessageHanlderFunc::generateBody(
    mlir::murphi::FunctionOp &func) {
  for (auto &op : func.getEntryBlock().getOperations()) {
    std::string murphiCode = generateMurphiCodeFromOperation(op, *this);
    this->procBody += murphiCode;
  }
}

// ------- Cache CPU Event Functions ------- //
void target::murphi::CacheCPUEventFunction::print(mlir::raw_ostream &stream) {
  stream << cache_load_store_proc(cacheState, cpuEvent, nestedOperations);
}

void target::murphi::CacheCPUEventFunction::addNestedOp(std::string op) {
  nestedOperations += op;
}

// ------- Cache Rule ------- //
std::string target::murphi::CacheRule::to_string() {
  return cache_rule(curState, cpuEvent, concurrent);
}

// ------- Cache RuleSet ------- //
void target::murphi::CacheRuleset::print(mlir::raw_ostream &stream) {
  std::string str_rules;
  for (auto rule : rules) {
    str_rules += rule.to_string();
  }
  stream << cache_ruleset(str_rules);
}

void target::murphi::CacheRuleset::addRule(target::murphi::CacheRule r) {
  rules.push_back(r);
}

// ------- Network RuleSet ------- //
void target::murphi::NetworkRuleset::print(mlir::raw_ostream &stream) {
  switch (ordering) {
  case target::murphi::NetworkOrder::Ordered:
    stream << ordered_ruleset(netId);
    break;
  case target::murphi::NetworkOrder::Unordered:
    stream << unordered_ruleset(netId);
    break;
  }
}

// ----------------------------------- //
// Cache/Directory Function Definition //
// ----------------------------------- //

// MachineHandlerFunction
void target::murphi::MachineHandlerFunction::print(mlir::raw_ostream &stream) {
  std::string body;
  for (auto item : stateHandlers) {
    body += item.to_string();
  }
  stream << machine_handler(machName,
                            switch_statement(machName + "_entry.State", body));
}

void target::murphi::MachineHandlerFunction::addStateHandler(
    target::murphi::StateHandler sh) {
  stateHandlers.push_back(sh);
}

// StateHandler
std::string target::murphi::StateHandler::to_string() {
  // If no MsgHandlers then we return false;
  if (msgHandlers.empty()) {
    return case_statement(stateId, "return false;");
  }
  std::string body;
  for (auto mh : msgHandlers) {
    body += mh.to_string();
  }
  return case_statement(stateId,
                        switch_statement_else_false("inmsg.mtype", body));
}

void target::murphi::StateHandler::addMessageHandler(
    target::murphi::MessageHandler mh) {
  msgHandlers.push_back(mh);
}

// MessageHandler
std::string target::murphi::MessageHandler::to_string() {
  return case_statement(messageId, operationsText);
}

void target::murphi::MessageHandler::add_operation_text(std::string text) {
  operationsText += text;
}
