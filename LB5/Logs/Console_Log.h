#ifndef OOP_PROJECT_CONSOLE_LOG_H
#define OOP_PROJECT_CONSOLE_LOG_H
#include "ILogger.h"


class Console_Log:public ILogger {
public:
    void output_logs(Observed_Obj* obj) override;
};


#endif //OOP_PROJECT_CONSOLE_LOG_H
