/*
** EPITECH PROJECT, 2019
** parser.hpp
** File description:
** ex00
*/

#include <iostream>
#include <sstream>
#include "Parser.hpp"

//CONSTRUCTOR OF PARSER

Parser::Parser()
{
}

//DESTRUCTOR OF PARSER

Parser::~Parser()
{
}

//ALL CALCS

int add(int a, int b)
{
        int res;
        
        res = a + b;
        return (res);
}

int sub(int a, int b)
{
         int res;
        
        res = a - b;
        return (res);
}

int mult(int a, int b)
{
        int res;
        
        res = a * b;
        return (res);
}

int mod(int a, int b)
{       int res;
        
        res = a % b;
        return (res);
}

//CALLED THE CALCS


static int calc(int a, int b, char op)
{
    if (op == '+') {
           return add(a, b);
    }
    else if (op == '*') {
        return mult(a, b);
    }
    else if (op == '%') {
        return mod(a, b);
    }
    else
        return sub(a, b);
}


//CHECK IS DIGIT

bool is_digit(char nbr)
{

        if (nbr >= '0' && nbr <= '9')
                return (true);
        return (false);
}

//CHECK IS OP

bool is_op(char op)
{
        if (op == '+' || op == '-' || op == '*')
                return (true);
        return (false);
}

//STACK CALC


void Parser::feed(std::string const& str) {
    int nbr1;
    int nbr2;
    char op;
    int i = 0;

    while (str[i]) {
        if (is_digit(str[i]) == true) {
            int my_nbr = 0;
            while (str[i] && is_digit(str[i])) {
                my_nbr = my_nbr * 10 + str[i] - '0';
                ++i;
            }
            _operands.push(my_nbr);
        }
        else if (str[i] == ')') {
            nbr2 = _operands.top();
            _operands.pop();
            nbr1 = _operands.top();
            _operands.pop();
            op = _operators.top();
            _operators.pop();
            _operands.push(calc(nbr1, nbr2, op));
            ++i;
        }
        else if (str[i] == '+' || str[i] == '-' || str[i] == '/' || str[i] == '*' || str[i] == '%'){
            _operators.push(str[i]);
            ++i;
        }
        else
            ++i;
    }
    nbr1 = _operands.top();
    _operands.pop();
    if (!_operands.empty()) {
        if (!_operators.empty()) {
            op = _operators.top();
            _operators.pop();
            nbr1 = calc(nbr1, _operands.top(), op);
        }
        else {
            nbr1 += _operands.top();
            _operands.pop();
        }
    }
    _operands.push(nbr1);
}

int Parser::result() const {
    return _operands.top();
}

void Parser::reset() {
    while (!_operands.empty())
        _operands.pop();
    while (!_operators.empty())
        _operators.pop();
}
