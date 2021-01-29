#include "Target/MurphiModule.h"
#include "Target/MurphiTemplates.h"
#include <algorithm>
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

bool target::murphi::Module::addSendFunction(
    target::murphi::SendFunction *sendFunc) {
  sendFunctions.push_back(sendFunc);
  return true;
}

bool target::murphi::Module::addMachineHandleFunction(target::murphi::MachineHandlerFunction f){
  machHandleFuncs.push_back(f);
  return true;
}

bool target::murphi::Module::addCacheCPUEventFunction(
    target::murphi::CacheCPUEventFunction *cacheFunc) {
  cacheCpuEventFunctions.push_back(cacheFunc);
}

bool target::murphi::Module::addNetworkRuleset(
    target::murphi::NetworkRuleset rs) {
  netRulesets.push_back(rs);
  return true;
}

void target::murphi::Module::print(mlir::raw_ostream &stream) {
  // ----- Print the constants ----- //
  stream << "const\n\n";
  for (auto constDecl : constantsList) {
    constDecl->print(stream);
  }

  // ----- Print the type definitions ----- //
  stream << "type\n\n";
  for (auto td : typeDefs) {
    td->print(stream);
  }

  // ----- Print the var Declarations ----- //
  stream << "var\n\n";
  for (auto var : variables) {
    var->print(stream);
  }

  // ----- Print the message constructors ----- //
  for (auto mc : msgContructors) {
    mc->print(stream);
  }

  // ----- Print the Send helper function ----- //
  for (auto sf : sendFunctions) {
    sf->print(stream);
  }

  // ----- Print cache and directory funcitons ----- //
  for (auto mh : machHandleFuncs){
    mh.print(stream);
  }

  // ----- Print cache and directory load/store functions ----- //
  for (auto ef : cacheCpuEventFunctions) {
    ef->print(stream);
  }
  // ----- Print cache ruleset ----- //
  cacheRuleset.print(stream);
  // ----- Print network rulesets (EASY)----- //
  for (auto nrs : netRulesets) {
    nrs.print(stream);
  }
  // ----- Print startstates ----- //
  // ----- Print Invariant (EASY) (SKIP FOR NOW)----- //
  // stream << write_serialization();
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
  stream << "\t" << getDefiningId() << " : " << value << "\n";
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

// ------- Cache CPU Event Functions ------- //
void target::murphi::CacheCPUEventFunction::print(mlir::raw_ostream &stream) {
  stream << cache_load_store_proc(cacheState, cpuEvent, "\n-- INSERT BODY OF FUNCTION HERE --\n");
}

// ------- Cache Rule ------- //
std::string target::murphi::CacheRule::to_string() {
  return cache_rule(curState, cpuEvent);
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
void target::murphi::MachineHandlerFunction::print(mlir::raw_ostream &stream){
  std::string body;
  for(auto item : stateHandlers){
    body += item.to_string();
  }
  stream << machine_handler(machName, switch_statement(machName+"_entry.State", body));
}

void target::murphi::MachineHandlerFunction::addStateHandler(target::murphi::StateHandler sh){
  stateHandlers.push_back(sh);
}

// StateHandler
std::string target::murphi::StateHandler::to_string(){
  // If no MsgHandlers then we return false;
  if(msgHandlers.empty()){
    return case_statement(stateId, "return false;");
  }
  std::string body;
  for(auto mh : msgHandlers){
    body += mh.to_string();
  }
  return case_statement(stateId, switch_statement_else_false("inmsg.id", body));
}

void target::murphi::StateHandler::addMessageHandler(target::murphi::MessageHandler mh){
  msgHandlers.push_back(mh);
}

// MessageHandler
std::string target::murphi::MessageHandler::to_string(){
  return case_statement(messageId, "-- INSERT BODY OF FUNCTION HERE --");
}

