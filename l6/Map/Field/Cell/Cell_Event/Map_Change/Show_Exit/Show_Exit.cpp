#include "Show_Exit.h"


void Show_Exit::set_exit_shown_flag() {
    for (int i = 0; i < this->field_obj->get_width(); i++) {
        for (int j = 0; j < this->field_obj->get_height(); j++) {
            if (this->field_obj->get_field()[i][j].get_cell_type() == Exit && this->field_obj->get_field()[i][j].get_exit_is_shown_flag() == 0) {
                this->field_obj->get_field()[i][j].set_exit_is_shown_flag(1);
                this->notify();
            }
        }
    }

}


void Show_Exit::interact() {
    this->set_exit_shown_flag();
}

Show_Exit::Show_Exit(Field *other_field) {
    this->field_obj = other_field;

}

std::string Show_Exit::get_log() {
    return "The exit showing event worked.\n";
}

std::string Show_Exit::get_str() {
    return "Show";
}
