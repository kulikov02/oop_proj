#ifndef OOP_PROJECT_MAP_CHANGE_H
#define OOP_PROJECT_MAP_CHANGE_H
#include "../ICell_Event.h"
#include "../../../Field.h"
#include "../../../../../Logs/Observed_Obj.h"
class Map_Change: public ICell_Event {
protected:
    Field* field_obj;
};


#endif //OOP_PROJECT_MAP_CHANGE_H
