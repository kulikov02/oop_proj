#ifndef OOP_PROJECT_INCREASE_FIRE_ARMOR_H
#define OOP_PROJECT_INCREASE_FIRE_ARMOR_H
#include "../Stats_Change.h"

class Increase_Fire_Armor: public Stats_Change  {
public:
    explicit Increase_Fire_Armor(Player* other_hero);
    void interact() override;
    std::string get_log() override;
};


#endif //OOP_PROJECT_INCREASE_FIRE_ARMOR_H
