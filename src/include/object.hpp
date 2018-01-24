#include <string>
#include <functional>
#include "callback.hpp"

using std::string;

class object;
typedef void (object::*objMemFnc)(callbackData data);

class object {
public:
        //void postEvent() const;
        virtual void recieveEvent();
        void runCallback(objMemFnc function, callbackData data) {std::invoke(this, function, data);};
private:

};
