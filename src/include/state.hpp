#ifndef STATE_HPP
#define STATE_HPP

#include "object.hpp"

class state : public object{
public:
        virtual void draw()=0;
        virtual void switchedTo(){};
        virtual void switchedFrom(){};
        bool isBlocking() {return drawType == DrawStatus::Blocking;};
private:
        enum DrawStatus {Normal, Blocking, None};
        int drawType;
};

#endif