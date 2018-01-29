#ifndef OBJECT_HPP
#define OBJECT_HPP

#include <string>
#include <vector>
#include <functional>
#include "callbackData.hpp"

using std::vector;
using std::string;
using std::invoke;

class object;
typedef void (object::*objMemFnc)(callbackData data);

class object {
public:
        //void postEvent() const;
        //virtual void recieveEvent();
        void runCallback(objMemFnc function, callbackData data) {invoke(function, this, data);};
private:
        vector<int> callbackHandles;
};

#endif
