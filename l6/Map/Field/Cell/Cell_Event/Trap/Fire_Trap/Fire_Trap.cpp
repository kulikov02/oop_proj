#include "Fire_Trap.h"

Fire_Trap::Fire_Trap(Player* other_hero) {
    this->trap_power =  1 + rand() % 8;
    this->hero = other_hero;
}

void Fire_Trap::interact() {
    if(hero->avoid_event() == 0) {
        int cur_health = hero->get_player_health();
        int cur_fire_armor = hero->get_player_fire_armor();
        if (cur_fire_armor < this->trap_power) {
            hero->set_player_health(cur_health - (this->trap_power - cur_fire_armor));
        }
    }
    this->notify();
}

std::string Fire_Trap::get_log() {
    return "Fire trap with power " + std::to_string(this->trap_power) + " worked.";
}

std::string Fire_Trap::get_str() {
    return "FIT";
}