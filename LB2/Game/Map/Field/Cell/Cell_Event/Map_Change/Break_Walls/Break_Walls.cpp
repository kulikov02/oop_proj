#include "Break_Walls.h"

Break_Walls::Break_Walls(Cell **map, int width, int height) {
    this->map = map;
    this->width = width;
    this->height = height;
}

void Break_Walls::break_walls_around() {
    for(int i = player_x_coord - 1;i < player_x_coord + 2;i++){
        if(i < this->width & i >= 0){
            for(int j = this->player_y_coord; j < player_y_coord + 2;j++){
                if( j < this->height & j >= 0){
                    this->map[i][j].set_cell_type(Free);
                }
            }
        }
    }

}


void Break_Walls::interact(Player* hero, int x_coord, int y_coord) {
    this->player_x_coord = x_coord;
    this->player_y_coord = y_coord;
    this->break_walls_around();
}