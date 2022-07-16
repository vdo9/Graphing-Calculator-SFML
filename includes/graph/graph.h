#ifndef GRAPH_H
#define GRAPH_H

// #include "gtest/gtest.h"
#include <cmath>
#include <iostream>
#include <iomanip>
#include <set>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <time.h>

#include "../queue/MyQueue.h"
#include "../token/function.h"
#include "../token/integer.h"
#include "../token/leftparen.h"
#include "../token/operator.h"
#include "../token/rightparen.h"
#include "../token/token.h"
#include "../shunting_yard/shunting_yard.h"
#include "../rpn/rpn.h"


using namespace std;

class Graph{
    public:
        //CTOR
        Graph();
        // Graph(int min, int max);
        
        // created and run expression to check for sinx
        void createExpression(Queue<Token*> infix);
        
        // given interval
        int min_x;
        int max_x; 

        // vector to save y -coordinates
        vector<double> realCoord;
        // variable for y coord
        double yCoord;
};

#endif