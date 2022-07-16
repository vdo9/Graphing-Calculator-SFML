#ifndef RIGHTPAREN_H
#define RIGHTPAREN_H

#include <iostream>
#include <string>

#include "token.h"
#include "constants.h"

using namespace std;

class RightParen: public Token 
{
public:
    //CTOR
    RightParen();
    RightParen(char s);
    RightParen(string s);

    TOKEN_TYPES getType() override;
    double getVal() override;

    void Print(ostream &outs=cout) const override;

private:
    char sign;
};

#endif //RIGHTPAREN_H