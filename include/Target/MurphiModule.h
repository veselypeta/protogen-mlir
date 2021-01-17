#pragma once
#include "mlir/Target/LLVMIR/ModuleTranslation.h"
#include "llvm/ADT/TypeSwitch.h"
#include <cstdarg>
#include <exception>
#include <iostream>
#include <vector>

namespace target {
namespace murphi {

class LanguageConstruct {
public:
  virtual std::string getDefiningId() = 0;
  virtual void print(mlir::raw_ostream &stream) = 0;
  virtual ~LanguageConstruct(){};
};

class Constant : public LanguageConstruct {
public:
  Constant(std::string constId, int constValue)
      : id{constId}, value{constValue} {}
  virtual void print(mlir::raw_ostream &stream);
  virtual std::string getDefiningId() { return id; };

private:
  std::string id;
  int value;
};

class Enum : public LanguageConstruct {
public:
  Enum(std::string enumId, std::vector<std::string> enumValues)
      : id{enumId}, enums{enumValues} {}
  virtual std::string getDefiningId() { return id; };
  virtual void print(mlir::raw_ostream &stream);

private:
  std::string id;
  std::vector<std::string> enums;
};

// Address: scalarset(ADR_COUNT);
class Scalarset : public LanguageConstruct {
public:
  Scalarset(std::string scalarsetId, int intValue)
      : id{scalarsetId}, intValue{intValue}, intReference{nullptr} {};
  Scalarset(std::string scalarsetId, LanguageConstruct *ref)
      : id{scalarsetId}, intValue{-1}, intReference{ref} {};
  virtual std::string getDefiningId() { return id; }
  void print(mlir::raw_ostream &stream);

private:
  std::string id;
  int intValue;
  LanguageConstruct *intReference;
};

class ValRange : public LanguageConstruct {
public:
  ValRange(std::string id, int startVal, int endVal)
      : id{id}, startValue{startVal}, endValue{endVal}, startReference{nullptr},
        endReference{nullptr} {};
  ValRange(std::string id, int startVal, LanguageConstruct *endRef)
      : id{id}, startValue{startVal}, endValue{-1}, startReference{nullptr},
        endReference{endRef} {};
  ValRange(std::string id, LanguageConstruct *startRef,
           LanguageConstruct *endRef)
      : id{id}, startValue{-1}, endValue{-1}, startReference{startRef},
        endReference{endRef} {};

  std::string getDefiningId() { return id; };
  void print(mlir::raw_ostream &stream);

private:
  std::string id;
  int startValue;
  int endValue;
  LanguageConstruct *startReference;
  LanguageConstruct *endReference;
};

class Union : public LanguageConstruct {
public:
  Union(std::string unionId, LanguageConstruct *first,
        LanguageConstruct *second)
      : id{unionId} {
    unions.push_back(first);
    unions.push_back(second);
  };
  virtual std::string getDefiningId() { return id; }
  virtual void print(mlir::raw_ostream &stream);

private:
  std::vector<LanguageConstruct *> unions;
  std::string id;
};

class Record : public LanguageConstruct {
public:
  Record(std::string recordId) : id{recordId} {}
  virtual std::string getDefiningId() { return id; }
  virtual void print(mlir::raw_ostream &stream);
  void addEntry(std::string key, LanguageConstruct *type) {
    for (auto pair : elements) {
      if (pair.first == key) {
        return;
      }
    }
    elements.push_back({key, type});
  }
  std::pair<std::string, LanguageConstruct *> findEntry(std::string key) {
    for (auto pair : elements) {
      if (pair.first == key) {
        return pair;
      }
    }
  }
  std::vector<std::pair<std::string, LanguageConstruct *>> getElements() {
    return elements;
  }

private:
  std::string id;
  std::vector<std::pair<std::string, LanguageConstruct *>> elements;
};

class Boilerplate : public LanguageConstruct {
public:
  Boilerplate(std::string id, std::string printTemplate)
      : id{id}, printTemplate{printTemplate} {}
  virtual std::string getDefiningId() { return id; }
  virtual void print(mlir::raw_ostream &stream);

private:
  std::string id;
  std::string printTemplate;
};

class Variable : public LanguageConstruct {
public:
  Variable(std::string id, LanguageConstruct *typeId)
      : id{id}, typeId{typeId} {}
  virtual void print(mlir::raw_ostream &stream);
  virtual std::string getDefiningId() { return id; }

private:
  std::string id;
  LanguageConstruct *typeId;
};

class MessageContructor {
public:
  MessageContructor(std::string msgId, LanguageConstruct *msgDef)
      : id{msgId}, messageDef{msgDef} {}
  void print(mlir::raw_ostream &stream);
  void addExtraField(std::string fieldName) {
    extraFields.push_back(fieldName);
  }

private:
  std::string id;
  LanguageConstruct *messageDef;
  std::vector<std::string> extraFields;
};

class Module {
public:
  bool addConstant(target::murphi::Constant *constDecl);
  bool addEnum(target::murphi::Enum *enumDecl);
  bool addScalarset(target::murphi::Scalarset *scalarsetDeclaration);
  bool addValRange(target::murphi::ValRange *valRangeDecl);
  bool addUnion(target::murphi::Union *unionDef);
  bool addRecord(target::murphi::Record *record);
  bool addBoilerplate(target::murphi::Boilerplate *boilerplate);
  bool addVariable(target::murphi::Variable *var);
  bool addMessageConstructor(target::murphi::MessageContructor *msgConstr);
  void print(mlir::raw_ostream &stream);
  LanguageConstruct *findReference(std::string id);

  ~Module() {
    // Delete Constants
    for (auto cd : constantsList) {
      delete cd;
    }

    // Delete Type Defs
    for (auto lc : typeDefs) {
      delete lc;
    }

    // Delete Var Def
    for (auto var : variables) {
      delete var;
    }
  }

private:
  std::vector<Constant *> constantsList;
  std::vector<Enum *> enumList;
  std::vector<Scalarset *> scalarsetList;
  std::vector<ValRange *> valRangeList;
  std::vector<Union *> unionList;
  std::vector<Record *> recordList;
  std::vector<LanguageConstruct *> typeDefs;
  std::vector<Variable *> variables;

  std::vector<MessageContructor *> msgContructors;
};

} // namespace murphi
} // namespace target
