#include "Controller.h"

Controller::Controller() {
    auto* field_obj = new Field();
    auto* fieldview =  new FieldView(field_obj);
    this->fieldview_obj = fieldview;
}

void Controller::set_field_size(int width, int height) {
    delete this->fieldview_obj;
    if(width < 3 or width > 20 or height < 3 or height > 20){
        width = 10;
        height = 10;
    }
    auto* field_obj = new Field(height,width);
    auto* fieldview =  new FieldView(field_obj);
    this->fieldview_obj = fieldview;
}

void Controller::start_game() {
    char choice;
    this->fieldview_obj->show_field();
    while(true){
        std::cin >> choice;
        switch (choice) {
            case 'w':
                this->fieldview_obj->get_field()->move_player(0,1);
                this->fieldview_obj->show_field();
                break;
            case 'a':
                this->fieldview_obj->get_field()->move_player(-1,0);
                this->fieldview_obj->show_field();
                break;

            case 's':
                this->fieldview_obj->get_field()->move_player(0,-1);
                this->fieldview_obj->show_field();
                break;

            case 'd':
                this->fieldview_obj->get_field()->move_player(1,0);
                this->fieldview_obj->show_field();
                break;

            case 'e':
                return;

            default:
                continue;
        }
    }
}

Controller::~Controller() {
    delete this->fieldview_obj;
}