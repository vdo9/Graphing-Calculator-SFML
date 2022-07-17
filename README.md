[![Open in Visual Studio Code](https://classroom.github.com/assets/open-in-vscode-c66648af7eb3fe8bc4f294546bfd86ef473780cde1dea487d3c4ff354943c9ae.svg)](https://classroom.github.com/online_ide?assignment_repo_id=8027954&assignment_repo_type=AssignmentRepo)
# C++ Graphing Calculator Built with SFML Multimedia Library

## Objective
As part of my final project for my advanced C++ course at Pasadena City College, I created a Graphing Calculator with an interactive interface using SFML, a simple API for creating games and various multimedia components. In my class, as a progression towards this final project, I developed a thorough understanding of pointers, classes & objects, friend functions & overloading operators, linked lists, stacks & queues, inheritance, and polymorphism. In order to implement a graphing calculator, I learned the shunting yard and rpn algorithm used to remodel and generate solutions to an expression. 

I'd like to document this project as my first official project as I've faced many challenges and learned tremendously through creating this Graphing Calculator. The greatest challenge I faced and would like to continue working on is developing a better understanding on how to organize a project. Some questions I struggled with were:

What is the best way to condense my code? <br>
Where should I write the methods? <br>
When should I create an object? <br>
Should I include this logic in this part of the code? <br>

Currently, this graphing calculator can take the following expressions:
| Type                 | Example                    | 
| -------------------- |:--------------------------:| 
| Polynomials (1 term) | X^2+3 ; X^3+1 ; 3*X^3+X^2+3| 
| Trigonometric        | sin(X) ; cos(X) ; tan(X)   | 

## Explanation of Shunting Yard and Reverse Polish Notation Algorithm
<img src="https://upload.wikimedia.org/wikipedia/commons/thumb/2/24/Shunting_yard.svg/1000px-Shunting_yard.svg.png" width="600">

The goal of the Shunting Yard (SY) algorithm is to take an expression in 'infix order' (3+5) and convert it to 'postfix order' (3 5 +) in order to solve the expression with Reverse Polish Notation (RPN). For SY, while looping through each expression character, operands and operator are separated. A queue is created to hold the operands and operators in a specific order. A stack is created to hold the operators while determining their correct order. Each operator such as '+', '-', '*', etc. is assigned a precedence rank, depending on which is the higher rank, the operator is pushed into the output queue which creates the postfix order.

As for solving the expression, a stack is used to evaluate the postfix notation also known as the RPN algorithm. While looping through the postfix notation, operands and operators are separated again. This time, when an operator is found, two operands are popped off from the stack and the operator is performed on them. This is done until the stack is empty, resulting in the solution. 

## Example of Graphing Calculator Usage

![Graphing Calculator - Animated gif demo](demo/graphing-calc-demo.gif | width=400)




