#include "Target/MurphiModule.h"

// ------- Murphi Module ------- //

bool target::MurphiModule::addConstant(target::MurphiConstantDeclaration constDecl){
    constantsList.push_back(constDecl);
    return true;
}

bool target::MurphiModule::addEnum(target::MurphiEnumDeclaration enumDecl){
    enumList.push_back(enumDecl);
    return true;
}
bool target::MurphiModule::addScalarset(target::MurphiScalarsetDeclaration scalarsetDeclaration){
    scalarsetList.push_back(scalarsetDeclaration);
    return true;
}

bool target::MurphiModule::addValRange(target::MurphiValRangeDeclaration valRangeDecl){
    valRangeList.push_back(valRangeDecl);
    return true;
}

void target::MurphiModule::print(mlir::raw_ostream &stream){
    // Print out all the Constants
    stream << "const\n";
    for (auto s : constantsList){
        s.print(stream);
    }

    stream << "\n\n";

    // Print all Enums
    stream << "type\n";
    for (auto t : enumList){
        t.print(stream);
    }

    stream << "\n\n";
    // Print all Scalarsets
    for(auto ss : this->scalarsetList){
        ss.print(stream);
    }
    
}
target::MurphiReference* target::MurphiModule::findReference(std::string id){
    // loop over Constsnts
    for(int i=0; i < (int)constantsList.size(); i++){
        target::MurphiConstantDeclaration* c = &constantsList.data()[i];
        if(c->getDefiningId() == id){
            return c;
        }
    }

    // loop over Enums
    for(int i=0; i < (int)enumList.size(); i++){
        target::MurphiEnumDeclaration* e = &enumList.data()[i];
        if(e->getDefiningId() == id){
            return e;
        }
    }

    // Loop over scalarsets
    for(int i=0; i < (int)scalarsetList.size(); i++){
        target::MurphiScalarsetDeclaration* s = &scalarsetList.data()[i];
        if(s->getDefiningId() == id){
            return s;
        }
    }

    return nullptr;
}

// ------- MurphiConstantDeclaration ------- //
void target::MurphiConstantDeclaration::print(mlir::raw_ostream &stream){
    stream << "\t" << getDefiningId() << " : " << value << "\n";
}

// ------- MurphiEnumDefinition ------- //
void target::MurphiEnumDeclaration::print(mlir::raw_ostream &stream){
    stream << getDefiningId() << " : enum {\n\t";
    llvm::interleave(enums, stream, ",\n\t");
    stream << "\n};\n";
};

// ------- MurphiScalarsetDefinition ------- //
void target::MurphiScalarsetDeclaration::print(mlir::raw_ostream &stream){
    if(this->intReference == nullptr){
        stream << this->getDefiningId() << ": scalarset(" << intValue << ");";
    }else{
        stream << this->getDefiningId() << ": scalarset(" << intReference->getDefiningId() << ");";
    }
}
// ------- MurphiValRangeDeclaration ------- //
void target::MurphiValRangeDeclaration::print(mlir::raw_ostream &stream){
    if(this->startReference == nullptr && this->endReference == nullptr){
        stream << getDefiningId() << ": " << startValue << ".." << endValue << ";";
    }else if(this->startReference == nullptr && this->endReference != nullptr){
        stream << getDefiningId() << ": " << startValue << ".." << endReference->getDefiningId() << ";";
    }else if(this->startReference != nullptr && this->endReference != nullptr){
        stream << getDefiningId() << ": " << startReference->getDefiningId() << ".." << endReference->getDefiningId() << ";";
    }
}


