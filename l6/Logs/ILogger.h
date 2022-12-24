#ifndef OOP_PROJECT_ILOGGER_H
#define OOP_PROJECT_ILOGGER_H
#include "Observed_Obj.h"

class ILogger {
public:
    virtual void output_logs(Observed_Obj* obj) = 0;
};


#endif //OOP_PROJECT_ILOGGER_H
