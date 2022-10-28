#ifndef OOP_PROJECT_STATS_CHANGE_H
#define OOP_PROJECT_STATS_CHANGE_H
#include "../ICell_Event.h"
#include "../../../../../Logs/Observed_Obj.h"

class Stats_Change: public ICell_Event {
protected:
    int amount_of_change;
    Player* hero;
};


#endif //OOP_PROJECT_STATS_CHANGE_H
