#ifndef OOP_PROJECT_INCREASE_FIRE_ARMOR_H
#define OOP_PROJECT_INCREASE_FIRE_ARMOR_H
#include "../Stats_Change.h"

class Increase_Fire_Armor: public Stats_Change  {
public:
    Increase_Fire_Armor();
    void interact(Player* hero, int player_x_coord, int player_y_coord) override;
};


#endif //OOP_PROJECT_INCREASE_FIRE_ARMOR_H
