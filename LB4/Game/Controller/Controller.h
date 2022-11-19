#ifndef OOP_PROJECT_CONTROLLER_H
#define OOP_PROJECT_CONTROLLER_H
#include "../Map/FieldView/FieldView.h"
#include "../Map/Field_Event_filler/Field_Event_Filler.h"
#include "../Logs/Console_Log.h"
#include "../Logs/File_Log.h"
#include "../Logs/Observer.h"
#include "../Commands/Command_Reader/Command_Reader.h"

class Controller {
    FieldView* fieldview_obj;
    Observer* log_observer;
    Command_Reader* c_reader;
public:
    Controller(int width, int height);
    void start_game();
    int is_player_dead_or_won();
    void set_logs(int num);
    ~Controller();
};


#endif //OOP_PROJECT_CONTROLLER_H
