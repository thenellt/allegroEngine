#pragma once

#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro_font.h"
#include "allegro5/mouse.h"

class renderManager{
public:

private:
    ALLEGRO_DISPLAY *display;
    ALLEGRO_BITMAP *icon;
    ALLEGRO_FONT *font;

    int fps;
    int fps_accum;
    double fps_time;

};
