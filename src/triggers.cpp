#include "include/triggers.hpp"

void trigger::setID(int newID){
        id = newID;
}

bool trigger::checkID(int id){
        return this->id == id;
}

mouseTrigger::mouseTrigger(bool down) : trigger(down){
        type = mTrigType::any;
}

mouseTrigger::mouseTrigger(int button, bool down) : trigger(down){
        type = mTrigType::click;
        this->button  = button;
}

mouseTrigger::mouseTrigger(int button, rect region, bool down) : trigger(down){
        type = mTrigType::clickRegion;
        this->button = button;
        bounds = region;
}

mouseTrigger::mouseTrigger(rect region, bool down) : trigger(down){
        type = mTrigType::region;
        bounds = region;
}

bool mouseTrigger::check(int button, int x, int y, bool down){
        if(isDown != down){
                return false;
        } else {
                switch(type){
                case any:
                        return true;
                case click:
                        return this->button == button;
                case clickRegion:
                        if(this->button == button)
                                return bounds.contains(x, y);
                        else
                                return false;
                case region:
                        return bounds.contains(x, y);
                default:
                        return false;
                }
        }
}

keyTrigger::keyTrigger(bool down) : trigger(down){
        type = kTrigType::kany;
}

keyTrigger::keyTrigger(int key, bool down) : trigger(down){
        type = kTrigType::single;
        this->key = key;
}

keyTrigger::keyTrigger(vector<int> keys, bool down) : trigger(down){
        type = kTrigType::many;
        this->keys = keys;
}

bool keyTrigger::check(int input, bool down){
        if(isDown != down){
                return false;
        } else {
                switch(type){
                case kany:
                        return true;
                case single:
                        return key == input;
                case many:
                        for(const int &k : keys)
                                if(k == input)
                                        return true;
                        return false;
                default:
                        return false;
                }
        }
}
