#include "Field.h"

#define MAP_SIZE 10


Field::Field(int height, int width, Player *hero, int player_x_coord, int player_y_coord)
        : field_height(height),
          field_width(width),
          hero(hero),
          player_x_coord(
                  player_x_coord),
          player_y_coord(
                  player_y_coord), wall_error_flag(0), size_error_flag(0), loggers_amount(1) {

    if (width < 3 or width > 20 or height < 3 or height > 20) {
        this->field_width = width = 10;
        this->field_height = height = 10;
        this->size_error_flag = 1;
        this->notify();
    }
    map = new Cell *[this->field_width];
    for (int i = 0; i < this->field_width; i++) {
        map[i] = new Cell[this->field_height];
    }
    for (int i = 0; i < this->field_width; i++) {
        for (int j = 0; j < this->field_height; j++) {
            this->map[i][j] = Cell();
        }
    }
    this->current_player_cell = &this->map[0][0];
    this->current_player_cell->set_cell_type(Start);
    this->map[field_width - 1][field_height - 1].set_cell_type(Exit);
    this->map[0][0].player_on_cell(hero, 0, 0);
}

Field::Field(const Field &other_field) {
    this->field_width = other_field.field_width;
    this->field_height = other_field.field_height;
    this->player_x_coord = other_field.player_x_coord;
    this->player_y_coord = other_field.player_y_coord;
    this->hero = other_field.hero;
    this->map = new Cell *[this->field_width];
    for (int i = 0; i < this->field_width; i++) {
        this->map[i] = new Cell[this->field_height];
    }
    for (int i = 0; i < this->field_width; i++) {
        for (int j = 0; j < this->field_height; j++) {
            this->map[i][j] = other_field.map[i][j];
        }
    }
    this->current_player_cell = other_field.current_player_cell;
    this->map[player_x_coord][player_y_coord].player_on_cell(hero, player_x_coord, player_y_coord);
}

Field::Field(Field &&other_field) noexcept {
    std::swap(map, other_field.map);
    std::swap(field_height, other_field.field_height);
    std::swap(field_width, other_field.field_width);
    std::swap(player_y_coord, other_field.player_y_coord);
    std::swap(player_x_coord, other_field.player_x_coord);
    std::swap(hero, other_field.hero);
    std::swap(current_player_cell, other_field.current_player_cell);
}

void Field::set_current_player_cell(Cell *new_player_cell) {
    this->current_player_cell = new_player_cell;
}

Field &Field::operator=(const Field &other_field) {
    if (this != &other_field) {
        for (int i = 0; i < field_width; i++) {
            delete[]map[i];
        }
        delete[]map;
    }

    this->field_width = other_field.field_width;
    this->field_height = other_field.field_height;
    this->player_x_coord = other_field.player_x_coord;
    this->player_y_coord = other_field.player_y_coord;
    this->hero = other_field.hero;
    this->map = new Cell *[this->field_width];
    for (int i = 0; i < this->field_width; i++) {
        this->map[i] = new Cell[this->field_height];
    }
    for (int i = 0; i < this->field_width; i++) {
        for (int j = 0; j < this->field_height; j++) {
            this->map[i][j] = other_field.map[i][j];
        }
    }
    this->current_player_cell = other_field.current_player_cell;
    this->map[player_x_coord][player_y_coord].player_on_cell(hero, player_x_coord, player_y_coord);
    return *this;
}


Field &Field::operator=(Field &&other_field) noexcept {
    if (this != &other_field) {
        std::swap(map, other_field.map);
        std::swap(field_height, other_field.field_height);
        std::swap(field_width, other_field.field_width);
        std::swap(player_y_coord, other_field.player_y_coord);
        std::swap(player_x_coord, other_field.player_x_coord);
        std::swap(hero, other_field.hero);
        std::swap(current_player_cell, other_field.current_player_cell);
    }
    return *this;
}

Cell **Field::get_field() {
    return this->map;
}

Player *Field::get_hero() {
    return this->hero;
}

Cell *Field::get_current_player_cell() {
    return this->current_player_cell;
}

void Field::move_player(int delta_x_coord, int delta_y_coord) {
    int new_x_coord = this->player_x_coord + delta_x_coord;
    int new_y_coord = this->player_y_coord + delta_y_coord;
    if (new_x_coord == this->field_width) {
        new_x_coord = 0;
    }
    if (new_y_coord == this->field_height) {
        new_y_coord = 0;
    }
    if (new_x_coord == -1) {
        new_x_coord = this->field_width - 1;
    }
    if (new_y_coord == -1) {
        new_y_coord = this->field_height - 1;
    }


    if (this->map[new_x_coord][new_y_coord].get_cell_type() != Wall) {
        this->current_player_cell->player_out_of_cell();
        this->player_x_coord = new_x_coord;
        this->player_y_coord = new_y_coord;
        this->current_player_cell = &this->map[player_x_coord][player_y_coord];
        this->current_player_cell->player_on_cell(this->hero, player_x_coord, player_y_coord);
    } else {
        if (this->loggers_amount == 2) {
            this->wall_error_flag = 2;
        } else {
            this->wall_error_flag = 1;
        }
    }
    this->notify();

}


