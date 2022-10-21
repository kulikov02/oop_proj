#ifndef OOP_PROJECT_INCREASE_HEALTH_H
#define OOP_PROJECT_INCREASE_HEALTH_H
#include "../Stats_Change.h"

class Increase_Health: public Stats_Change {
public:
    Increase_Health();
    void interact(Player* hero, int player_x_coord, int player_y_coord) override;
};


#endif //OOP_PROJECT_INCREASE_HEALTH_H
