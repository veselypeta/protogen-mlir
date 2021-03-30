#include "utils/murphiUtils.h"



std::string getMurphiOperand(std::string inOperand){
    if( inOperand == "=="){
        return "=";
    }
    return inOperand;
}