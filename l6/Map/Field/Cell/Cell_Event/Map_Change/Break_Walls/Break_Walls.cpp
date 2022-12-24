#include "Break_Walls.h"

Break_Walls::Break_Walls(Field *other_field) {
    this->field_obj = other_field;
}

void Break_Walls::break_walls_around() {
    for (int i = this->field_obj->get_player_x_coord() - 1; i < this->field_obj->get_player_x_coord() + 2; i++) {
        if (i < this->field_obj->get_width() & i >= 0) {
            for (int j = this->field_obj->get_player_y_coord() - 1;
                 j < this->field_obj->get_player_y_coord() + 2; j++) {
                if (j < this->field_obj->get_height() & j >= 0) {
                    if (this->field_obj->get_field()[i][j].get_cell_type() == Wall) {
                        this->field_obj->get_field()[i][j].set_cell_type(Free);
                    }
                }
            }
        }
    }
    this->notify();
}


void Break_Walls::interact() {
    this->break_walls_around();
}

std::string Break_Walls::get_log() {
    return "Cells from " + std::string("[") + std::to_string(this->field_obj->get_player_x_coord() - 1) +
           std::string("]") + std::string("[") + std::to_string(this->field_obj->get_player_y_coord() - 1) +
           std::string("]") + " to " + std::string("[") + std::to_string(this->field_obj->get_player_x_coord() + 1) +
           std::string("]") + std::string("[") + std::to_string(this->field_obj->get_player_y_coord() + 1) +
           std::string("]") + " are free now.\n";
}

std::string Break_Walls::get_str() {
    return "Break";
}