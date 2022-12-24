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


void Cell::restore(std::string load_str) {
    std::string state = load_str;
    std::string state_array[5];
    int j = 0;
    for (int i = 0; i < 5; i++) {
        while (state[j] != ' ' && j < state.size()) {
            state_array[i] += state[j];
            j++;
        }
        while (state[j] == ' ') {
            j++;
        }
    }
    if (std::stoi(state_array[0]) != 0 && std::stoi(state_array[0]) != 1 && std::stoi(state_array[0]) != 2 &&
        std::stoi(state_array[0]) != 3 && std::stoi(state_array[0]) != 4){
        throw Load_Cell_Exception();
    }
        this->type = Cell_type(std::stoi(state_array[0]));
    this->cell_event_str = state_array[1];
    this->exit_is_shown_flag = std::stoi(state_array[2]);
    this->player_on_cell_flag = std::stoi(state_array[3]);
    this->event_finished = std::stoi(state_array[4]);
    if ((cell_event_str != "Show" && cell_event_str != "null" && cell_event_str != "Break" && cell_event_str != "IFI" &&
         cell_event_str != "IFR" && cell_event_str != "IA" && cell_event_str != "IH" && cell_event_str != "FRT" &&
         cell_event_str != "FIT") || (
                exit_is_shown_flag != 0 && exit_is_shown_flag != 1 && exit_is_shown_flag != -1) || (player_on_cell_flag != 0 &&
                                                                        player_on_cell_flag != 1) ||
        (event_finished != 0 && event_finished != 1)) {
        throw Load_Cell_Exception();
    }
}

std::string Cell::save() {
    std::string state_arr[5];
    state_arr[0] = std::to_string(this->type);
    if (this->event == nullptr) {
        state_arr[1] = "null";
    } else {
        state_arr[1] = this->event->get_str();
    }
    state_arr[2] = std::to_string(this->exit_is_shown_flag);
    state_arr[3] = std::to_string(this->player_on_cell_flag);
    state_arr[4] = std::to_string(this->event_finished);
    std::string state =
            state_arr[0] + " " + state_arr[1] + " " + state_arr[2] + " " + state_arr[3] + " " + state_arr[4];
    return state;
}


std::string Cell::get_cell_ev_str() {
    return this->cell_event_str;
}


Cell::~Cell() {
    delete event;
}