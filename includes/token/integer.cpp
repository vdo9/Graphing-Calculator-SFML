#include "integer.h"


//CTOR
Integer::Integer(){};

Integer::Integer(double i){
    num = i;
};

// declare virtual function
TOKEN_TYPES Integer::getType() {
        return INTEGER; 
}; 

double Integer::getVal(){
    return num;
};

void Integer::Print(ostream &outs) const {
    outs << num;
}