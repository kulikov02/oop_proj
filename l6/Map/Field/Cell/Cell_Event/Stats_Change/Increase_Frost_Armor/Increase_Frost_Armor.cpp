#include "Increase_Frost_Armor.h"

Increase_Frost_Armor::Increase_Frost_Armor(Player* other_hero) {
    this->amount_of_change = this->amount_of_change = 1 + rand() % 2;
    this->hero = other_hero;
}

void Increase_Frost_Armor::interact() {
    hero->set_player_frost_armor(hero->get_player_frost_armor() + this->amount_of_change);
    this->notify();
}

std::string Increase_Frost_Armor::get_log() {
    return "Player's frost armor now: " + std::to_string(this->hero->get_player_frost_armor()) + "\n";
}

std::string Increase_Frost_Armor::get_str() {
    return "IFR";
}