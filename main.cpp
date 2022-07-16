#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <time.h>
#include <string>
#include <vector>
#include "Color.hpp"

#include "includes/textbox/textbox.h"
#include "includes/graph/graph.h"
#include "includes/tokenizer/tokenizer.h"
#include "includes/queue/MyQueue.h"
#include "includes/token/function.h"
#include "includes/token/integer.h"
#include "includes/token/leftparen.h"
#include "includes/token/operator.h"
#include "includes/token/rightparen.h"
#include "includes/token/token.h"
#include "includes/shunting_yard/shunting_yard.h"
#include "includes/rpn/rpn.h"

const int SCREEN_WIDTH = 2200;
const int SCREEN_HEIGHT = 1600;
const int GRID_WIDTH = 200;
const int GRID_HEIGHT = 110;
const int CELL_SIZE = 5;

using namespace std;

void createCircles(Graph* graph, vector<sf::CircleShape> &circles, Tokenizer* token);
void clearHistory(vector<sf::Text> &expressions, Textbox &textbox1);

int main()
{
    //----------S E T U P ------------------------------:

    //declare a window object:
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "GRAPHING CALCULATOR");
    window.setFramerateLimit(3);

    //this is where we keep all the shapes.
    //sf::RectangleShape shapeArray[GRID_HEIGHT][GRID_WIDTH];

    // call it once, after creating the window
    window.setVerticalSyncEnabled(true);
    //Application runs at the same freq as monitor

// ------- CREATING VIEW PANEL ON RIGHT SIDE --------- //
    sf::RectangleShape viewPanel;
    viewPanel.setSize(sf::Vector2f(600, 1600));
    viewPanel.setPosition(sf::Vector2f(1600, 0));
    viewPanel.setFillColor(sf::Color(40,40,40));

// ------ CREATING TITLE AND THE TEXTBOX ---------- //
    sf::Font verdana;
    verdana.loadFromFile("Verdana.ttf");
    Textbox textbox1(30, sf::Color(102, 255, 102), true);
    textbox1.setFont(verdana);
    textbox1.setPosition({1650, 90});

    sf::Text title("Enter expression here: ", verdana);
    title.setCharacterSize(30);
    title.setStyle(sf::Text::Bold);
    title.setFillColor(sf::Color(255, 176, 0));
    title.setPosition({1650, 35});

    sf::Text history("History: (Click to View) ", verdana);
    history.setCharacterSize(30);
    history.setStyle(sf::Text::Bold);
    history.setFillColor(sf::Color(255, 176, 0));
    history.setPosition({1650, 180});

    sf::Text clearButton("Clear History", verdana);
    clearButton.setCharacterSize(30);
    clearButton.setStyle(sf::Text::Bold);
    clearButton.setFillColor(sf::Color(255, 176, 0));
    clearButton.setPosition({1650, 1520});

 // ----- CODE FOR DRAWING AXIS AND GRID MARKS -------//
    // setting y-axis
    sf::RectangleShape lineY;
    lineY.setSize(sf::Vector2f(1600, 4));
    lineY.setPosition(sf::Vector2f(0, 1600/2));
    // lineY.setFillColor(sf::Color(255, 176, 0));
    lineY.setFillColor(sf::Color::Black);

    // setting x-axis
    sf::RectangleShape lineX;
    lineX.setSize(sf::Vector2f(4, 1600));
    lineX.setPosition(sf::Vector2f(1600/2, 0));
    lineX.setFillColor(sf::Color::Black);

    // this is for drawing the x-axis grid lines
    vector<sf::RectangleShape> x_lines;
    int screen_w = 1600;
    int screen_h = 0;

    // 21 to 41
    for(int i = 0; i < 41; i++){
        sf::RectangleShape line;
        line.setSize(sf::Vector2f(screen_w, 1));
        line.setPosition(sf::Vector2f(0, screen_h/4));
        // line.setFillColor(sf::Color(0, 255, 102));
        line.setFillColor(sf::Color::Black);

        
        x_lines.push_back(line);
        screen_h += 200;
    }
    // this is for drawing the y-axis grid lines
    vector<sf::RectangleShape> y_lines;
    screen_w = 0;
    screen_h = 1600;

    for(int i = 0; i < 33; i++){
        sf::RectangleShape line;
        line.setSize(sf::Vector2f(1, screen_h));
        line.setPosition(sf::Vector2f(screen_w/4, 0));
        line.setFillColor(sf::Color::Black);
        
        y_lines.push_back(line);
        screen_w += 200;
    }
 // ----- END OF AXIS AND GRID MARK CODE ----//


// ---- TESTING OUT GRAPHING ---- //

    // holds y value realCoord from equation
    vector<sf::CircleShape> circles;
    // holds the string name of expression to add to history list
    vector<sf::Text> expressions; 
    // vector<string> expressionText;
    // expressionText.push_back("sin(X)");
    // expressionText.push_back("tan(X)");

    // cout << "checking again: " << expressionText[1] << endl;

