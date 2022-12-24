#ifndef OOP_PROJECT_EXIT_NOT_SHOWN_RULE_H
#define OOP_PROJECT_EXIT_NOT_SHOWN_RULE_H


#include "../../Map/Field/Field.h"
#include"../../Map/Field/Cell/Cell_Event/Map_Change/Show_Exit/Show_Exit.h"
template<int n>
class Exit_Not_Shown_Rule {
public:
    void set_exit_visibility(Field* field){
        if(n == 0){
            return;
        }
        if(n == 1){
            for(int i = 0;i < field->get_width();i++){
                for(int j = 0;j < field->get_height();j++){
                    if (field->get_field()[i][j].get_cell_type() == Exit ) {
                        field->get_field()[i][j].set_exit_is_shown_flag(-1);
                    }

                }
            }
        }
    }


};


#endif //OOP_PROJECT_EXIT_NOT_SHOWN_RULE_H
