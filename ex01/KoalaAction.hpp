/*
** EPITECH PROJECT, 2019
** KoalaAction.hpp
** File description:
** ex01
*/

#ifndef _KOALAACTION_
#define _KOALAACTION_ 

#include <iostream>
#include <string>
#include <cstdlib >
#include "DomesticKoala.hpp"

class KoalaAction {
       public:  
        void eat(const std::string &str) {
                std::cout << "eat" << str << std::endl;
        }
        void goTo(const std::string &str) {
                std::cout << "goto" << str << std::endl;
        }
        void sleep(const std::string &str) {
                std::cout << "sleep" << std << std::endl;
        }
        void reproduce(const std::string &str) {
                std::cout << "reproduce" << str << std::endl;
        }
};