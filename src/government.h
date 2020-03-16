#ifndef __GOVERNMENT_AGENT__H
#define __GOVERNMENT_AGENT__H 

#include "enviro.h"

/*
governmentController is to control the governemt agent watch on when the event happen and react once it happen.
*/

using namespace enviro;

class governmentController : public Process, public AgentInterface {

    public:
    governmentController() : Process(), AgentInterface() {}

    void init() {
        label("Government: Don't Worry!",-50, -20);
        watch("button_click",[&](Event &e) {
            game_start = true;
        });
        watch("Warning",[this](Event e) {
            if (game_start) {
                move_toward(-600,0,200,100);
                label("Government: We have to shut down facilites!", -30, -30);
            }
        });
    }
    void start() {}
    void update() {}
    void stop() {}
    bool game_start = false;

};

class government : public Agent {
    public:
    government(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    governmentController c;
};

DECLARE_INTERFACE(government)

#endif