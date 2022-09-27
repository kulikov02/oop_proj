#include "Cell.h"

Cell::Cell(Cell_type other_type, Cell_Event *other_event, int player_flag) : type(other_type), event(other_event),
                                                                             player_on_cell_flag(player_flag) {
    if (other_type == Wall) {
        this->event = nullptr;
    }
}

Cell::Cell(const Cell &other_cell) {
    this->type = other_cell.type;
    this->event = other_cell.event;
    this->player_on_cell_flag = other_cell.player_on_cell_flag;
}

Cell::Cell(Cell &&other_cell) {
    std::swap(event, other_cell.event);
    std::swap(type, other_cell.type);
    std::swap(player_on_cell_flag, other_cell.player_on_cell_flag);
}

Cell &Cell::operator=(const Cell &other_cell) {
    if (this != &other_cell) {
        *this->event = *other_cell.event;
        this->type = other_cell.type;

    }
    return *this;
}

Cell &Cell::operator=(Cell &&other_cell) {
    if (this != &other_cell) {
        std::swap(event, other_cell.event);
        std::swap(type, other_cell.type);
        std::swap(player_on_cell_flag, other_cell.player_on_cell_flag);
    }
}


void Cell::set_cell_type(Cell_type other_type) {
    this->type = other_type;
    if (other_type == Wall) {
        this->event = nullptr;
    }

}

void Cell::player_on_cell(Player *hero) {
    this->player_on_cell_flag = 1;
    if (this->event) this->event->interact(hero);
}

Cell_type Cell::get_cell_type() {
    return type;
}


void Cell::set_event(Cell_Event *other_event) {
    if (this->type != Wall) event = other_event;
}

Cell_Event *Cell::get_event() {
    return event;
}

void Cell::player_out_of_cell() {
    this->player_on_cell_flag = 0;
}

int Cell::is_player_on_cell() {
    if (this->player_on_cell_flag == 1)
        return 1;
    else
        return 0;
}
