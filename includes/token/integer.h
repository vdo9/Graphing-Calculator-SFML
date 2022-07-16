#ifndef INTEGER_H
#define INTEGER_H

#include <iostream>
#include <cmath>

#include "token.h"
#include "constants.h"

using namespace std;

class Integer: public Token
{
public:
    //CTOR
    Integer();
    Integer(double i);

    TOKEN_TYPES getType() override;
    double getVal() override;
    void Print(ostream &outs=cout) const override;
private:
    double num;
};

#endif //INTEGER_H