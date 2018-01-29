#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <string>
#include <vector>
#include "state.hpp"

using std::cout;
using std::endl;
using std::string;
using std::vector;

class menu : public state{
public:
        menu();
        void switchedTo();
        void switchedFrom();
        void draw();
private:
        //vector<object *> components;
};

#endif
