#ifndef OOP_PROJECT_CELL_H
#define OOP_PROJECT_CELL_H

#include <iostream>
#include "Cell_Event/ICell_Event.h"
#include "Load_Cell_Exception.h"

enum Cell_type {
    Wall, Free, Start, Exit
};

class Cell {
    Cell_type type;
    ICell_Event *event;
    std::string cell_event_str;
    int exit_is_shown_flag;
    int player_on_cell_flag;
    int event_finished = 0;
public:
    explicit Cell(Cell_type other_type = Free, ICell_Event *other_event = nullptr, int player_flag = 0,
                  int exit_flag = 0);

    Cell(const Cell &other_cell);

    Cell(Cell &&other_cell) noexcept ;

    Cell &operator=(const Cell &other_cell);

    Cell &operator=(Cell &&other_cell) noexcept ;

    void set_cell_type(Cell_type other_type);

    void set_exit_is_shown_flag(int num);

    int get_exit_is_shown_flag();

    void player_out_of_cell();

    void player_on_cell(Player *hero, int player_x_coord, int player_y_coord);

    Cell_type get_cell_type();

    void set_event(ICell_Event *other_event);

    ICell_Event *get_event();

    int is_player_on_cell();

    std::string save();

    void restore(std::string load_str);

    std::string get_cell_ev_str();

    ~Cell();

};


#endif //OOP_PROJECT_CELL_H
