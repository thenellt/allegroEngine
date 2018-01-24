#pragma once

#include <string>
#include <vector>
#include "object.hpp"

using std::string;
using std::vector;

class menu{
public:
        menu();
        menu(string);
        void draw();
private:
        vector<object *> components;
};
