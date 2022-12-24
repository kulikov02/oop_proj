#ifndef OOP_PROJECT_EXIT_POS_RULE_H
#define OOP_PROJECT_EXIT_POS_RULE_H

#include "../../Map/Field/Field.h"

template<int n>
class Exit_Pos_Rule {
public:
    void set_exit_pos(Field* field){
        if(n == 0){
            return;
        }
        if(n == 1){
            field->get_field()[field->get_width() - 1][field->get_height() - 1].set_cell_type(Free);
            field->get_field()[0][field->get_height() - 1].set_cell_type(Exit);
        }
    }
};


#endif //OOP_PROJECT_EXIT_POS_RULE_H
