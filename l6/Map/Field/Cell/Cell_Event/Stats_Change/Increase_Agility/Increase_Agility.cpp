#include "Increase_Agility.h"

Increase_Agility::Increase_Agility(Player* other_hero) {
    this->amount_of_change = 1 + rand() % 2;
    this->hero = other_hero;
}

void Increase_Agility::interact() {
    hero->set_player_agility(hero->get_player_agility() + this->amount_of_change);
    this->notify();
}

std::string Increase_Agility::get_log() {
    return "Player's agility now: " + std::to_string(this->hero->get_player_agility()) + "\n";
}

std::string Increase_Agility::get_str() {
    return "IA";
}