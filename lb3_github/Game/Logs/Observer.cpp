#include "Observer.h"


Observer::Observer(Field *inp_game_field, ILogger *inp_logger_1, ILogger *inp_logger_2) : game_field(inp_game_field),
                                                                                          logger1(inp_logger_1),
                                                                                          logger2(inp_logger_2) {
}

void Observer::update() {
    int num_of_obj = 0;
    Observed_Obj *logging_objects[3];
    if (this->logger1 != nullptr) {
        for (int i = 0; i < this->game_field->get_width(); i++) {
            for (int j = 0; j < this->game_field->get_height(); j++) {
                if (this->game_field->get_field()[i][j].get_event()->get_notify_flag() == 1) {
                    logging_objects[num_of_obj] = this->game_field->get_field()[i][j].get_event();
                    num_of_obj++;
                }
            }
        }
        if (this->game_field->get_notify_flag() == 1) {
            logging_objects[num_of_obj] = this->game_field;
            num_of_obj++;
        }
        if (this->game_field->get_hero()->get_notify_flag() == 1) {
            logging_objects[num_of_obj] = this->game_field->get_hero();
            num_of_obj++;
        }
        for (int i = 0; i < num_of_obj; i++) {
            logging_objects[i]->set_notify_flag(0);
            this->logger1->output_logs(logging_objects[i]);
        }
    }
    if (this->logger2 != nullptr) {
        for (int i = 0; i < num_of_obj; i++) {
            logging_objects[i]->set_notify_flag(0);
            this->logger2->output_logs(logging_objects[i]);
        }
    }
}