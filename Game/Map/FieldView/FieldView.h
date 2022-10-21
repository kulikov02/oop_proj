#ifndef OOP_PROJECT_FIELDVIEW_H
#define OOP_PROJECT_FIELDVIEW_H

#include "../Field/Field.h"

class FieldView {
    Field *game_field;
    char **output_arr;
    int output_arr_width;
    int output_arr_height;

public:
    explicit FieldView(Field *other_field);

    void show_field();

    void show_stats();

    Field* get_field();

    void player_dead();

    void player_won();

    ~FieldView();
};


#endif //OOP_PROJECT_FIELDVIEW_H
