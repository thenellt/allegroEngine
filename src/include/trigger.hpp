#pragma once

#include "rect.hpp"

struct trigger{
        /*
        enum type {KEYBOARD, MOUSE};
        trigger(int b) : type(t), button(b) {};
        trigger(int b)
        */
        bool check(int e, int mouseX, int mouseY) const{
                return true;
        };

        int type;
        int button;
        rect bounds;
};
