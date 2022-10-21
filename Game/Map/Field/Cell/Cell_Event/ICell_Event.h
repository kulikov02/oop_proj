#ifndef OOP_PROJECT_ICELL_EVENT_H
#define OOP_PROJECT_ICELL_EVENT_H

#include "../../../../Player/Player.h"

class ICell_Event {
public:
    virtual void interact(Player* hero, int player_x_coord, int player_y_coord) = 0;
};


#endif //OOP_PROJECT_ICELL_EVENT_H
