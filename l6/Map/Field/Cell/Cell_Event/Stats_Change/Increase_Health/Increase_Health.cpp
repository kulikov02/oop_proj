#include "Increase_Health.h"

Increase_Health::Increase_Health(Player* other_hero) {
    this->amount_of_change = 1 + rand() % 3;
    this->hero = other_hero;
}

void Increase_Health::interact() {
    hero->set_player_health(hero->get_player_health() + this->amount_of_change);
    this->notify();
}

std::string Increase_Health::get_log() {
    return "Player's health now: " + std::to_string(this->hero->get_player_health()) + "\n";
}

std::string Increase_Health::get_str() {
    return "IH";
}