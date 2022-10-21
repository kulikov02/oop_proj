#include "Fire_Trap.h"

Fire_Trap::Fire_Trap() {
    this->trap_power =  1 + rand() % 8;
}

void Fire_Trap::interact(Player* hero, int player_x_coord, int player_y_coord) {
    if(hero->avoid_event() == 0) {
        int cur_health = hero->get_player_health();
        int cur_fire_armor = hero->get_player_fire_armor();
        if (cur_fire_armor < this->trap_power) {
            hero->set_player_health(cur_health - (this->trap_power - cur_fire_armor));
        }
    }
}