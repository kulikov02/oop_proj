#include "Controller.h"


Controller::Controller(int width, int height, int level) {
    if (level == 1) {
        Map_Generator<1, 1, 1, 1, 1, 1> map_generator_obj(height, width);
        auto *field_obj = map_generator_obj.get_game_field();
        auto *fieldview = new FieldView(field_obj);
        this->fieldview_obj = fieldview;
    } else {
        Map_Generator<0, 0, 0, 0, 0, 0> map_generator_obj(height, width);
        auto *field_obj = map_generator_obj.get_game_field();
        auto *fieldview = new FieldView(field_obj);
        this->fieldview_obj = fieldview;
    }

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
    Input_Output().enter_logging_msg();
    Input_Output().read_logging(logs_choice);

    if(!std::cin){
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.clear();
    }
    if (logs_choice == 0 || logs_choice == 1 || logs_choice == 2 || logs_choice == 3)
        this->set_logs(logs_choice);
    else
        this->set_logs(1);
    this->c_reader = new Command_Reader();
    this->c_reader->choose_commands();
    while (true) {
        choice = this->c_reader->input_commands();
        switch (choice) {
            case MoveUp:
                this->fieldview_obj->get_field()->move_player(0, 1);
                this->fieldview_obj->show_field();
                if (logs_choice != 0)
                    this->log_observer->update();
                if (this->is_player_dead_or_won() == 1) {
                    return;
                }
                break;
            case MoveLeft:
                this->fieldview_obj->get_field()->move_player(-1, 0);
                this->fieldview_obj->show_field();
                if (logs_choice != 0)
                    this->log_observer->update();
                if (this->is_player_dead_or_won() == 1) {
                    return;
                }
                break;

            case MoveDown:
                this->fieldview_obj->get_field()->move_player(0, -1);
                this->fieldview_obj->show_field();
                if (logs_choice != 0)
                    this->log_observer->update();
                if (this->is_player_dead_or_won() == 1) {
                    return;
                }
                break;

            case MoveRight:
                this->fieldview_obj->get_field()->move_player(1, 0);
                this->fieldview_obj->show_field();
                if (logs_choice != 0)
                    this->log_observer->update();
                if (this->is_player_dead_or_won() == 1) {
                    return;
                }
                break;

            case ExitGame:
                return;
            case Stats:
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
        this->log_observer = new Observer(this->fieldview_obj->get_field(),
                                          new File_Log(std::string("../Game/Logs/logs.txt")));
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