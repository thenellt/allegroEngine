#ifndef ENGINE_HPP
#define ENGINE_HPP

#include <iostream>
#include <string>
#include <vector>
#include "renderManager.hpp"
#include "eventManager.hpp"
#include "state.hpp"
#include "menu.hpp"

using std::cout;
using std::endl;
using std::vector;

extern eventManager *evntMngr;
extern renderManager *renderer;

class engine{
public:
        engine();
        void runGame();
        void drawStates();
        void engineDebugDraw();
private:
        state *newState;
        vector<state *> states;
};

#endif
