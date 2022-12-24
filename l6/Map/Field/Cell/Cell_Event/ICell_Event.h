#ifndef OOP_PROJECT_ICELL_EVENT_H
#define OOP_PROJECT_ICELL_EVENT_H

#include "../../../../Player/Player.h"
#include "../../../../Logs/Observed_Obj.h"

class ICell_Event: public Observed_Obj {
public:
    virtual void interact() = 0;
    virtual std::string get_str()=0;
};


#endif //OOP_PROJECT_ICELL_EVENT_H
