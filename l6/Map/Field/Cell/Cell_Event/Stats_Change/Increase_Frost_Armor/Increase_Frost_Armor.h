#ifndef OOP_PROJECT_INCREASE_FROST_ARMOR_H
#define OOP_PROJECT_INCREASE_FROST_ARMOR_H
#include "../Stats_Change.h"

class Increase_Frost_Armor: public Stats_Change {
public:
    explicit Increase_Frost_Armor(Player* other_hero);
    void interact() override;
    std::string get_log() override;
    std::string get_str() override;
};


#endif //OOP_PROJECT_INCREASE_FROST_ARMOR_H
