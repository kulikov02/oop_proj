#ifndef OOP_PROJECT_FIRE_TRAP_H
#define OOP_PROJECT_FIRE_TRAP_H
#include "../Trap.h"

class Fire_Trap: public Trap {
public:
    explicit Fire_Trap(Player* other_hero);
    void interact() override;
    std::string get_log() override;
    std::string get_str() override;
};


#endif //OOP_PROJECT_FIRE_TRAP_H
