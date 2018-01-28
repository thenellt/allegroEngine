#include "include/renderManager.hpp"

renderManager::renderManager(){
        frameTimer = al_create_timer(1.0 / 60);

        display = al_create_display(windowXRes, windowYRes);
        al_set_window_title(display, "Allegro Engine Test");

        ALLEGRO_EVENT_QUEUE *eventQueue = evntMngr->accessEventQueue();
        al_register_event_source(eventQueue, al_get_display_event_source(display));
        al_register_event_source(eventQueue, al_get_timer_event_source(frameTimer));
}

void renderManager::startFpsRegulator(){
        al_start_timer(frameTimer);
}

void renderManager::stopFpsRegulator(){
        al_stop_timer(frameTimer);
}

void renderManager::confirmResize(){
        al_acknowledge_resize(display);
}