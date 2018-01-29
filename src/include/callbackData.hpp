#ifndef CALLBACKDATA_HPP
#define CALLBACKDATA_HPP

struct callbackData{
        callbackData(int k, int mb, int mx, int my, bool dir) : key(k), mouseButton(mb),
                mouseX(mx), mouseY(my), isUp(dir) {};

        int key;
        int mouseButton;
        int mouseX;
        int mouseY;
        bool isUp;
};

#endif
