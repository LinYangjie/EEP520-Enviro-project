#ifndef __FINAL_PROJECT__H
#define __FINAL_PROJECT_AGENT__H 

#include "enviro.h"
/*
final_projectController is to control the biggest agent to move toward the statue, and reduce hp when hit by bullet or missile.
*/

using namespace enviro;

class final_projectController : public Process, public AgentInterface {

    public:
    final_projectController() : Process(), AgentInterface() {}

    void init() {
        
        watch("button_click",[&](Event &e) {
            game_start = true;
        });

        label("This is final project please turn in before 3/18/2020", -150, -30);
        
        notice_collisions_with("Bullet", [&](Event &e) {
            remove_agent(e.value()["id"]);
            monster_lifes -= 1;
        });
        notice_collisions_with("Fragment", [&](Event &e) {
            remove_agent(e.value()["id"]);
            monster_lifes -= 0.5;
        });

    }
    void start() {}
    void update() {
        if (monster_lifes < 0) {
            remove_agent(id());
        }
        if (game_start) {
            omni_move_toward(-700, 0, 0.002);
        }
    }
    void stop() {} 
    double monster_lifes = 50;
    bool game_start = false;
};

class final_project : public Agent {
    public:
    final_project(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    final_projectController c;
};

DECLARE_INTERFACE(final_project)

#endif