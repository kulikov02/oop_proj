#include "Increase_Fire_Armor.h"

Increase_Fire_Armor::Increase_Fire_Armor() {
    this->amount_of_change = 1 + rand() % 2;
}

void Increase_Fire_Armor::interact(Player* hero, int player_x_coord, int player_y_coord) {
    hero->set_player_fire_armor(hero->get_player_fire_armor() + this->amount_of_change);
}