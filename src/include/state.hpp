#ifndef STATE_HPP
#define STATE_HPP

#include "object.hpp"

class state : public object{
public:
        virtual void draw()=0;
        virtual void switchedTo()=0;
        virtual void switchedFrom()=0;
private:

};

#endif