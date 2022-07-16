#ifndef OPERATOR_H
#define OPERATOR_H

#include <iostream>
#include <string>
#include <math.h>

#include "../../includes/token/token.h"
#include "../../includes/token/constants.h"

using namespace std;

class Operator: public Token
{
public:
    //CTOR
    Operator();
    Operator(string i);

    TOKEN_TYPES getType() override;
    string getOp();
    int getPrec() override;
    void setPrec() override;
    bool setUnary();
    double getResult(string i, double first, double second)override;
    double getResult(string i, double input);
    void Print(ostream &outs=cout) const override;
private:
    string sign;
    int precedence;
    string asso;
    bool unary;
};

#endif //OPERATOR_H