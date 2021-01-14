#include "Target/MurphiModule.h"

// ------- Murphi Module ------- //

bool target::murphi::Module::addConstant(target::murphi::Constant *constDecl) {
  constantsList.push_back(constDecl);
  allConstructs.push_back(constDecl);
  return true;
}

bool target::murphi::Module::addEnum(target::murphi::Enum *enumDecl) {
  enumList.push_back(enumDecl);
  allConstructs.push_back(enumDecl);
  return true;
}
bool target::murphi::Module::addScalarset(
    target::murphi::Scalarset *scalarsetDeclaration) {
  scalarsetList.push_back(scalarsetDeclaration);
  allConstructs.push_back(scalarsetDeclaration);
  return true;
}

bool target::murphi::Module::addValRange(
    target::murphi::ValRange *valRangeDecl) {
  valRangeList.push_back(valRangeDecl);
  allConstructs.push_back(valRangeDecl);
  return true;
}

bool target::murphi::Module::addUnion(target::murphi::Union *unionDefinition){
    unionList.push_back(unionDefinition);
    allConstructs.push_back(unionDefinition);
    return true;
}

bool target::murphi::Module::addRecord(target::murphi::Record *recordDefinition){
    recordList.push_back(recordDefinition);
    allConstructs.push_back(recordDefinition);
    return true;
}

void target::murphi::Module::print(mlir::raw_ostream &stream) {

    for(auto lc: allConstructs){
        lc->print(stream);
    }
  // Print out all the Constants
//   stream << "const\n";
//   for (auto s : constantsList) {
//     s.print(stream);
//   }

//   stream << "\n\n";

//   // Print all Enums
//   stream << "type\n";
//   for (auto t : enumList) {
//     t.print(stream);
//   }

//   stream << "\n\n";
//   // Print all Scalarsets
//   for (auto ss : this->scalarsetList) {
//     ss.print(stream);
//   }

//   // print all value ranges
//   for (auto vl : this->valRangeList) {
//     vl.print(stream);
//   }
}
target::murphi::LanguageConstruct *
target::murphi::Module::findReference(std::string id) {
    for (auto lc : this->allConstructs) {
      if (lc->getDefiningId() == id) {
        return lc;
      }
    }
  //   return nullptr;
  // loop over Constsnts
//   for (int i = 0; i < (int)constantsList.size(); i++) {
//     target::murphi::Constant *c = &constantsList.data()[i];
//     if (c->getDefiningId() == id) {
//       return c;
//     }
//   }

//   // loop over Enums
//   for (int i = 0; i < (int)enumList.size(); i++) {
//     target::murphi::Enum *e = &enumList.data()[i];
//     if (e->getDefiningId() == id) {
//       return e;
//     }
//   }

//   // Loop over scalarsets
//   for (int i = 0; i < (int)scalarsetList.size(); i++) {
//     target::murphi::Scalarset *s = &scalarsetList.data()[i];
//     if (s->getDefiningId() == id) {
//       return s;
//     }
//   }

//   // Loop over value ranges
//   for (int i = 0; i < (int)valRangeList.size(); i++) {
//     target::murphi::ValRange *v = &valRangeList.data()[i];
//     if (v->getDefiningId() == id) {
//       return v;
//     }
//   }

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
void target::murphi::Union::print(mlir::raw_ostream &stream){
    stream << getDefiningId() << ": union{" << unions[0]->getDefiningId() << ", " << unions[1]->getDefiningId() << "};\n";
}


// ------- Record ------- //
void target::murphi::Record::print(mlir::raw_ostream &stream){
    stream << getDefiningId() << ": record\n";
    for(auto elem : elements){
        stream << "\t" << elem.first << " : " << elem.second->getDefiningId() << ";\n";
    }
    stream << "end;\n";
}