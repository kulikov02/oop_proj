#include "Controller.h"


Controller::Controller(int width, int height) {

    auto *field_obj = new Field(height, width);
    auto *field_event_filler_obj = new Field_Event_Filler(field_obj);
    field_event_filler_obj->fill_the_field();
    auto *fieldview = new FieldView(field_obj);
    this->fieldview_obj = fieldview;
}


int Controller::is_player_dead_or_won() {
    if (this->fieldview_obj->get_field()->get_hero()->get_player_health() <= 0) {
        this->fieldview_obj->player_dead();
        return 1;
    }
    if (this->fieldview_obj->get_field()->get_current_player_cell()->get_cell_type() == Exit) {
        this->fieldview_obj->player_won();
        return 1;
    }
    return 0;
}

void Controller::start_game() {
    char choice;
    int logs_choice;
    this->fieldview_obj->show_field();
    std::cout << "Choose the way of logging. 0 - No logs, 1 - Console logs, 2 -logs in logs.txt logs , 3 - both logs\n";
    std::cin >> logs_choice;
    this->set_logs(logs_choice);
    this->c_reader = new Command_Reader();
    this->c_reader->choose_commands();
    while (true) {
        choice = this->c_reader->input_commands();
        switch (choice) {
            case 'w':
                this->fieldview_obj->get_field()->move_player(0, 1);
                this->fieldview_obj->show_field();
                if (logs_choice != 0)
                    this->log_observer->update();
                if (this->is_player_dead_or_won() == 1) {
                    return;
                }
                break;
            case 'a':
                this->fieldview_obj->get_field()->move_player(-1, 0);
                this->fieldview_obj->show_field();
                if (logs_choice != 0)
                    this->log_observer->update();
                if (this->is_player_dead_or_won() == 1) {
                    return;
                }
                break;

            case 's':
                this->fieldview_obj->get_field()->move_player(0, -1);
                this->fieldview_obj->show_field();
                if (logs_choice != 0)
                    this->log_observer->update();
                if (this->is_player_dead_or_won() == 1) {
                    return;
                }
                break;

            case 'd':
                this->fieldview_obj->get_field()->move_player(1, 0);
                this->fieldview_obj->show_field();
                if (logs_choice != 0)
                    this->log_observer->update();
                if (this->is_player_dead_or_won() == 1) {
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

void Controller::set_logs(int num) {
    if (num == 1) {
        this->log_observer = new Observer(this->fieldview_obj->get_field(), new Console_Log());
    }
    if (num == 2) {
        this->log_observer = new Observer(this->fieldview_obj->get_field(), new File_Log(std::string("../Game/Logs/logs.txt")));
    }
    if (num == 3) {
        this->fieldview_obj->get_field()->set_loggers_amount(2);
        this->log_observer = new Observer(this->fieldview_obj->get_field(), new Console_Log(),
                                          new File_Log(std::string("../Game/Logs/logs.txt")));
    }
}

Controller::~Controller() {
    delete this->fieldview_obj;
}