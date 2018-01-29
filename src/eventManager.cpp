#include "include/eventManager.hpp"
#include "include/renderManager.hpp"

eventManager::eventManager(){
        idCounter = 1;
        evntQueue = al_create_event_queue();
        al_register_event_source(evntQueue, al_get_keyboard_event_source());
        al_register_event_source(evntQueue, al_get_mouse_event_source());
}

ALLEGRO_EVENT_QUEUE *eventManager::accessEventQueue(){
        return evntQueue;
}

void eventManager::checkMouseMoveTriggers(int x, int y){
        cerr << "mouse move (x, y): (" << x << ", " << y << ")" << endl;
}

void eventManager::checkMouseButtonTriggers(int x, int y, bool isUp){
        cerr << "mouse move (x, y): (" << x << ", " << y << ")" << endl;
}

void eventManager::checkKeyboardTriggers(int key, bool isUp){
        cerr << "keyboard (key, down): (" << key << ", " << isUp << ")" << endl;
}

int eventManager::registerEvent(object *o, mouseTrigger m, objMemFnc func){
        const int freshID = idCounter++;
        m.setID(freshID);
        if(m.type == trigger::any || m.type == trigger::region)
                mousePosListners.push(m);
        else if(m.type == trigger::click || m.type == trigger::clickRegion)
                mouseButtonListeners.push(m);

        callbackLookup[freshID] = callback(o, func);
        return freshID;
}

int eventManager::registerEvent(object *o, keyTrigger k, objMemFnc func){
        const int freshID = idCounter++;
        keyTrigger temp = k;
        temp.setID(freshID);
        keyboardListners.push(temp);
        callbackLookup[freshID] = callback(o, func);
        return freshID;
}

int eventManager::poll(){
        ALLEGRO_EVENT event;
        al_wait_for_event(evntQueue, &event);

        switch(event.type){
        case ALLEGRO_EVENT_MOUSE_AXES:
                checkMouseMoveTriggers(event.mouse.x, event.mouse.y);
                break;
        case ALLEGRO_EVENT_MOUSE_BUTTON_DOWN:
                checkMouseButtonTriggers(event.mouse.x, event.mouse.y, false);
                break;
        case ALLEGRO_EVENT_MOUSE_BUTTON_UP:
                checkMouseButtonTriggers(event.mouse.x, event.mouse.y, true);
                break;
        case ALLEGRO_EVENT_KEY_DOWN:
                checkKeyboardTriggers(event.keyboard.keycode, false);
                break;
        case ALLEGRO_EVENT_KEY_UP:
                checkKeyboardTriggers(event.keyboard.keycode, true);
                break;
        case ALLEGRO_EVENT_TIMER:
                if(renderer->checkTimer(event.timer.source)){
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

        return eventStatus::nothing;
}
