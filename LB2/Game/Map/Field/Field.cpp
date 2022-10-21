#include "Field.h"

#define MAP_SIZE 10


Field::Field(int height, int width, Player *hero, int player_x_coord, int player_y_coord)
        : field_height(height),
          field_width(width),
          hero(hero),
          player_x_coord(
                  player_x_coord),
          player_y_coord(
                  player_y_coord) {

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
    this->map[field_width-1][field_height-1].set_cell_type(Exit);
    this->map[0][0].player_on_cell(hero,0,0);
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
    this->map[player_x_coord][player_y_coord].player_on_cell(hero,player_x_coord,player_y_coord);
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
    this->map[player_x_coord][player_y_coord].player_on_cell(hero,player_x_coord,player_y_coord);
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
        this->current_player_cell->player_on_cell(this->hero,player_x_coord,player_y_coord);
    }

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


Field::~Field() {
    for (int i = 0; i < field_width; i++) {
        delete[]map[i];
    }
    delete[]map;
}



