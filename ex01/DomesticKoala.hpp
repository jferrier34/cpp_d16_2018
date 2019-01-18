/*
** EPITECH PROJECT, 2019
** DomesticKoala.hpp
** File description:
** ex01
*/

#ifndef _DOMESTICKOALA_
#define _DOMESTICKOALA_ 

#include <iostream>
#include <string>
#include <cstdlib >

class DomesticKoala {
        private:
        
        public:
               using methodPointer_t = xxxx;
               const std::vector<methodPointer_t> *getAction() const;
               void learnAction(unsigned char command, methodPointer_t action);
               void unlearnAction(unsigned char command);
               void doAction(unsigned char command, const std::string &param);
               void setKoalaAction(KoalaAction &);
};

#endif