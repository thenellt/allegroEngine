#ifndef ENGINE_HPP
#define ENGINE_HPP
#pragma once

#include <string>
#include <vector>
#include "renderManager.hpp"
#include "eventManager.hpp"

using std::vector;

extern eventManager *evntMngr;
extern renderManager *renderer;

class engine{
public:
        engine();
        void runGame();

private:
        //vector<state *> states;
};

#endif
