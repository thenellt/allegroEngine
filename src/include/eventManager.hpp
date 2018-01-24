#pragma once

#include <unordered_map>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include "allegro5/allegro.h"
#include "event.hpp"
#include "trigger.hpp"
#include "callback.hpp"
#include "object.hpp"

using std::stack;
using std::queue;
using std::string;
using std::unordered_map;

enum eventStatus {evnt, draw, quit};

class eventManager{
public:
        //int registerEvent(trigger, string, callback *);
        void removeCallback(const string);
        void removeCallback(const int);

private:
        //mouse triggers
        //stack<mouseTrigger> mouseListeners;
        //stack<keyTrigger> keyboardListners;

        queue<string> callbackQueue;
        unordered_map<string, objMemFnc> callbackLookup;

        ALLEGRO_TIMER *timer;
        ALLEGRO_EVENT_QUEUE *evntQueue;
};
