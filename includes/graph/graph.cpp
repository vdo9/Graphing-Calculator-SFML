#include "graph.h"

// when class is initialized, other functions will run
Graph::Graph(){
    min_x = -10;
    max_x = 10;
    // createExpression();
    // cout << "graph ran!!!" << endl;
 };

//  Graph::Graph(int min, int max){
//      min_x = min;
//      max_x = max;

//  }


// creating values from the expression
void Graph::createExpression(Queue<Token*> infix){
    // will evaluate expression between interval
    // will save the results to vector
    // cout << "graph.cpp error" << endl;
    ShuntingYard sy(infix);
    Queue<Token*> postfix = sy.postfix(); 
    cout << "the postfix: " << postfix << endl;

    for(double x = -8; x <= 8; x+= 0.1){
        RPN rpn(postfix);
        cout << "rpn(postfix) passed" <<endl;
        double y = rpn(x);
        cout << "y:" << y << endl;
        realCoord.push_back(y);
    }
};


