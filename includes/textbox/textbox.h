#include <iostream>
#include <SFML/Graphics.hpp>
#include <sstream>
#include <string>

#define DELETE_KEY 8
#define ENTER_KEY 10 // changed from 13
#define ESCAPE_KEY 27

#include "../graph/graph.h"
#include "../tokenizer/tokenizer.h"
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

class Textbox {
    public:
        Textbox(){}
        Textbox(int size, sf::Color color, bool sel){
            textbox.setCharacterSize(size);
            textbox.setFillColor(color);
            isSelected = sel;
            if(sel){
                textbox.setString("_");
            }
            else {
                textbox.setString(" ");
            }
        }

        void setFont(sf::Font &font){
            textbox.setFont(font);
        }

        void setPosition(sf::Vector2f pos){
            textbox.setPosition(pos);
        }

        void setLimit(bool ToF){
            hasLimit = ToF;
        }

        void setLimit(bool ToF, int lim){
            hasLimit = ToF;
            limit = lim - 1;
        }

        void setSelected(bool sel){
            isSelected = sel;
            if(!sel){
                string t = text.str();
                string newT = "";
                for (int i = 0; i < t.length()-1;i++){
                    newT += t[i];
                }
                textbox.setString(newT);
            }
        }

        string getText(){
            return text.str();
        }

        void drawTo(sf::RenderWindow &window){
            window.draw(textbox);
        }
        
        void typedOn(sf::Event input){
            if(isSelected){
                int charTyped = input.text.unicode;
                if(charTyped < 128){
                    if(hasLimit){
                        if(text.str().length() <= limit){
                            inputLogic(charTyped);
                        }
                        else if(text.str().length() > limit && charTyped == DELETE_KEY){
                            deleteLastChar();
                        }
                    }
                    else{
                        inputLogic(charTyped);
                    }
                }
            }
        }

        Tokenizer* token;
        bool inputExist = false;
        string inputText = "";
        vector<string> expressionText;
        sf::Text textbox;
        ostringstream text; // the string of text

    private:
        bool isSelected = false;
        bool hasLimit = false;
        int limit;

        void inputLogic(int charTyped){
            if(charTyped != DELETE_KEY && charTyped != ENTER_KEY && charTyped != ESCAPE_KEY){
                cout << "what pressed: " << charTyped << endl;
                text << static_cast<char>(charTyped);
            }
            else if(charTyped == DELETE_KEY){
                inputText = "";
                if(text.str().length() > 0){
                    deleteLastChar();
                }
            }
            else if(charTyped == ENTER_KEY){
                cout << "enter key detected!!" <<endl;
                 // adds text to string to input graph
                inputText += text.str(); 
                cout << "inputText: " << inputText << endl;
                expressionText.push_back(inputText);
                inputExist = true;
                token = new Tokenizer(inputText);
            }
            textbox.setString(text.str() + "_");
        }

        void deleteLastChar(){
            string t = text.str();
            string newT = "";
            for (int i = 0; i < t.length()-1;i++){
                newT += t[i];
            }
            text.str("");
            text<<newT;

            textbox.setString(text.str());
        }
};