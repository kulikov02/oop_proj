#ifndef OOP_PROJECT_DIFFICULTY_RULE_H
#define OOP_PROJECT_DIFFICULTY_RULE_H


#include "../../Map/Field/Field.h"

template <int n>
class Difficulty_Rule {
public:
    void set_difficulty(Field* field){
        if(n == 0){
            return;
        }
        if(n == 1){
            field->get_hero()->set_player_health(field->get_hero()->get_player_health() + 5);
            field->get_hero()->set_player_agility(field->get_hero()->get_player_agility() + 1);
        }
    }

};


#endif //OOP_PROJECT_DIFFICULTY_RULE_H
