#include "token.h"

//CTOR
Token::Token(){};

// declare virtual function
TOKEN_TYPES Token::getType() {
    return TOKEN;
}

double Token::getVal(){
    return 0.0;
};

// char Token::getOp(){
//   return ' ';
// };

// string Token::getOps(){
//   return "";
// };

void Token::setPrec(){

};

int Token::getPrec(){
    return 0;
}

double Token::getResult(char i, double first, double second){
    return 0.0;
};

double Token::getResult(string i, double first, double second){
    return 0.0;
};

void Token::Print(ostream &outs) const
{
  outs << "TOKEN Print: DON't ^%#$# call me again!" << endl;
}

ostream& operator <<(ostream& outs, const Token* token)
{
  token->Print(outs);
  return outs;
}

ostream &operator<<(ostream &outs, const Token &token)
{
  token.Print(outs);
  return outs;
}