#ifndef OOP_PROJECT_CONTROLLER_H
#define OOP_PROJECT_CONTROLLER_H
#include "../Map/FieldView/FieldView.h"
#include "../Map/Field_Event_filler/Field_Event_Filler.h"
class Controller {
    FieldView* fieldview_obj;
public:
    Controller(int width, int height);
    void start_game();
    int is_player_dead_or_won();
    ~Controller();
};


#endif //OOP_PROJECT_CONTROLLER_H
