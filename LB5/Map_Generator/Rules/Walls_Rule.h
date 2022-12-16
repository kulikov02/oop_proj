#ifndef OOP_PROJECT_WALLS_RULE_H
#define OOP_PROJECT_WALLS_RULE_H

#include "../../Map/Field/Field.h"

template<int n>
class Walls_Rule {
public:
    Field *place_walls(Field* field) {
        Cell **map = field->get_field();
        if (n == 0) {
            for (int j = 1; j < field->get_height(); j += 2) {
                for (int i = 1; i < field->get_width() - 1; i += 2) {
                    map[i][j].set_cell_type(Wall);
                }
            }
        }
        if (n == 1) {
            int j = 1;
            for (int i = 1; i < field->get_width() - 1; i++) {
                map[i][j].set_cell_type(Wall);
                j += 1;
            }
            j = field->get_height() - 2;
            for (int i = 1; i < field->get_width() - 1; i++) {
                map[i][j].set_cell_type(Wall);
                j -= 1;
            }
        }
        return field;
    }
};


#endif //OOP_PROJECT_WALLS_RULE_H
