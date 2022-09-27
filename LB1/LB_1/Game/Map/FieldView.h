#ifndef OOP_PROJECT_FIELDVIEW_H
#define OOP_PROJECT_FIELDVIEW_H

#include "Field/Field.h"


class FieldView {
    Field *game_field;
    char **output_arr;
    int output_arr_width;
    int output_arr_height;

public:
    explicit FieldView(Field *other_field);

    void show_field();

    Field* get_field();

    ~FieldView();
};


#endif //OOP_PROJECT_FIELDVIEW_H
