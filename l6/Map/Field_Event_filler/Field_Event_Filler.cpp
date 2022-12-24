#include "Field_Event_Filler.h"

Field_Event_Filler::Field_Event_Filler(Field *other_field) {
    this->field_obj = other_field;
}

//enum event_type {
//    Fire_Trap,
//    Frost_Trap,
//    Show_Exit,
//    Break_Walls,
//    Increase_Agility,
//    Increase_Health,
//    Increase_Frost_Armor,
//    Increase_Fire_Armor
//};
void Field_Event_Filler::fill_the_field() {
    srand(time(nullptr));
    for (int i = 0; i < this->field_obj->get_width(); i++) {
        for (int j = 0; j < this->field_obj->get_height(); j++) {
            int rand_num = rand() % 8;
            if (rand_num == 0) {
                this->field_obj->get_field()[i][j].set_event(new Fire_Trap(this->field_obj->get_hero()));
            }
            if (rand_num == 1) {
                this->field_obj->get_field()[i][j].set_event(new Frost_Trap(this->field_obj->get_hero()));
            }
            if (rand_num == 2) {
                this->field_obj->get_field()[i][j].set_event(new Increase_Fire_Armor(this->field_obj->get_hero()));
            }
            if (rand_num == 3) {
                this->field_obj->get_field()[i][j].set_event(
                        new Break_Walls(this->field_obj));
            }
            if (rand_num == 4) {
                this->field_obj->get_field()[i][j].set_event(new Increase_Agility(this->field_obj->get_hero()));
            }
            if (rand_num == 5) {
                this->field_obj->get_field()[i][j].set_event(new Increase_Health(this->field_obj->get_hero()));
            }
            if (rand_num == 6) {
                this->field_obj->get_field()[i][j].set_event(new Increase_Frost_Armor(this->field_obj->get_hero()));
            }

            if (rand_num == 7) {
                this->field_obj->get_field()[i][j].set_event(
                        new Show_Exit(this->field_obj));
            }
        }
    }

}

void Field_Event_Filler::fill_loading_field(Field *loading_field) {
    for (int i = 0; i < loading_field->get_width(); i++) {
        for (int j = 0; j < loading_field->get_height(); j++) {
            if (loading_field->get_field()[i][j].get_cell_ev_str() == "null") {
                loading_field->get_field()[i][j].set_event(nullptr);
            }
            if (loading_field->get_field()[i][j].get_cell_ev_str() == "Show") {
                loading_field->get_field()[i][j].set_event(new Show_Exit(this->field_obj));
            }
            if (loading_field->get_field()[i][j].get_cell_ev_str() == "Break") {
                loading_field->get_field()[i][j].set_event(new Break_Walls(this->field_obj));
            }
            if (loading_field->get_field()[i][j].get_cell_ev_str() == "IFI") {
                loading_field->get_field()[i][j].set_event(new Increase_Fire_Armor(this->field_obj->get_hero()));
            }
            if (loading_field->get_field()[i][j].get_cell_ev_str() == "IFR") {
                loading_field->get_field()[i][j].set_event(new Increase_Frost_Armor(this->field_obj->get_hero()));
            }
            if (loading_field->get_field()[i][j].get_cell_ev_str() == "IA") {
                loading_field->get_field()[i][j].set_event(new Increase_Agility(this->field_obj->get_hero()));
            }
            if (loading_field->get_field()[i][j].get_cell_ev_str() == "IH") {
                loading_field->get_field()[i][j].set_event(new Increase_Health(this->field_obj->get_hero()));
            }
            if (loading_field->get_field()[i][j].get_cell_ev_str() == "FRT") {
                loading_field->get_field()[i][j].set_event(new Frost_Trap(this->field_obj->get_hero()));
            }
            if (loading_field->get_field()[i][j].get_cell_ev_str() == "FIT") {
                loading_field->get_field()[i][j].set_event(new Fire_Trap(this->field_obj->get_hero()));
            }
        }
    }

}