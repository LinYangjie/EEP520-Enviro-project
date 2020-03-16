#ifndef __FRAGMENT_AGENT__H
#define __FRAGMENT_AGENT__H 

#include "enviro.h"

/*
fragmentController is to control the fragment to randomly goint toward everywhere and  then disappear after a while.
*/

using namespace enviro;

class fragmentController : public Process, public AgentInterface {

    public:
    fragmentController() : Process(), AgentInterface() {}

    void init() {
        omni_apply_force(-50 + rand()%100, -50 + rand()%100);
    }
    void start() {}
    void update() {
        if (counter++ > 20) {
            remove_agent(id());
        }
    }
    void stop() {}

    double counter;

};

class fragment : public Agent {
    public:
    fragment(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    fragmentController c;
};

DECLARE_INTERFACE(fragment)

#endif