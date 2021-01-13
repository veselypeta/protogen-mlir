#pragma once
#include "mlir/Target/LLVMIR/ModuleTranslation.h"
#include "llvm/ADT/TypeSwitch.h"
#include <exception>
#include <iostream>
#include <vector>

namespace target {

class MurphiReference {
public:
  virtual std::string getDefiningId() = 0;
  virtual ~MurphiReference(){};
};

// class MurphiType: public MurphiReference {
// public:
//     virtual void print(mlir::raw_ostream &stream) {
//         throw new std::exception();
//     };
//     virtual std::string getDefiningId(){throw new std::exception();}
//     virtual ~MurphiType(){};
// };

class MurphiConstantDeclaration : public MurphiReference {
public:
  MurphiConstantDeclaration(std::string constId, int constValue)
      : id{constId}, value{constValue} {}
  virtual void print(mlir::raw_ostream &stream);
  virtual std::string getDefiningId() { return id; };

private:
  std::string id;
  int value;
};

class MurphiEnumDeclaration : public MurphiReference {
public:
  MurphiEnumDeclaration(std::string enumId, std::vector<std::string> enumValues)
      : id{enumId}, enums{enumValues} {}
  virtual std::string getDefiningId() { return id; };
  virtual void print(mlir::raw_ostream &stream);

private:
  std::string id;
  std::vector<std::string> enums;
};

// Address: scalarset(ADR_COUNT);
class MurphiScalarsetDeclaration : public MurphiReference {
public:
  MurphiScalarsetDeclaration(std::string scalarsetId, int intValue)
      : id{scalarsetId}, intValue{intValue}, intReference{nullptr} {};
  MurphiScalarsetDeclaration(std::string scalarsetId, MurphiReference *ref)
      : id{scalarsetId}, intValue{-1}, intReference{ref} {};
  virtual std::string getDefiningId() { return id; }
  void print(mlir::raw_ostream &stream);

private:
  std::string id;
  int intValue;
  MurphiReference *intReference;
};

class MurphiValRangeDeclaration : public MurphiReference {
public:
  MurphiValRangeDeclaration(std::string id, int startVal, int endVal)
      : id{id}, startValue{startVal}, endValue{endVal}, startReference{nullptr},
        endReference{nullptr} {};
  MurphiValRangeDeclaration(std::string id, int startVal, MurphiReference *endRef)
      : id{id},startValue{startVal}, endValue{-1}, startReference{nullptr},
        endReference{endRef} {};
  MurphiValRangeDeclaration(std::string id, MurphiReference *startRef, MurphiReference *endRef)
      : id{id},startValue{-1}, endValue{-1}, startReference{startRef},
        endReference{endRef} {};
  
  std::string getDefiningId() {return id;};
  void print(mlir::raw_ostream &stream);

private:
  std::string id;
  int startValue;
  int endValue;
  MurphiReference *startReference;
  MurphiReference *endReference;
};

class MurphiModule {
public:
  bool addConstant(target::MurphiConstantDeclaration constDecl);
  bool addEnum(target::MurphiEnumDeclaration enumDecl);
  bool addScalarset(target::MurphiScalarsetDeclaration scalarsetDeclaration);
  bool addValRange(target::MurphiValRangeDeclaration valRangeDecl);
  void print(mlir::raw_ostream &stream);
  MurphiReference *findReference(std::string id);

private:
  std::vector<MurphiConstantDeclaration> constantsList;
  std::vector<MurphiEnumDeclaration> enumList;
  std::vector<MurphiScalarsetDeclaration> scalarsetList;
  std::vector<MurphiValRangeDeclaration> valRangeList;
};

// class MurphiTypeDefinitions {

//   bool addEnum(std::string id, std::vector<std::string> values);

// private:
//   std::vector<MurphiEnumDefinition> enums;
// };

// class MurphiEnumDefinition {
// public:
//   std::string print();
//   std::string getId();

// private:
//   std::vector<std::string> values;
//   std::string id;
// };

// class MurphiScalarsetDefinition {
// public:
//   std::string print();
//   std::string getId;

// private:
//   std::string id;
// };

// class MurphiRecordDefinition {
// public:
// private:
//   std::vector<std::string> fieldIds;
//   std::vector<MurphiTypeDefinitions> definitions;
// };

} // namespace target
