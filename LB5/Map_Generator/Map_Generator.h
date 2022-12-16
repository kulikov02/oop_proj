#ifndef OOP_PROJECT_MAP_GENERATOR_H
#define OOP_PROJECT_MAP_GENERATOR_H

#include<iostream>
#include "Rules/Difficulty_Rule.h"
#include "Rules/Events_Distribution_Rule.h"
#include "Rules/Exit_Not_Shown_Rule.h"
#include "Rules/Exit_Pos_Rule.h"
#include "Rules/Player_Pos_Rule.h"
#include "Rules/Walls_Rule.h"
#include "../Map/Field/Field.h"
#include "../Map/Field_Event_filler/Field_Event_Filler.h"


template<int... Args>
class Map_Generator {
    Field *game_field = nullptr;
public:
    Map_Generator(int height, int width) {
        int rules_arr[]{int((Args))...};
        int n = sizeof...(Args);
        this->game_field = new Field(height, width);
        auto field_event_filler_obj = new Field_Event_Filler(game_field);
        field_event_filler_obj->fill_the_field();


        for(int i = 0; i < n;i++) {
            if (i == 0) {
                if(rules_arr[i] == 0) {
                    Difficulty_Rule<0> diff_rule;
                    diff_rule.set_difficulty(game_field);
                }
                else if(rules_arr[i] == 1) {
                    Difficulty_Rule<1> diff_rule;
                    diff_rule.set_difficulty(game_field);
                }

            }
            if (i == 1) {
                if(rules_arr[i] == 0) {
                    Events_Distribution_Rule<0> event_distr_rule;
                    event_distr_rule.set_event_distribution(game_field);
                }
                else if(rules_arr[i] == 1) {
                    Events_Distribution_Rule<1> event_distr_rule;
                    event_distr_rule.set_event_distribution(game_field);
                }

            }

            if (i == 2) {
                if(rules_arr[i] == 0){
                    Exit_Pos_Rule<0> exit_pos_rule;
                    exit_pos_rule.set_exit_pos(game_field);

                }
                else if(rules_arr[i] == 1){
                    Exit_Pos_Rule<1> exit_pos_rule;
                    exit_pos_rule.set_exit_pos(game_field);
                }

            }
            if (i == 3) {
                if(rules_arr[i] == 0){
                    Exit_Not_Shown_Rule<0> exit_shown_rule;
                    exit_shown_rule.set_exit_visibility(game_field);
                }
                else if(rules_arr[i] == 1){
                    Exit_Not_Shown_Rule<1> exit_shown_rule;
                    exit_shown_rule.set_exit_visibility(game_field);

                }

            }
            if (i == 4) {
                if(rules_arr[i] == 0){
                    Player_Pos_Rule<0> player_pos_rule;
                    player_pos_rule.set_player_pos(game_field);
                }
                else if(rules_arr[i] == 1){
                    Player_Pos_Rule<1> player_pos_rule;
                    player_pos_rule.set_player_pos(game_field);
                }

            }
            if (i == 5) {
                if(rules_arr[i] == 0){
                    Walls_Rule<0> walls_rule;
                    walls_rule.place_walls(game_field);
                }
                else if(rules_arr[i] == 1){
                    Walls_Rule<1> walls_rule;
                    walls_rule.place_walls(game_field);
                }

            }
        }

        if(n < 6){
            Walls_Rule<0> walls_rule;
            walls_rule.place_walls(game_field);
        }
        if(n < 5){
            Player_Pos_Rule<0> player_pos_rule;
            player_pos_rule.set_player_pos(game_field);

        }
        if(n < 4){
            Exit_Pos_Rule<0> exit_pos_rule;
            exit_pos_rule.set_exit_pos(game_field);
        }
        if(n < 3){
            Exit_Not_Shown_Rule<0> exit_shown_rule;
            exit_shown_rule.set_exit_visibility(game_field);
        }
        if(n < 2){
            Events_Distribution_Rule<0> event_distr_rule;
            event_distr_rule.set_event_distribution(game_field);
        }
        if(n < 1){
            Difficulty_Rule<0> diff_rule;
            diff_rule.set_difficulty(game_field);
        }

    }


    Field *get_game_field() {
        return this->game_field;
    }

};


#endif //OOP_PROJECT_MAP_GENERATOR_H
