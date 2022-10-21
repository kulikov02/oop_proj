#include "Show_Exit.h"


void Show_Exit::set_exit_shown_flag() {
    for (int i = 0; i < this->width; i++) {
        for (int j = 0; j < this->height; j++) {
            if(this->map[i][j].get_cell_type() == Exit & this->map[i][j].get_exit_is_shown_flag() == 0){
                this->map[i][j].set_exit_is_shown_flag(1);
            }
        }
    }
}


void Show_Exit::interact(Player *hero, int x_coord, int y_coord) {
    this->set_exit_shown_flag();
}

Show_Exit::Show_Exit(Cell **map, int width, int height) {
    this->width = width;
    this->height = height;
    this->map = map;
}
