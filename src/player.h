#ifndef __PLAYER_AGENT__H
#define __PLAYER_AGENT__H 

#include "enviro.h"

using namespace enviro;

/*
playerController is to control the agent by keyboard including moving agent and having shooting different weapons.  
*/

class playerController : public Process, public AgentInterface {

    public:
    playerController() : Process(), AgentInterface(), f(0), tau(0), firing(false) {}

    void init() {
        label("PLAYER", -20, -30);
        watch("button_click",[&](Event &e) {
            game_start = true;
        });

        watch("keydown", [&](Event &e) {
            if (game_start) {
                auto k = e.value()["key"].get<std::string>();
                if ( k == " " && !firing ) {
                    if (current_weapon == BULLET) {
                        Agent& bullet = add_agent("Bullet", x() + 17*cos(angle()), y() + 17*sin(angle()), angle(), BULLET);    
                        bullet.apply_force(60,0);
                        firing = true;
                    }
                    else if (current_weapon == MISSILE) {
                        Agent& missile = add_agent("Missile", x() + 17*cos(angle()), y() + 17*sin(angle()), angle(), MISSILE);    
                        missile.apply_force(70,0);
                        firing = true;
                    }
                } 
                else if ( k == "1" ) {
                        current_weapon = BULLET;     
                }
                else if ( k == "2" ) {
                        current_weapon = MISSILE;     
                }
                else if ( k == "w" ) {
                    f = magnitude;              
                } 
                else if ( k == "s" ) {
                    f = -magnitude;  
                } 
                else if ( k == "a" ) {
                    tau = -magnitude;
                } 
                else if ( k == "d" ) {
                    tau = magnitude;
                }
            }    
        });        
        watch("keyup", [&](Event &e) {
            if (game_start) {
                auto k = e.value()["key"].get<std::string>();
                if ( k == " " ) {
                    firing = false;
                } 
                else if ( k == "w" || k == "s" ) {
                    f = 0;               
                } 
                else if ( k == "a" ) {
                    tau = 0;
                } 
                else if ( k == "d" ) {
                    tau = 0;
                }
            }   
        });
        notice_collisions_with("Assignment", [&](Event &e) {  //check if hit by assignment, return to the start point
            teleport(-700, -200, 0);
        });
        notice_collisions_with("Virus", [&](Event &e) { //check if hit by virus, return to the start point
            teleport(-700, -200, 0);
        });
        notice_collisions_with("Final_Project", [&](Event &e) { //check if hit by final_project, return to the start point
            teleport(-700, -200, 0);
        });
    }
    void start() {}
    void update() {
        apply_force(f,tau);
    }
    void stop() {}
    double f, tau;
    double const magnitude = 200;
    bool firing;
    bool game_start = false;
    const json BULLET = { 
                   {"fill", "green"}, 
                   {"stroke", "#888"}, 
                   {"stroke-width", "5px"},
                   {"stroke-opacity", "0.25"}
                };
    const json MISSILE = {
                   {"fill", "gray"}, 
                   {"stroke", "#888"}, 
                   {"stroke-width", "5px"},
                   {"stroke-opacity", "0.35"}
                };          
    json current_weapon;
};

class player : public Agent {
    public:
    player(json spec, World& world) : Agent(spec, world) {
        add_process(c);
    }
    private:
    playerController c;
};

DECLARE_INTERFACE(player)

#endif