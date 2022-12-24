#ifndef OOP_PROJECT_OBSERVER_H
#define OOP_PROJECT_OBSERVER_H
#include "ILogger.h"
#include "Observed_Obj.h"
#include "../Map/Field/Field.h"

class Observer{
protected:
    ILogger* logger1;
    ILogger* logger2;
    Field* game_field;
public:
    Observer(Field* game_field = nullptr, ILogger* inp_logger_1 = nullptr, ILogger* inp_logger_2 = nullptr);
    void update();
};


#endif //OOP_PROJECT_OBSERVER_H
