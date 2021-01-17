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

bool target::murphi::Module::addBoilerplate(target::murphi::Boilerplate *boilerplate){
  typeDefs.push_back(boilerplate);
  return true;
}

bool target::murphi::Module::addVariable(target::murphi::Variable *var){
  variables.push_back(var);
  return true;
}

bool target::murphi::Module::addMessageConstructor(
    target::murphi::MessageContructor *msgConstr) {
  msgContructors.push_back(msgConstr);
  return true;
}

bool target::murphi::Module::addSendFunction(target::murphi::SendFunction *sendFunc){
  sendFunctions.push_back(sendFunc);
  return true;
}

void target::murphi::Module::print(mlir::raw_ostream &stream) {
  // ----- Print the constants ----- //
  stream << "const\n\n";
  for(auto constDecl : constantsList){
    constDecl->print(stream);
  }

  // ----- Print the type definitions ----- //
  stream << "type\n\n";
  for (auto td : typeDefs) {
    td->print(stream);
  }
  
  // ----- Print the var Declarations ----- //
  stream << "var\n\n";
  for (auto var : variables){
    var->print(stream);
  }

  // ----- Print the message constructors ----- //
  for (auto mc : msgContructors) {
    mc->print(stream);
  }

  // ----- Print the Send helper function ----- //
  for (auto sf : sendFunctions){
    sf->print(stream);
  }

  // ----- Print cache and directory funcitons ----- //
  // ----- Print cache and directory load/store functions ----- //
  // ----- Print cache ruleset ----- //
  // ----- Print network rulesets (EASY)----- //
  // ----- Print startstates ----- //
  // ----- Print Invariant (EASY)----- //

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
  for(auto var : this->variables){
    if(var->getDefiningId() == id){
      return var;
    }
  }
  // Search Message Constructors
    for(auto mc : this->msgContructors){
    if(mc->getDefiningId() == id){
      return mc;
    }
  }
  // Search Send Functions
    for(auto sf : this->sendFunctions){
    if(sf->getDefiningId() == id){
      return sf;
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
void target::murphi::Boilerplate::print(mlir::raw_ostream &stream){
  stream << printTemplate;
}


// ------- Variable ------- //
void target::murphi::Variable::print(mlir::raw_ostream &stream){
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
void target::murphi::SendFunction::print(mlir::raw_ostream &stream){
  switch (ordering)
  {
  case target::murphi::NetworkOrder::Ordered:
    stream << ordered_send_proc(netId);
    stream << ordered_pop_proc(netId);
    break;
  
  case target::murphi::NetworkOrder::Unordered:
    stream << unordered_send_proc(netId);
    break;
  }
}
