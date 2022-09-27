#ifndef OOP_PROJECT_CELL_H
#define OOP_PROJECT_CELL_H

#include <iostream>
#include "Cell_Event/Cell_Event.h"

enum Cell_type {
    Wall, Free, Start, Finish
};

class Cell {
    Cell_type type;
    Cell_Event *event;
    int player_on_cell_flag;
public:
    explicit Cell(Cell_type other_type = Free, Cell_Event *other_event = nullptr, int player_flag = 0);

    Cell(const Cell &other_cell);

    Cell(Cell &&other_cell);

    Cell &operator=(const Cell &other_cell);

    Cell &operator=(Cell &&other_cell);

    void set_cell_type(Cell_type other_type);

    void player_out_of_cell();

    void player_on_cell(Player *hero);

    Cell_type get_cell_type();

    void set_event(Cell_Event *other_event);

    Cell_Event *get_event();

    int is_player_on_cell();


};


#endif //OOP_PROJECT_CELL_H
