#ifndef __VIRUS_AGENT__H
#define __VIRUS_AGENT__H 

#include "enviro.h"

using namespace enviro;

/*
VirusController is to control virus to move toward the statue, and reduce hp when hit by bullet or missile.
*/

class virusController : public Process, public AgentInterface {

    public:
    virusController() : Process(), AgentInterface() {}

    void init() {

        watch("button_click",[&](Event &e){
            game_start = true;
        });

        notice_collisions_with("Bullet", [&](Event &e) {
            remove_agent(e.value()["id"]);
            monster_lifes -= 1;
        });
        notice_collisions_with("Fragment", [&](Event &e) {
            remove_agent(e.value()["id"]);
            monster_lifes -= 0.5;
        });
        label("COVID-19", -30 , 5);
    }
    void start() {}
    void update() {
        if (game_start) {
            omni_move_toward(-700,0,0.03);
        }
        if (monster_lifes < 0) {
            remove_agent(id());
        }
    }
    void stop() {}
    const int fmax = 100;
    double monster_lifes = 3;
    double counter ;
    bool game_start = false;

};

class virus : public Agent {
    public:
    virus(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    virusController c;
};

DECLARE_INTERFACE(virus)

#endif