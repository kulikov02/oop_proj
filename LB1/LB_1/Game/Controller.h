#ifndef OOP_PROJECT_CONTROLLER_H
#define OOP_PROJECT_CONTROLLER_H
#include "Map/FieldView.h"

class Controller {
    FieldView* fieldview_obj;
public:
    Controller();
    void set_field_size(int width,int height);
    void start_game();
    ~Controller();
};


#endif //OOP_PROJECT_CONTROLLER_H
