#include "rightparen.h"

//CTOR
RightParen::RightParen(){
    sign = ')';
};

RightParen::RightParen(char i){
    sign = i;
}

RightParen::RightParen(string i){
    sign = i[0];
}


// declare virtual function
TOKEN_TYPES RightParen::getType() {
        return RPAREN; 
}; 

double RightParen::getVal(){
    return sign;
};

void RightParen::Print(ostream &outs) const {
    outs << sign;
}