// -------- LOOPING TO HAVE WINDOW OPEN ------- //
    // run the program as long as the window is open
    // this is your main loop:
    while (window.isOpen()){
        cout<<"looooping..."<<endl;
        // check all the window's events that were triggered since the last iteration of the loop

        sf::Event event;

        //go through all the pending events: keyboard, mouse, close, resize, etc.
        //pollEvent and waitEvent are the only two functions that can fill event
        while (window.pollEvent(event))//or waitEvent: EVENT LOOP
        {
            // check the type of the event...
            switch (event.type)
            {
            // window closed
            // "close requested" event: we close the window
            case sf::Event::Closed:
                cout<<"close event was encountered!"<<endl;
                window.close();
                break;
            case sf::Event::TextEntered:
                textbox1.typedOn(event);
        
                // for typing into box and entering into list
                if(textbox1.inputExist == true){

                    // must create new graph object in while loop to  redraw coordinates otherwise coordinates don't change //
                    Graph* graph = new Graph();
                    cout << "graph initialized" << endl;

                    // clear previous circle if enter new expression
                    circles.clear();

                    createCircles(graph, circles, textbox1.token);
                    
                    sf::Text text(textbox1.inputText, verdana);
                    text.setCharacterSize(30);
                    text.setFillColor(sf::Color(255, 204, 0));
                    expressions.push_back(text);
                }
                break;
            // key pressed
            case sf::Event::KeyPressed:
                cout<<"a key was pressed..."<<endl;
                break;
            case sf::Event::MouseButtonReleased:
                if (event.mouseButton.button == sf::Mouse::Right)
                {
                    std::cout << "the right button was pressed" << std::endl;
                    std::cout << "mouse x: " << event.mouseButton.x << std::endl;
                    std::cout << "mouse y: " << event.mouseButton.y << std::endl;
                    
                    // check for first button
                    if(event.mouseButton.x >= 1668 && event.mouseButton.y < 1520){
                        Tokenizer* token;
                        if(event.mouseButton.y >= 214 && event.mouseButton.y <= 270){
                            token = new Tokenizer(textbox1.expressionText[0]);
                        }
                        else if(event.mouseButton.y > 298 && event.mouseButton.y <= 334){
                            token = new Tokenizer(textbox1.expressionText[1]);
                        }
                        else if(event.mouseButton.y > 380 && event.mouseButton.y <= 390){
                            token = new Tokenizer(textbox1.expressionText[2]);
                        }
                        else if(event.mouseButton.y > 400 && event.mouseButton.y <= 440){
                            token = new Tokenizer(textbox1.expressionText[3]);
                        }
                        else if(event.mouseButton.y > 450 && event.mouseButton.y <= 490){
                            token = new Tokenizer(textbox1.expressionText[4]);
                        }
                        else if(event.mouseButton.y > 500 && event.mouseButton.y <= 540){
                            token = new Tokenizer(textbox1.expressionText[5]);
                        }
                        Graph* graph = new Graph();
                        cout << "graph initialized" << endl;

                        // clear previous circle if enter new expression
                        circles.clear();

                        createCircles(graph, circles, token); 
                     }

                    // check for clear button
                    else if(event.mouseButton.x >= 1668 && event.mouseButton.y > 1520 && event.mouseButton.y <= 1570 ){
                        clearHistory(expressions, textbox1);
                    }
                }
                else
                    std::cout<<"left button?"<<std::endl;
                break;
            default:
                break;
            }
        }


        // you HAVE TO clear your window on every iteration of this while.
        window.clear(sf::Color::White);
        
        // window.draw(line, 2, sf::Lines);
        window.draw(lineY);
        window.draw(lineX);
        window.draw(viewPanel);
        window.draw(title);
        window.draw(history);
        window.draw(clearButton);

        // for drawing grid
        for(int i = 0; i < 41; i++){
            window.draw(x_lines[i]);
        }
        for(int i = 0; i < 33; i++){
            window.draw(y_lines[i]);
        }

        // drawing textbox
        textbox1.drawTo(window);

        if(textbox1.inputExist == true){
            // for drawing circles
            for(int i=0; i < 160; i++){
                window.draw(circles[i]);
            }

            // loop to show list
            int listPos = 225;
            for(int i = 0; i < expressions.size(); i++){
                expressions[i].setPosition({1650, static_cast<float>(listPos)});
                window.draw(expressions[i]);
                listPos += 5;   
            }
        }

        window.display();
    }

    cout<<"------ NORMAL TERMINATION: WINDOW CLOSED!"<<endl;
    return 0;
}

// function for creating the coordinates for the circles from an expression and saving them
void createCircles(Graph* graph, vector<sf::CircleShape> &circles, Tokenizer* token){
    int screenw = 0;
    int screenh = 800;

    graph->createExpression(token->infix);
    // cout << "graph created expressionsss" << endl;

    for(int i = 0; i < 160; i++){
        sf::CircleShape circle(5.f);
        // cout << "circle created!!!" << endl;
        circle.setFillColor(sf::Color::Black);
        if(graph->realCoord[i]*100 < 0){
            // cout << "graphing real coordinates: " << graph->realCoord[i]*100 << endl;
            sf::Vector2f circlePos(screenw, screenh + abs(graph->realCoord[i]*100));
            circle.setPosition(circlePos);
        }
        else{
            sf::Vector2f circlePos(screenw, screenh - graph->realCoord[i]*100); 
            // cout << "graphing real coordinates: " << graph->realCoord[i]*100 << endl;
            circle.setPosition(circlePos);
        }
        screenw+=10;
        circles.push_back(circle);
    }  
}

// function for clearing the history
void clearHistory(vector<sf::Text> &expressions, Textbox &textbox1){
    int size = expressions.size();
    for(int i=0; i < size; i++){
        // removes expressions objects from vector
        expressions.pop_back();
        // does not let the window.draw() happen for circles
        textbox1.inputExist = false;
        // resets the textbox input and clears the string input from before
        textbox1.textbox.setString("_");
        textbox1.inputText = "";
        // clears ostringstream in the textbox
        textbox1.text.str("");
    }
}