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

bool target::MurphiModule::addType(target::MurphiType t){
    typeList.push_back(t);
    return true;
}

void target::MurphiModule::print(mlir::raw_ostream &stream){
    // Print out all the Constants
    stream << "const\n";
    for (auto s : constantsList){
        s.print(stream);
    }

    stream << "\n\n";

    stream << "type\n";
    for (auto t : enumList){
        t.print(stream);
    }
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



