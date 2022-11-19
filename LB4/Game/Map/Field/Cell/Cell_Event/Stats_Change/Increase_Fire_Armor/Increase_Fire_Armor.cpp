#include "Increase_Fire_Armor.h"

Increase_Fire_Armor::Increase_Fire_Armor(Player* other_hero) {
    this->amount_of_change = 1 + rand() % 2;
    this->hero = other_hero;
}

void Increase_Fire_Armor::interact() {
    hero->set_player_fire_armor(hero->get_player_fire_armor() + this->amount_of_change);
    this->notify();
}

std::string Increase_Fire_Armor::get_log() {
    return "Player's fire armor now: " + std::to_string(this->hero->get_player_fire_armor()) + "\n";
}