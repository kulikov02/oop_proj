#include "Increase_Frost_Armor.h"

Increase_Frost_Armor::Increase_Frost_Armor() {
    this->amount_of_change = this->amount_of_change = 1 + rand() % 2;
}

void Increase_Frost_Armor::interact(Player* hero, int player_x_coord, int player_y_coord) {
    hero->set_player_frost_armor(hero->get_player_frost_armor() + this->amount_of_change);
}