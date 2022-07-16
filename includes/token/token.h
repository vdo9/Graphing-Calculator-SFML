#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>
#include <string>

#include "../../includes/token/constants.h"

using namespace std;

class Token 
{  
public:
    //CTOR
    Token();

    // declare virtual function
    virtual TOKEN_TYPES getType();
    virtual void Print(ostream &outs=cout) const;

    // integer, operator, functions getvalue func.
    virtual double getVal();
    // virtual char getOp();
    // virtual string getOps();

    // operator functions
    virtual void setPrec();
    virtual int getPrec();
    virtual double getResult(char i, double first, double second);
    virtual double getResult(string i, double first, double second);

    friend ostream& operator <<(ostream& outs, const Token* token);
    friend ostream &operator<<(ostream &outs, const Token &token);
};

#endif //TOKEN_H