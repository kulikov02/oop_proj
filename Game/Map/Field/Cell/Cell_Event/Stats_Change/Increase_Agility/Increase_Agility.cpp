#include "Increase_Agility.h"

Increase_Agility::Increase_Agility() {
    this->amount_of_change = 1 + rand() % 2;
}

void Increase_Agility::interact(Player* hero, int player_x_coord, int player_y_coord) {
    hero->set_player_agility(hero->get_player_agility() + this->amount_of_change);
}