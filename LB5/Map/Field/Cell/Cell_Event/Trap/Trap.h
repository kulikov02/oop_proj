#ifndef OOP_PROJECT_TRAP_H
#define OOP_PROJECT_TRAP_H
#include "../ICell_Event.h"
#include "../../../../../Logs/Observed_Obj.h"

class Trap : public ICell_Event {
protected:
    int trap_power;
    Player* hero;
};


#endif //OOP_PROJECT_TRAP_H
