#ifndef CALLBACK_HPP
#define CALLBACK_HPP

#include <string>
#include "callbackData.hpp"

class object;
typedef void (object::*objMemFnc)(callbackData data);

struct callback{
        callback() {};
        callback(object *o, objMemFnc f) : owner(o), func(f) {};

        object *owner;
        objMemFnc func;
};

#endif
