#ifndef OOP_PROJECT_FIELD_H
#define OOP_PROJECT_FIELD_H

#include "Cell/Cell.h"
#include "../../Player/Player.h"
#include "../../Logs/Observed_Obj.h"
#include "Load_Field_Exception.h"

#define MAP_SIZE 10

class Field : public Observed_Obj {
    Cell **map;
    int field_height;
    int field_width;
    int player_x_coord;
    int player_y_coord;
    int loggers_amount;
    int wall_error_flag;
    int size_error_flag;
    Player *hero;
    Cell *current_player_cell;

public:

    explicit Field(int height = MAP_SIZE, int width = MAP_SIZE, Player *hero = new Player(), int player_x_coord = 0,
                   int player_y_coord = 0);

    Field(const Field &other_field);

    Field(Field &&other_field) noexcept;

    Field &operator=(const Field &other_field);

    Field &operator=(Field &&other) noexcept;

    Cell **get_field();

    Player *get_hero();

    Cell *get_current_player_cell();

    void set_current_player_cell(Cell* new_player_cell);

    int get_player_x_coord();

    int get_player_y_coord();

    void set_player_x_coord(int new_x_coord);

    void set_player_y_coord(int new_y_coord);

    int get_height();

    int get_width();

    void move_player(int delta_x_coord, int delta_y_coord);

    void set_loggers_amount(int num);

    std::string get_log() override;

    std::string save();

    void restore(std::string load_str);

    ~Field();

};


#endif //OOP_PROJECT_FIELD_H
