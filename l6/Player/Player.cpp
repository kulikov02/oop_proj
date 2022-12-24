#include "Player.h"

Player::Player(int health, int frost_armor, int fire_armor, int agility) :
        player_health(health),
        player_frost_armor(frost_armor), player_fire_armor(fire_armor),
        agility(agility) {
}

void Player::set_player_frost_armor(int new_frost_armor) {
    this->player_frost_armor = new_frost_armor;
    this->notify();
}

void Player::set_player_fire_armor(int new_fire_armor) {
    this->player_fire_armor = new_fire_armor;
    this->notify();
}

void Player::set_player_health(int new_health) {
    this->player_health = new_health;
    this->notify();
}

void Player::set_player_agility(int new_agility) {
    this->agility = new_agility;
    this->notify();
}

int Player::get_player_agility() {
    return this->agility;
}

int Player::get_player_health() {
    return this->player_health;
}

int Player::get_player_frost_armor() {
    return this->player_frost_armor;
}

int Player::get_player_fire_armor() {
    return this->player_fire_armor;
}

int Player::avoid_event() {
    if (((rand() % 10) + this->agility) > 8) {
        this->notify();
        return 1;
    } else {
        return 0;
    }
}

std::string Player::get_log() {
    return "Health: " + std::to_string(player_health) + "\nFrost armor: " + std::to_string(player_frost_armor) +
           "\nFire armor: " + std::to_string(player_fire_armor) + "\nAgility: " + std::to_string(agility) + "\n";
}






