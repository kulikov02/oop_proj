#include "FieldView.h"
#include <iostream>

FieldView::FieldView(Field *other_field) {
    this->game_field = other_field;
    Cell **map = other_field->get_field();
    this->output_arr_height = other_field->get_height();
    this->output_arr_width = other_field->get_width();
    this->output_arr = new char *[this->output_arr_width];
    for (int i = 0; i < this->output_arr_width; i++) {
        this->output_arr[i] = new char[this->output_arr_height];
    }
    for (int i = 0; i < this->output_arr_width; i++) {
        for (int j = 0; j < this->output_arr_height; j++) {
            if (map[i][j].get_cell_type() == Free) {
                this->output_arr[i][j] = 'F';
            }
            if (map[i][j].get_cell_type() == Wall) {
                this->output_arr[i][j] = 'W';
            }
            if (map[i][j].is_player_on_cell() == 1) {
                this->output_arr[i][j] = 'P';
            }
            if (map[i][j].get_cell_type() == Exit & map[i][j].get_exit_is_shown_flag() == 1) {
                this->output_arr[i][j] = 'E';
            }
        }
    }
}


void FieldView::show_field() {
    Cell **map = this->game_field->get_field();
    for (int i = 0; i < this->output_arr_width; i++) {
        for (int j = 0; j < this->output_arr_height; j++) {
            if (map[i][j].get_cell_type() == Free or map[i][j].get_cell_type() == Start) {
                this->output_arr[i][j] = 'F';
            }
            if (map[i][j].get_cell_type() == Wall) {
                this->output_arr[i][j] = 'W';
            }
            if (map[i][j].is_player_on_cell() == 1) {
                this->output_arr[i][j] = 'P';
            }
            if (map[i][j].get_cell_type() == Exit) {
                this->output_arr[i][j] = 'F';
            }
            if (map[i][j].get_cell_type() == Exit & map[i][j].get_exit_is_shown_flag() == 1) {
                this->output_arr[i][j] = 'E';
            }
        }
    }
    for (int j = this->output_arr_height - 1; j >= 0; j--) {
        for (int i = 0; i < this->output_arr_width; i++) {
            std::cout << this->output_arr[i][j] << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';

}

void FieldView::show_stats() {
    std::cout << "Health: " << this->game_field->get_hero()->get_player_health() << '\n';
    std::cout << "Frost armor: " << this->game_field->get_hero()->get_player_frost_armor() << '\n';
    std::cout << "Fire armor: " << this->game_field->get_hero()->get_player_fire_armor() << '\n';
    std::cout << "Agility: " << this->game_field->get_hero()->get_player_agility() << '\n';
}

void FieldView::player_dead() {
    std::cout << "You died. The game is over";
}

void FieldView::player_won() {
    std::cout << "You finished the game!";
}

Field *FieldView::get_field() {
    return this->game_field;
}

FieldView::~FieldView() {
    for (int i = 0; i < this->output_arr_width; i++) {
        delete this->output_arr[i];
    }
    delete[]output_arr;
}
