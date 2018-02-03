#ifndef RENDERMANAGER_HPP
#define RENDERMANAGER_HPP

#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"
#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro_font.h"
#include "allegro5/mouse.h"

class eventManager;

extern eventManager *evntMngr;

const int windowYRes = 720;
const int windowXRes = 1280;

class renderManager{
public:
    renderManager();
    void startFpsRegulator();
    void stopFpsRegulator();
    double finishFrame();
    void drawFPSInfo();
    void confirmResize();
    bool checkTimer(const ALLEGRO_TIMER *);
    double getFPS() const {return fps;};
private:
    ALLEGRO_DISPLAY *display;
    //ALLEGRO_BITMAP *icon;
    ALLEGRO_FONT *font;
    ALLEGRO_TIMER *frameTimer;

    int fps;
    int fps_accum;
    double fps_time;
    double lastFrameT;
};

#endif
