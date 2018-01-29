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
#include "object.hpp"
#include "callbackData.hpp"
#include "callback.hpp"

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
        int registerEvent(object *, mouseTrigger, objMemFnc);
        int registerEvent(object *, keyTrigger, objMemFnc);
        void removeCallback(const int);
        void checkMouseMoveTriggers(int, int);
        void checkMouseButtonTriggers(int, int, bool);
        void checkKeyboardTriggers(int, bool);
        int poll();

private:
        stack<mouseTrigger> mousePosListners;
        stack<mouseTrigger> mouseButtonListeners;
        stack<keyTrigger> keyboardListners;

        unordered_map<int, callback> callbackLookup;

        ALLEGRO_EVENT_QUEUE *evntQueue;
        int idCounter;
};

#endif
