#ifndef FUNCTION_H
#define FUNCTION_H

#include <iostream>

#include "token.h"
#include "constants.h"

using namespace std;

class Function: public Token 
{
public:
    //CTOR
    Function();
    Function(char i);
    Function(string i);

    TOKEN_TYPES getType() override;
    double getVal() override;
    int getPrec() override;    
    void Print(ostream &outs=cout) const override;


private:
    char sign;
    string s_sign;
    int precedence = 4;
    
};

#endif //FUNCTION_H