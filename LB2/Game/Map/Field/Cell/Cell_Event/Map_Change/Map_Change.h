#ifndef OOP_PROJECT_MAP_CHANGE_H
#define OOP_PROJECT_MAP_CHANGE_H
#include "../ICell_Event.h"
#include "../../Cell.h"
class Map_Change: public ICell_Event {
protected:
    Cell** map;
    int height;
    int width;
};


#endif //OOP_PROJECT_MAP_CHANGE_H
