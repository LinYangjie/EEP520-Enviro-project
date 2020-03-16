#ifndef __MISSLE_AGENT__H
#define __MISSLE_AGENT__H 

#include "enviro.h"

using namespace enviro;

/*
missileController is to control missile to shot by the player, and explode after a while, which turn into fragments. 
*/

class missleController : public Process, public AgentInterface {

    public:
    missleController() : Process(), AgentInterface() {}

    void init() {
    }
    void start() {}
    void update() {
        if ( counter++ > 40 ) {
            for ( double theta = 0; theta < 2*M_PI; theta += M_PI/8 ) {
                Agent& v = add_agent("Fragment", x() + 10*cos(theta), y() + 10*sin(theta), 0, FRAGMENT);
            }
            remove_agent(id());
        }
    }
    void stop() {}

    double counter;
    const json FRAGMENT = { 
                   {"fill", "blue"}, 
                   {"stroke", "#888"}, 
                   {"stroke-width", "5px"},
                   {"stroke-opacity", "0.35"}
                };

};

class missle : public Agent {
    public:
    missle(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    missleController c;
};

DECLARE_INTERFACE(missle)

#endif