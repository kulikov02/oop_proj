#ifndef OOP_PROJECT_FROST_TRAP_H
#define OOP_PROJECT_FROST_TRAP_H
#include "../Trap.h"

class Frost_Trap: public Trap {
public:
    explicit Frost_Trap(Player* other_hero);
    void interact() override;
    std::string get_log() override;
    std::string get_str() override;
};


#endif //OOP_PROJECT_FROST_TRAP_H
