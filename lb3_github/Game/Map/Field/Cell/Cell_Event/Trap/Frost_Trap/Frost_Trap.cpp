#include "Frost_Trap.h"


Frost_Trap::Frost_Trap(Player* other_hero) {
    this->trap_power =  1 + rand() % 8;
    this->hero = other_hero;
}

void Frost_Trap::interact() {
    if(hero->avoid_event() == 0) {
        int cur_health = hero->get_player_health();
        int cur_frost_armor = hero->get_player_frost_armor();
        if (cur_frost_armor < this->trap_power) {
            hero->set_player_health(cur_health - (this->trap_power - cur_frost_armor));
        }
    }
    this->notify();
}

std::string Frost_Trap::get_log() {
    return "Frost trap with power " + std::to_string(this->trap_power) + " worked.";
}