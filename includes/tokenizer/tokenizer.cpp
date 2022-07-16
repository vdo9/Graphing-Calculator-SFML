#include "tokenizer.h"

Tokenizer:: Tokenizer(){
    
}

Tokenizer:: Tokenizer(string input){
    string temp = "";
    string trig = "";

    for(int i = 0; i < input.length(); i++){
        // converting to simply check
        int num = convertToASCII(input[i]);

        // checking integers
        if(num >= 48 && num < 58){
            temp += input[i];
            i+=1;
            bool check = true;
            while(check){
                num = convertToASCII(input[i]);
                if(((num >= 48 && num < 58) || num == 46) && i < input.length()){
                    temp += input[i];
                    i+=1;
                    cout << "temp: " << temp << endl;
                }
                else{
                    i--;
                    check = false;
                }
            }
            infix.push(new Integer(stoi(temp)));
            cout << "integer pushed" << endl;
            temp = ""; // clear temp
        }
        // checking operators
        else if(num == 42 || num == 43 || num == 45 || num == 47 || num == 94){
            infix.push(new Operator(string(1, input[i])));
            cout << "operator pushed" << endl;
        }
        // checking function
        else if(num == 88){
            infix.push(new Function("X"));
            cout << "function pushed" << endl;
        }
        
        // checking sin
        else if(num == 115){
            trig += input[i];
            i+=1;
            while(input[i] != 'n'){ 
                num = convertToASCII(input[i]);
                trig += input[i];
                cout << "trig: " << trig << endl;
                i+=1;
            }
            if(input[i] == 'n'){
                trig += input[i];
            }
            infix.push(new Operator(trig));
        }

        // checking cos
        else if(num == 99){
            trig += input[i];
            i+=1;
            while(input[i] != 's'){ 
                num = convertToASCII(input[i]);
                trig += input[i];
                cout << "trig: " << trig << endl;
                i+=1;
            }
            if(input[i] == 's'){
                trig += input[i];
            }
            infix.push(new Operator(trig));
        }

        // checking tan
        else if(num == 116){
            trig += input[i];
            i+=1;
            while(input[i] != 'n'){ 
                num = convertToASCII(input[i]);
                trig += input[i];
                cout << "trig: " << trig << endl;
                i+=1;
            }
            if(input[i] == 'n'){
                trig += input[i];
            }
            infix.push(new Operator(trig));
        }
     
        // catching parenthesis
        else if(num == 40){
            cout << "caught left" << endl;
             infix.push(new LeftParen());
        }
        else if(num == 41){
            cout << "caught right" << endl;
            infix.push(new RightParen());
        }
    };
}

// converts to ascii value to check type
int Tokenizer::convertToASCII(char letter)
{
    char x = letter;
    cout << "ascii value" << int(x) << endl;
    return int(x);
}
