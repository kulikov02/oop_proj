#include "Increase_Health.h"

Increase_Health::Increase_Health() {
    this->amount_of_change = 1 + rand() % 3;
}

void Increase_Health::interact(Player* hero, int player_x_coord, int player_y_coord) {
    hero->set_player_health(hero->get_player_health() + this->amount_of_change);
}