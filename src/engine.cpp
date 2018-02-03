#include "include/engine.hpp"

eventManager *evntMngr;
renderManager *renderer;

engine::engine(){
        al_init();
        al_init_image_addon();
        al_init_primitives_addon();
        al_init_font_addon();
        al_install_mouse();
        al_install_keyboard();

        evntMngr = new eventManager();
        renderer = new renderManager();

        states.push_back(new menu);
        states.back()->switchedTo();
        cout << "ran engine constructor" << endl;
        renderer->startFpsRegulator();
}

void engine::runGame(){
        bool running = true;
        while(running){
                const int status = evntMngr->poll();
                switch(status){
                case nothing:
                        break;
                case draw:
                        drawStates();
                        break;
                case pop:
                        states.pop_back();
                        states.back()->switchedTo();
                        break;
                case push:
                        states.back()->switchedFrom();
                        states.push_back(newState);
                        states.back()->switchedTo();
                        break;
                case quit:
                        running = false;
                        break;
                }
        }
}

void engine::drawStates(){
        unsigned int start = states.size();
        vector<state *>::reverse_iterator rit = states.rbegin();
        for(; rit != states.rend(); ++rit){
                start--;
                if((*rit)->isBlocking() || !start)
                        break;
        }

        for(; start < states.size(); start++)
                states.at(start)->draw();

        engineDebugDraw();
        renderer->finishFrame();
}

void engine::engineDebugDraw(){ //for drawing debug overlays over everything else
        renderer->drawFPSInfo();
}