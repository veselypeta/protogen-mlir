#pragma once
#include <iostream>
#include <vector>
#include <exception>
#include "mlir/Target/LLVMIR/ModuleTranslation.h"
#include "llvm/ADT/TypeSwitch.h"

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

class MurphiModule {
public:
  bool addConstant(target::MurphiConstantDeclaration constDecl);
  bool addEnum(target::MurphiEnumDeclaration enumDecl);
  void print(mlir::raw_ostream &stream);

private:
  std::vector<MurphiConstantDeclaration> constantsList;
  std::vector<MurphiEnumDeclaration> enumList;
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
