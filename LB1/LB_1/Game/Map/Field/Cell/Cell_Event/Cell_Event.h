#ifndef OOP_PROJECT_CELL_EVENT_H
#define OOP_PROJECT_CELL_EVENT_H

#include "../../../../Player/Player.h"

class Cell_Event {
public:
    virtual void interact(Player* hero) = 0;
};


#endif //OOP_PROJECT_CELL_EVENT_H
