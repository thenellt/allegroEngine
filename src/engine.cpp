#include "include/engine.hpp"

eventManager *evntMngr;
renderManager *renderer;

engine::engine(){
    evntMngr = new eventManager();
    renderer = new renderManager();
    
}

void engine::loadLevel(std::string levelPath){

}

void engine::runGame(){

}