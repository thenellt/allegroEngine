#ifndef TRIGGERS_HPP
#define TRIGGERS_HPP

#include <vector>
#include "rect.hpp"

using std::vector;

class trigger{
public:
        enum mTrigType {any, click, clickRegion, region};
        enum kTrigType {kany, single, many};
        void setID(int);
        bool checkID(int);
        int type;
protected:
        trigger(bool down) : isDown(down) {};
        int id;
        bool isDown;
};

class mouseTrigger : public trigger{
public:
        mouseTrigger(bool = false);                   //any mouse activity
        mouseTrigger(int, bool = false);              //specific mouse button
        mouseTrigger(int, rect, bool = false);        //button in region
        mouseTrigger(rect, bool = false);             //any activity in region

        bool check(int, int, int, bool);      //button, x, y
private:
        rect bounds;
        int button;
};

class keyTrigger : public trigger{
public:
        keyTrigger(bool = false);
        keyTrigger(int, bool = false);
        keyTrigger(vector<int>, bool = false);

        bool check(int, bool);
private:
        int key;
        vector<int> keys;
};

#endif
