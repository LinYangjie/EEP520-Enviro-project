#ifndef __WHO_AGENT__H
#define __WHO_AGENT__H 

#include "enviro.h"

using namespace enviro;

class WHOController : public Process, public AgentInterface {

    public:
    WHOController() : Process(), AgentInterface() {}

    void init() {
        label(status, -200, -50);
    }
    void start() {}
    void update() {
        if (sensor_value(0) < 400) {
            label("Tedros Adhanom Ghebreyesus: Pandemic start!",0,-50);
            emit(Event("Warning"));
            
        }

    }
    void stop() {}
    std::string status = "Tedros Adhanom Ghebreyesus: Unnecessarily interfere with international travel and trade!!";
    const json GOVERNMENT = { 
                   {"fill", "purple"}, 
                   {"stroke", "#888"}, 
                   {"stroke-width", "5px"},
                   {"stroke-opacity", "0.35"}
                };

};

class WHO : public Agent {
    public:
    WHO(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    WHOController c;
};

DECLARE_INTERFACE(WHO)

#endif