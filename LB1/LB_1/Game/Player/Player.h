#ifndef OOP_PROJECT_PLAYER_H
#define OOP_PROJECT_PLAYER_H


#include <iostream>

class Player {
    int player_health;
    int player_damage;
    int agility;

public:
    explicit Player(int health = 10, int damage = 1, int agility = 1);

    void set_player_damage(int new_damage);

    void set_player_health(int new_health);

    void set_player_agility(int new_agility);

    int avoid_event();

};


#endif //OOP_PROJECT_PLAYER_H
