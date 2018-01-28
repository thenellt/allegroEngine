#include "include/eventManager.hpp"

eventManager::eventManager(){
        evntQueue = al_create_event_queue();
        al_register_event_source(evntQueue, al_get_keyboard_event_source());
        al_register_event_source(evntQueue, al_get_mouse_event_source());
}

ALLEGRO_EVENT_QUEUE *eventManager::accessEventQueue(){
        return evntQueue;
}

int eventManager::poll(){
        ALLEGRO_EVENT event;
        al_wait_for_event(evntQueue, &event);
        
        switch(event.type){
        case ALLEGRO_EVENT_MOUSE_AXES:
                checkMouseMoveTriggers();
                break;
        case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
                
        case ALLEGRO_EVENT_MOUSE_BUTTON_UP:

        case ALLEGRO_EVENT_KEY_DOWN:
                checkKeyboardTriggers((event.keyboard.keycode);
                break;
        case ALLEGRO_EVENT_TIMER:
                if(renderer->checkTimer(event.source)){
                        return eventStatus::draw;
                } else {
                        cerr << "uncaught timer event: " << event.type << endl;
                        return eventStatus::nothing;
                }
        case ALLEGRO_EVENT_DISPLAY_RESIZE:
                renderer->confirmResize();
                return eventStatus::draw;
        case ALLEGRO_EVENT_DISPLAY_CLOSE:
                return eventStatus::quit;
        }
}