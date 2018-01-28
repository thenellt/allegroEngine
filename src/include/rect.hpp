#ifndef RECT_HPP
#define RECT_HPP

struct rect{
        rect() : x(0), y(0), w(-1), h(-1) {};
        rect(int a, int b, int c, int d) : x(a), y(b), w(c), h(d) {};
        bool contains(int dx, int dy){
                return (dx >= x && dx <= x + w) && (dy <= y && dy >= y - h);
        }
        int x;
        int y;
        int w;
        int h;
};

#endif