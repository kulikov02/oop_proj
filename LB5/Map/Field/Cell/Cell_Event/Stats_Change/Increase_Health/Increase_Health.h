#ifndef OOP_PROJECT_INCREASE_HEALTH_H
#define OOP_PROJECT_INCREASE_HEALTH_H
#include "../Stats_Change.h"

class Increase_Health: public Stats_Change {
public:
    explicit Increase_Health(Player* other_hero);
    void interact() override;
    std::string get_log() override;
};


#endif //OOP_PROJECT_INCREASE_HEALTH_H
