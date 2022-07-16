#include "function.h"


//CTOR
Function::Function(){};

Function::Function(char i){
    sign = i;
};

Function::Function(string i){
    if(i.length() == 1){
        sign = i[0];
    }
    else{
        s_sign = i;
    }
};

// declare virtual function
TOKEN_TYPES Function::getType() {
        return FUNCTION; 
}; 

double Function::getVal(){
    return sign;
};

int Function::getPrec(){
    return precedence;
}

void Function::Print(ostream &outs) const {
    outs << sign;
}