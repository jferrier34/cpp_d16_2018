/*
** EPITECH PROJECT, 2019
** Parser.hpp
** File description:
** ex00
*/

#ifndef PARSER_H
#define PARSER_H

#include <stack>
#include <string>

class Parser {
  std::stack<char>    _operators;
  std::stack<int>     _operands;

public:
  Parser();
  ~Parser();

  void feed(std::string const&);
  int result() const;
  void reset();
};

#endif