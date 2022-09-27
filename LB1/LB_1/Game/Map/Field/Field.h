#ifndef OOP_PROJECT_FIELD_H
#define OOP_PROJECT_FIELD_H

#include "Cell/Cell.h"
#include "../../Player/Player.h"

#define MAP_SIZE 10

class Field {
    Cell **map;
    int field_height;
    int field_width;
    int player_x_coord;
    int player_y_coord;
    Player *hero;
    Cell *current_player_cell;
public:

    Field(int height = MAP_SIZE, int width = MAP_SIZE, Player *hero = new Player(), int player_x_coord = 0,
          int player_y_coord = 0);

    Field(const Field &other_field);

    Field(Field &&other_field);

    Field &operator=(const Field &other_field);

    Field &operator=(Field &&other);

    Cell **get_field();

    int get_height();

    int get_width();

    void move_player(int delta_x_coord, int delta_y_coord);

    ~Field();

};


#endif //OOP_PROJECT_FIELD_H
