#pragma once
#include "mlir/Target/LLVMIR/ModuleTranslation.h"
#include "llvm/ADT/TypeSwitch.h"
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

class Module {
public:
  bool addConstant(target::murphi::Constant constDecl);
  bool addEnum(target::murphi::Enum enumDecl);
  bool addScalarset(target::murphi::Scalarset scalarsetDeclaration);
  bool addValRange(target::murphi::ValRange valRangeDecl);
  void print(mlir::raw_ostream &stream);
  LanguageConstruct *findReference(std::string id);

private:
  std::vector<Constant> constantsList;
  std::vector<Enum> enumList;
  std::vector<Scalarset> scalarsetList;
  std::vector<ValRange> valRangeList;
  std::vector<LanguageConstruct*> allConstructs;
};


} // namespace murphi
} // namespace target
