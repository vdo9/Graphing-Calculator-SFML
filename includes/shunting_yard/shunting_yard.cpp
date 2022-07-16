#include "shunting_yard.h"

// CTOR
ShuntingYard::ShuntingYard()
{
    queue = Queue<Token*>();
};

ShuntingYard::ShuntingYard(const Queue<Token*>& input_q)
{
    queue = input_q;

};

// save input_q to member variable queue
void ShuntingYard::infix(const Queue<Token*>& input_q){
    queue = input_q;

};

// generate postfix queue from infix queue
Queue<Token*> ShuntingYard::postfix()
{
    return shunting_yard();
};

Queue<Token*> ShuntingYard::postfix(const Queue<Token*>& input_q)
{
    queue = input_q;

    return shunting_yard();
};

// called by postfix() 
Queue<Token*> ShuntingYard::shunting_yard()
{
    Stack<Token*> stack;
    Queue<Token*> postQueue;

    while(queue.empty() == false){
        if(queue.front()->getType() == INTEGER){
            postQueue.push(queue.pop());
            // queue.pop();
        }
        else if(queue.front()->getType() == LPAREN){
            stack.push(queue.front());
            queue.pop();
        }
        else if(queue.front()->getType() == RPAREN){
            while(stack.top()->getType() != LPAREN){
                postQueue.push(stack.top());
                stack.pop();
            }
            stack.pop(); // removes the LPAREN
            queue.pop(); // removes RPAREN
        }
        else if(queue.front()->getType() == OPERATOR || queue.front()->getType() == FUNCTION){
            if(stack.empty() == true){
                stack.push(queue.pop());
            }
            //change pointer label
            // else if(queue.front()->getOp() == '^' && stack.top()->getOp() == '^'){
            //     stack.push(queue.pop());
            // }
            else if(static_cast<Operator*>(queue.front())->getOp() == "^" && static_cast<Operator*>(stack.top())->getOp() == "^"){
                stack.push(queue.pop());
            }
            // check if top of stack is greater than or less than the queue item about to be pushed on stack
            else if(queue.front()->getPrec() <= stack.top()->getPrec()){
                // loops for continous precedence cond.
                while(stack.empty() == false && queue.front()->getPrec() <= stack.top()->getPrec()){
                    postQueue.push(stack.pop());
                }
                stack.push(queue.pop());
            }
            else if(queue.front()->getPrec() > stack.top()->getPrec()){
                stack.push(queue.pop());
            }
        }
    }
    // queue is empty, pop stack and push to postqueue
    while(stack.empty() == false){
        postQueue.push(stack.pop());
    }

    return postQueue;
};