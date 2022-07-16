#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <iostream>
#include <string>
#include <string.h>
#include <cmath>
#include <typeinfo>

#include "../queue/MyQueue.h"
#include "../token/function.h"
#include "../token/integer.h"
#include "../token/leftparen.h"
#include "../token/operator.h"
#include "../token/rightparen.h"
#include "../token/token.h"
#include "../shunting_yard/shunting_yard.h"
#include "../rpn/rpn.h"

class Tokenizer{
    public:
        Tokenizer();
        Tokenizer(string input);

        int convertToASCII(char letter);

        Queue<Token*> infix;
        
};
#endif