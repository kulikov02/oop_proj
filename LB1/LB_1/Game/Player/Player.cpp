#include "Player.h"

Player::Player(int health, int damage, int agility) :
        player_health(health),
        player_damage(damage),
        agility(agility) {
}

void Player::set_player_damage(int new_damage) {
    this->player_damage = new_damage;
}

void Player::set_player_health(int new_health) {
    this->player_health = new_health;
}

int Player::avoid_event() {
    if (((rand() % 11) + this->agility) > 7) {
        return 1;
    } else {
        return 0;
    }
}

void Player::set_player_agility(int new_agility) {
    this->agility = new_agility;
}




