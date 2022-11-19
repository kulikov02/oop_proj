#ifndef OOP_PROJECT_INCREASE_AGILITY_H
#define OOP_PROJECT_INCREASE_AGILITY_H
#include "../Stats_Change.h"

class Increase_Agility: public Stats_Change{
public:
    explicit Increase_Agility(Player* other_hero);
    void interact() override;
    std::string get_log() override;
};


#endif //OOP_PROJECT_INCREASE_AGILITY_H
