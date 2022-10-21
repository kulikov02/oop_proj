#ifndef OOP_PROJECT_INCREASE_AGILITY_H
#define OOP_PROJECT_INCREASE_AGILITY_H
#include "../Stats_Change.h"

class Increase_Agility: public Stats_Change {
public:
    Increase_Agility();
    void interact(Player* hero, int player_x_coord, int player_y_coord) override;
};


#endif //OOP_PROJECT_INCREASE_AGILITY_H
