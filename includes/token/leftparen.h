#ifndef LEFTPAREN_H
#define LEFTPAREN_H

#include <iostream>
#include <string>

#include "token.h"
#include "constants.h"

using namespace std;

class LeftParen: public Token 
{
public:
    //CTOR
    LeftParen();
    LeftParen(char s);
    LeftParen(string s);

    TOKEN_TYPES getType() override;
    double getVal() override;

    void Print(ostream &outs=cout) const override;

private:
    char sign;
};

#endif //LEFTPAREN_H