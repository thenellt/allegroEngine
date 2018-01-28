#ifndef CALLBACK_HPP
#define CALLBACK_HPP

#include <string>

struct callbackData{
        callbackData(int k, int mb, int mx, int my) : key(k), mouseButton(mb),
                mouseX(mx), mouseY(my) {};

        int key;
        int mouseButton;
        int mouseX;
        int mouseY;
};

#endif