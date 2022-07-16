#include "leftparen.h"

//CTOR
LeftParen::LeftParen(){
    sign = '(';
};

LeftParen::LeftParen(char i){
    sign = i;
}

LeftParen::LeftParen(string i){
    sign = i[0];
}

// declare virtual function
TOKEN_TYPES LeftParen::getType() {
        return LPAREN; 
}; 

double LeftParen::getVal(){
    return sign;
};

void LeftParen::Print(ostream &outs) const {
    outs << sign;
}