int Field::get_height() {
    return this->field_height;
}

int Field::get_width() {
    return this->field_width;
}

int Field::get_player_x_coord() {
    return this->player_x_coord;
}

int Field::get_player_y_coord() {
    return this->player_y_coord;
}

void Field::set_player_x_coord(int new_x_coord) {
    this->player_x_coord = new_x_coord;
}

void Field::set_player_y_coord(int new_y_coord) {
    this->player_y_coord = new_y_coord;
}

void Field::set_loggers_amount(int num) {
    this->loggers_amount = num;
    if (this->size_error_flag == 1 & num == 2) {
        this->size_error_flag = 2;
    }
}

std::string Field::get_log() {
    if (this->wall_error_flag >= 1) {
        this->wall_error_flag -= 1;
        return "The player tried to go through wall.\n";
    }
    if (this->size_error_flag >= 1) {
        this->size_error_flag -= 1;
        return "The player tried to make a field with wrong size.\n" + std::string("Current hero position: ") +
               std::string("[") +
               std::to_string(player_x_coord) + std::string("]") +
               std::string("[") + std::to_string(player_y_coord) + std::string("]") + "\n";
    }
    return "Current hero position: " + std::string("[") + std::to_string(player_x_coord) + std::string("]") +
           std::string("[") + std::to_string(player_y_coord) + std::string("]") + "\n";
}

std::string Field::save() {
    std::string state_arr[11];
    state_arr[0] = std::to_string(this->field_height);
    state_arr[1] = std::to_string(this->field_width);
    state_arr[2] = std::to_string(this->player_x_coord);
    state_arr[3] = std::to_string(this->player_y_coord);
    state_arr[4] = std::to_string(this->loggers_amount);
    state_arr[5] = std::to_string(this->wall_error_flag);
    state_arr[6] = std::to_string(this->size_error_flag);
    state_arr[7] = std::to_string(this->get_hero()->get_player_health());
    state_arr[8] = std::to_string(this->get_hero()->get_player_frost_armor());
    state_arr[9] = std::to_string(this->get_hero()->get_player_fire_armor());
    state_arr[10] = std::to_string(this->get_hero()->get_player_agility());
    std::string
            state =
            state_arr[0] + " " + state_arr[1] + " " + state_arr[2] + " " + state_arr[3] + " " + state_arr[4] + " " +
            state_arr[5] + " " + state_arr[6] + " " + state_arr[7] + " " + state_arr[8] + " " + state_arr[9] + " " +
            state_arr[10];
    return state;
}

void Field::restore(std::string load_str) {
    std::string state = load_str;
    std::string state_array[11];
    int j = 0;
    for (int i = 0; i < 11; i++) {
        while (state[j] != ' ' && j < state.size()) {
            state_array[i] += state[j];
            j++;
        }
        while (state[j] == ' ') {
            j++;
        }
    }
    this->field_height = std::stoi(state_array[0]);
    this->field_width = std::stoi(state_array[1]);
    this->player_x_coord = std::stoi(state_array[2]);
    this->player_y_coord = std::stoi(state_array[3]);
    this->loggers_amount = std::stoi(state_array[4]);
    this->wall_error_flag = std::stoi(state_array[5]);
    this->size_error_flag = std::stoi(state_array[6]);
    this->get_hero()->set_player_health(std::stoi(state_array[7]));
    this->get_hero()->set_player_frost_armor(std::stoi(state_array[8]));
    this->get_hero()->set_player_fire_armor(std::stoi(state_array[9]));
    this->get_hero()->set_player_agility(std::stoi(state_array[10]));
    this->current_player_cell = &this->get_field()[this->player_x_coord][this->player_y_coord];
    if ((field_width < 3 || field_width > 20) || (field_height < 3 || field_height > 20) ||
        (player_x_coord >= field_width) || (player_x_coord < 0) || (player_y_coord < 0) ||
        (player_y_coord >= field_width) || (wall_error_flag != 0 && wall_error_flag != 1) ||
        (loggers_amount != 0 && loggers_amount != 1 && loggers_amount != 2) ||
        (size_error_flag != 0 && size_error_flag != 1) ||
        (this->get_hero()->get_player_health() < 1)) {
        throw Load_Field_Exception();
    }
}


Field::~Field() {
    for (int i = 0; i < field_width; i++) {
        delete[]map[i];
    }
    delete[]map;
}



