#ifndef OOP_PROJECT_FIRE_TRAP_H
#define OOP_PROJECT_FIRE_TRAP_H
#include "../Trap.h"

class Fire_Trap: public Trap {
public:
    Fire_Trap();
    void interact(Player* hero, int player_x_coord, int player_y_coord) override;
};


#endif //OOP_PROJECT_FIRE_TRAP_H
