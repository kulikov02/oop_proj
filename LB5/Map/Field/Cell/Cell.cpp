#include "Cell.h"

Cell::Cell(Cell_type other_type, ICell_Event *other_event, int player_flag, int exit_flag) : type(other_type),
                                                                                             event(other_event),
                                                                                             player_on_cell_flag(
                                                                                                     player_flag),
                                                                                             exit_is_shown_flag(
                                                                                                     exit_flag) {
    if (other_type == Wall) {
        this->event = nullptr;
    }
}

Cell::Cell(const Cell &other_cell) {
    this->type = other_cell.type;
    this->event = other_cell.event;
    this->player_on_cell_flag = other_cell.player_on_cell_flag;
    this->exit_is_shown_flag = other_cell.exit_is_shown_flag;
}

Cell::Cell(Cell &&other_cell) noexcept {
    std::swap(event, other_cell.event);
    std::swap(type, other_cell.type);
    std::swap(player_on_cell_flag, other_cell.player_on_cell_flag);
    std::swap(exit_is_shown_flag, other_cell.exit_is_shown_flag);
}

Cell &Cell::operator=(const Cell &other_cell) {
    if (this != &other_cell) {
        *this->event = *other_cell.event;
        this->type = other_cell.type;

    }
    return *this;
}

Cell &Cell::operator=(Cell &&other_cell) noexcept {
    if (this != &other_cell) {
        std::swap(event, other_cell.event);
        std::swap(type, other_cell.type);
        std::swap(player_on_cell_flag, other_cell.player_on_cell_flag);
    }
    return *this;
}


void Cell::set_cell_type(Cell_type other_type) {
    this->type = other_type;


}

void Cell::player_on_cell(Player *hero, int player_x_coord, int player_y_coord) {
    this->player_on_cell_flag = 1;
    if (this->event != nullptr && this->event_finished == 0) {
        this->event->interact();
        this->event_finished = 1;
    }
}

Cell_type Cell::get_cell_type() {
    return type;
}


void Cell::set_event(ICell_Event *other_event) {
    this->event = other_event;
}

void Cell::set_exit_is_shown_flag(int num) {
    this->exit_is_shown_flag = num;
}

int Cell::get_exit_is_shown_flag() {
    return this->exit_is_shown_flag;
}


ICell_Event *Cell::get_event() {
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

Cell::~Cell() {
    delete event;
}