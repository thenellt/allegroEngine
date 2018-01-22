#ifndef ENGINE_HPP
#define ENGINE_HPP
#pragma once

#include <string>
#include "renderManager.hpp"
#include "eventManager.hpp"

extern eventManager *evntMngr;
extern renderManager *renderer;

class engine{
public:
    engine();
    void runGame();
    void loadLevel(std::string);
private:

};

#endif