#ifndef OOP_PROJECT_BREAK_WALLS_H
#define OOP_PROJECT_BREAK_WALLS_H
#include "../Map_Change.h"

class Break_Walls: public Map_Change {
    int player_x_coord;
    int player_y_coord;
public:
    Break_Walls(Cell** map, int width, int height);
    void interact(Player* hero, int player_x_coord, int player_y_coord) override;
    void break_walls_around();

};


#endif //OOP_PROJECT_BREAK_WALLS_H
