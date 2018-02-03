#include "include/renderManager.hpp"
#include "include/eventManager.hpp"

renderManager::renderManager(){
        frameTimer = al_create_timer(1.0 / 60);
        lastFrameT = al_get_time();;

        display = al_create_display(windowXRes, windowYRes);
        font = al_load_font("fixed_font.tga", 0, 0);
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

double renderManager::finishFrame(){
        al_flip_display();
        fps_accum++;
        if (lastFrameT - fps_time >= 1) {
                fps = fps_accum;
                fps_accum = 0;
                fps_time = lastFrameT;
        }

        lastFrameT = al_get_time();
        return fps;
}

void renderManager::drawFPSInfo(){
        al_draw_filled_rounded_rectangle(windowXRes - 104, 10, windowXRes - 4, 36, 8, 8, al_map_rgba(140, 140, 140, 200));
        al_draw_textf(font, al_map_rgb(255, 255, 255), windowXRes - 54, 14, ALLEGRO_ALIGN_CENTRE, "FPS: %d", fps);
}

void renderManager::confirmResize(){
        al_acknowledge_resize(display);
}

bool renderManager::checkTimer(const ALLEGRO_TIMER *eventSource){
        return eventSource == frameTimer;
}
