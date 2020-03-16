#ifndef __STATUE_AGENT__H
#define __STATUE_AGENT__H 

#include "enviro.h"
/*
StatueController is checking if it is hit by "Final_Project", "Assignment", "Virus", if it does, statue agent will disappear. 
*/

using namespace enviro;

class statueController : public Process, public AgentInterface {

    public:
    statueController() : Process(), AgentInterface() {}

    void init() {
        notice_collisions_with("Final_Project", [&](Event &e) {
            remove_agent(id());
        });
        notice_collisions_with("Assignment", [&](Event &e) {
            remove_agent(id());
        });
        notice_collisions_with("Virus", [&](Event &e) {
            remove_agent(id());
        });
    }
    void start() {}
    void update() {}
    void stop() {}

};

class statue : public Agent {
    public:
    statue(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    statueController c;
};

DECLARE_INTERFACE(statue)

#endif