#include <vector>
#include "event.hpp"

class object {
public:
    void postEvent() const;
    virtual void recieveEvent();
private:
    std::vector<event *> eventQueue;
};