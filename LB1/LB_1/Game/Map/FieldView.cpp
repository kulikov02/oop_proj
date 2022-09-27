#include "FieldView.h"
#include <iostream>

FieldView::FieldView(Field *other_field) {
    this->game_field = other_field;
    Cell** map = other_field->get_field();
    this->output_arr_height = other_field->get_height();
    this->output_arr_width = other_field->get_width();
    this->output_arr = new char*[this->output_arr_width];
    for(int i = 0;i < this->output_arr_width;i++){
        this->output_arr[i] = new char[this->output_arr_height];
    }
    for(int i = 0;i < this->output_arr_width;i++){
        for(int j = 0;j < this->output_arr_height;j++){
            if(map[i][j].get_cell_type() == Free){
                this->output_arr[i][j] = 'F';
            }
            if(map[i][j].get_cell_type() == Wall){
                this->output_arr[i][j] = 'W';
            }
            if(map[i][j].is_player_on_cell() == 1){
                this->output_arr[i][j] = 'P';
            }
        }
    }
}


void FieldView::show_field() {
    Cell** map = this->game_field->get_field();
    for(int i = 0;i < this->output_arr_width;i++){
        for(int j = 0;j < this->output_arr_height;j++){
            if(map[i][j].get_cell_type() == Free or map[i][j].get_cell_type() == Start){
                this->output_arr[i][j] = 'F';
            }
            if(map[i][j].get_cell_type() == Wall){
                this->output_arr[i][j] = 'W';
            }
            if(map[i][j].is_player_on_cell() == 1){
                this->output_arr[i][j] = 'P';
            }
        }
    }
    for(int j = this->output_arr_height-1; j >= 0;j--){
        for(int i = 0;i < this->output_arr_width; i++){
            std::cout << this->output_arr[i][j] << ' ';
        }
        std::cout << '\n';
    }
    std::cout << '\n';

}

Field *FieldView::get_field() {
    return this->game_field;
}

FieldView::~FieldView() {
    for(int i = 0;i < this->output_arr_width;i++){
        delete this->output_arr[i];
    }
    delete []output_arr;
}
