#ifndef EVENTMANAGER_HPP
#define EVENTMANAGER_HPP

#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro_font.h"
#include "allegro5/mouse.h"
#include "event.hpp"
#include "renderManager.hpp"
#include "triggers.hpp"
#include "callback.hpp"
#include "object.hpp"

using std::endl;
using std::cerr;
using std::stack;
using std::queue;
using std::string;
using std::unordered_map;

enum eventStatus {evnt, draw, quit, pop, push, nothing};

extern renderManager *renderer;

class eventManager{
public:
        eventManager();
        ALLEGRO_EVENT_QUEUE *accessEventQueue();
        int registerEvent(string, mouseTrigger &, objMemFnc);
        int registerEvent(string, keyTrigger &, objMemFnc);
        void removeCallback(const string);
        void removeCallback(const int);
        void checkKeyboardTriggers(const int);
        void checkMouseTriggers();
        int poll();

private:
        //stack<mouseTrigger> mouseListeners;
        //stack<keyTrigger> keyboardListners;

        queue<string> callbackQueue;
        unordered_map<string, objMemFnc> callbackLookup;

        ALLEGRO_EVENT_QUEUE *evntQueue;
};

#endif