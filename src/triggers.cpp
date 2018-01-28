#include "include/triggers.hpp"

void trigger::setID(int newID){
        id = newID;
}

bool trigger::checkID(int id){
        return this->id == id;
}

mouseTrigger::mouseTrigger(){
        type = mTrigType::any;
}

mouseTrigger::mouseTrigger(int button){
        type = mTrigType::click;
        this->button  = button;
}

mouseTrigger::mouseTrigger(int button, rect region){
        type = mTrigType::clickRegion;
        this->button = button;
        bounds = region;
}

mouseTrigger::mouseTrigger(rect region){
        type = mTrigType::region;
        bounds = region;
}

bool mouseTrigger::check(int button, int x, int y){
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
        }
}

keyTrigger::keyTrigger(){
        type = kTrigType::any;
}

keyTrigger::keyTrigger(int key){
        type = kTrigType::single;
        this->key = key;
}

keyTrigger::keyTrigger(vector<int> keys){
        type = kTrigType::many;
        this->keys = keys;
}

bool keyTrigger::check(int input){
        
}