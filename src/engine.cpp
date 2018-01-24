#include "include/engine.hpp"

eventManager *evntMngr;
renderManager *renderer;

engine::engine(){
    evntMngr = new eventManager();
    renderer = new renderManager();

}

void engine::runGame(){
        bool running = true;
        while(running){
                /*
                const int status = evntMngr->poll();
                switch(status){
                case evnt:
                        states.back()->handleEvents();
                case draw:
                        states.back()->draw();
                        break;
                case quit:
                        running = false;
                        break;
                }
                */
        }
}
