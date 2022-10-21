#include "Controller.h"

Controller::Controller(int width, int height) {
    if(width < 3 or width > 20 or height < 3 or height > 20){
        width = 10;
        height = 10;
    }
    auto* field_obj = new Field(height,width);
    auto* field_event_filler_obj = new Field_Event_Filler(field_obj);
    field_event_filler_obj->fill_the_field();
    auto* fieldview =  new FieldView(field_obj);
    this->fieldview_obj = fieldview;
}



int Controller::is_player_dead_or_won() {
    if(this->fieldview_obj->get_field()->get_hero()->get_player_health() <= 0){
        this->fieldview_obj->player_dead();
        return 1;
    }
     if(this->fieldview_obj->get_field()->get_current_player_cell()->get_cell_type() == Exit){
         this->fieldview_obj->player_won();
         return 1;
     }
     return 0;
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
                if(this->is_player_dead_or_won() == 1){
                    return;
                }
                break;
            case 'a':
                this->fieldview_obj->get_field()->move_player(-1,0);
                this->fieldview_obj->show_field();
                if(this->is_player_dead_or_won() == 1){
                    return;
                }
                break;

            case 's':
                this->fieldview_obj->get_field()->move_player(0,-1);
                this->fieldview_obj->show_field();
                if(this->is_player_dead_or_won() == 1){
                    return;
                }
                break;

            case 'd':
                this->fieldview_obj->get_field()->move_player(1,0);
                this->fieldview_obj->show_field();
                if(this->is_player_dead_or_won() == 1){
                    return;
                }
                break;

            case 'e':
                return;
            case 'c':
                this->fieldview_obj->show_stats();
            default:
                continue;
        }
    }
}

Controller::~Controller() {
    delete this->fieldview_obj;
}