#ifndef OOP_PROJECT_PLAYER_POS_RULE_H
#define OOP_PROJECT_PLAYER_POS_RULE_H

#include "../../Map/Field/Field.h"

template<int n>
class Player_Pos_Rule {
public:
    void set_player_pos(Field *field) {
        if (n == 0) {
            return;
        }
        if (n == 1) {
            field->set_current_player_cell(&field->get_field()[field->get_width() - 1][0]);
            field->get_field()[field->get_width() - 1][0].set_cell_type(Start);
            field->get_field()[field->get_width() - 1][0].player_on_cell(field->get_hero(), field->get_width() - 1, 0);
            field->get_field()[0][0].set_cell_type(Free);
            field->get_field()[0][0].player_out_of_cell();
            field->set_player_x_coord(field->get_width() - 1);
        }
    }
};


#endif //OOP_PROJECT_PLAYER_POS_RULE_H
