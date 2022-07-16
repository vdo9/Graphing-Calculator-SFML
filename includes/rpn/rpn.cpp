#include "rpn.h"

// CTOR
RPN::RPN(){
    queue = Queue<Token*>();
};

RPN::RPN(const Queue<Token*>& input_q){
    queue = input_q;  
};

// save input_q to member variable queue
void RPN::set_input(const Queue<Token *> &input_q){
    queue = input_q;
};

// return result from member variable queue
double RPN::operator()(double value){
    return(rpn(value));
};

// called by operator ()
// has the rpn logic
double RPN::rpn(double value){
    Stack<Token*> stack;
    while(queue.empty() == false){
        if(queue.front()->getType() == INTEGER){
            stack.push(queue.front());
            // cout << "found integer";
        }

        else if(queue.front()->getType() == OPERATOR){
            // to work with single operands
            if(static_cast<Operator*>(queue.front())->setUnary() == true){
                // cout << "found true unary" << endl;
                double uresult = static_cast<Operator*>(queue.front())->getResult(static_cast<Operator*>(queue.front())->getOp(), stack.top()->getVal());
                stack.pop();
                // cout << "uresult: " << uresult <<endl;
                stack.push(new Integer(uresult));
            }
            else{   
                // cout << "found false unary" << endl;
                // cout << "top value: " << stack.top()->getVal() << endl;
                double op2 = stack.top()->getVal();
                stack.pop();
                // cout << "top value: " << stack.top()->getVal() << endl;
                double op1 = stack.top()->getVal(); // repeats
                stack.pop();
                double result;

                result = queue.front()->getResult(static_cast<Operator*>(queue.front())->getOp(), op1, op2);

                stack.push(new Integer(result));
            }

        }
        else if(queue.front()->getType() == FUNCTION){
            stack.push(new Integer(value));
            // cout << "found function" << endl;
        }
        queue.pop();
    }
    if(stack.size() == 1){
        return stack.top()->getVal();
    }
    return 0.0;
};