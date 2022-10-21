#ifndef OOP_PROJECT_FROST_TRAP_H
#define OOP_PROJECT_FROST_TRAP_H
#include "../Trap.h"

class Frost_Trap: public Trap {
public:
    Frost_Trap();
    void interact(Player* hero, int player_x_coord, int player_y_coord) override;
};


#endif //OOP_PROJECT_FROST_TRAP_H
