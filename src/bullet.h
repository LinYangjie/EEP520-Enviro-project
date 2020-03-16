#ifndef __BULLET_AGENT__H
#define __BULLET_AGENT__H 

#include "enviro.h"

/*
bulletController is to control bullet to disappear after a while.
*/

using namespace enviro;

class bulletController : public Process, public AgentInterface {

    public:
    bulletController() : Process(), AgentInterface() {}

    void init() {}
    void start() {}
    void update() {
        if ( counter++ > 20 ) {
            remove_agent(id());
        }
    }
    void stop() {}
    
    double counter;
};

class bullet : public Agent {
    public:
    bullet(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    bulletController c;
};

DECLARE_INTERFACE(bullet)

#endif