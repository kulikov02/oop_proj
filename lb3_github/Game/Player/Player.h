#ifndef OOP_PROJECT_PLAYER_H
#define OOP_PROJECT_PLAYER_H

#include "../Logs/Observed_Obj.h"
#include <iostream>

class Player:public Observed_Obj {
    int player_health;
    int player_frost_armor;
    int player_fire_armor;
    int agility;

public:
    explicit Player(int health = 15, int frost_armor = 0,int fire_armor = 0, int agility = 0);

    void set_player_frost_armor(int new_frost_armor);

    void set_player_fire_armor(int new_fire_armor);

    void set_player_health(int new_health);

    void set_player_agility(int new_agility);

    int get_player_frost_armor();

    int get_player_fire_armor();

    int get_player_health();

    int get_player_agility();

    int avoid_event();

    std::string get_log() override;

};


#endif //OOP_PROJECT_PLAYER_H
