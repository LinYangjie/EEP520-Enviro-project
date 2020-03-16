#ifndef __ASSIGNMENT_AGENT__H
#define __ASSIGNMENT_AGENT__H 

#include "enviro.h"

/*
assignemtController is to control the boat-like agent to move toward the statue, and reduce hp when hit by bullet or missile.
*/

using namespace enviro;

class assignmentController : public Process, public AgentInterface {

    public:
    assignmentController() : Process(), AgentInterface() {}

    void init() {
        watch("button_click",[&](Event &e) {
            game_start = true;
        });
        label("Assignment", -30, 20);
        notice_collisions_with("Bullet", [&](Event &e) {
            remove_agent(e.value()["id"]);
            monster_lifes -= 1;
        });
        notice_collisions_with("Fragment", [&](Event &e) {
            remove_agent(e.value()["id"]);
            monster_lifes -= 0.2;
        });
    }
    void start() {}
    void update() {
        if (monster_lifes < 0) {
            remove_agent(id());
        }
        if (game_start) {
            move_toward(-700,0,70,25);
        }
    }
    void stop() {}

    double monster_lifes = 10;
    double delay;
    bool game_start = false;

};

class assignment : public Agent {
    public:
    assignment(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    assignmentController c;
};

DECLARE_INTERFACE(assignment)

#endif