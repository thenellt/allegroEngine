#ifndef TRIGGERS_HPP
#define TRIGGERS_HPP

#include <vector>
#include "rect.hpp"

using std::vector;

class trigger{
public:
        void setID(int);
        bool checkID(int);
protected:
        int id;
        int type;
};

class mouseTrigger : public trigger{
public:
        mouseTrigger();                 //any mouse activity
        mouseTrigger(int);              //specific mouse button
        mouseTrigger(int, rect);        //button in region
        mouseTrigger(rect);             //any activity in region

        bool check(int, int, int);      //button, x, y
private:
        enum mTrigType {any, click, clickRegion, region};
        rect bounds;
        int button;
};

class keyTrigger : public trigger{
public:
        keyTrigger();
        keyTrigger(int);
        keyTrigger(vector<int>);

        bool check(int);
private:
        enum kTrigType {any, single, many};
        int key;
        vector<int> keys;
};

#endif