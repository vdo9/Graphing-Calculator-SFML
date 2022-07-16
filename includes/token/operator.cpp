#include "operator.h"

//CTOR
Operator::Operator(){};

Operator::Operator(string i){
    sign = i;
    setUnary();
    setPrec();
    // cout << "here is the sign:" << sign << endl;
}

// declare virtual function
TOKEN_TYPES Operator::getType() {
        return OPERATOR; 
}; 

string Operator::getOp(){
    return sign;
};

bool Operator::setUnary(){
    if(sign == "sqrt" || sign == "sin" || sign == "cos" || sign == "tan" || sign == "log" || sign == "exp"){
        // cout << "unary set: " << endl;
        unary = true;
    }
    else{
        unary = false;
    }
    return unary;
};

int Operator::getPrec(){
    return precedence;
};

void Operator::setPrec(){
    if(sign == "+"){
        precedence = 1;
        asso = "left";
    }
    else if(sign == "-"){
        precedence = 1;
        asso = "left";
    }
    else if(sign == "*"){
        precedence = 2;
        asso = "left";
    }
    else if(sign == "/"){
        precedence = 2;
        asso = "left";
    }
    else if(sign == "^"){
        precedence = 3;
        asso = "right";
    }
    else{
        precedence = 5;
    }
};

double Operator::getResult(string i, double first, double second){
    if(i == "+"){
        return first + second;
    }
    else if(i == "-"){
        return first - second;
    }
    else if(i == "*"){
        return first * second;
    }
    else if(i == "/"){
        return first / second;
    }
    else if(i == "^"){
        return pow(first, second);
    }
    else if(i == "max"){
        if (first >= second){
            return first;
        }
        else{
            return second;
        }
    }

    return 0.0;
};

double Operator::getResult(string i, double input){
    if(i == "sin"){
        return sin(input);
    }
    else if(i == "cos"){
        return cos(input);
    }
    else if(i == "tan"){
        return tan(input);
    }
    else if(i == "sqrt"){
        return sqrt(input);
    }
    else if(i == "log"){
        return log(input);
    }
    else if(i == "exp"){
        return exp(input);
    }
    return 0.0;
}

void Operator::Print(ostream &outs) const {
    outs << sign;
}