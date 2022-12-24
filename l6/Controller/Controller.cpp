#include "Controller.h"


Controller::Controller(int width, int height, int level) {
    if (level != 0 && level != 1) {
        throw Controller_Exception(0);
    }
    if (width < 3 or width > 20 or height < 3 or height > 20) {
        throw Controller_Exception(2);
    }
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

Controller::Controller(Field *loaded_field) {
    auto *field_obj = loaded_field;
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
    int load_choice;
    FieldView *tmp_fieldview_obj;
    FieldView *tmp1_fieldview_obj;
    std::string save_load_path;
    this->fieldview_obj->show_field();
    Input_Output().enter_logging_msg();
    Input_Output().read_logging(logs_choice);
    if (logs_choice != 0 && logs_choice != 1 && logs_choice != 2 && logs_choice != 3) {
        throw Controller_Exception(1);
    }

    if (!std::cin) {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin.clear();
    }

        if (logs_choice == 0 || logs_choice == 1 || logs_choice == 2 || logs_choice == 3)
            this->set_logs(logs_choice);
        else
            this->set_logs(1);

    try {
        this->c_reader = new Command_Reader();
        this->c_reader->choose_commands();
    }
    catch(Command_Reader_Exception& excpt){
        std::cout << excpt.what();
        std::terminate();
    }
    auto sl_object = Save_Load(this->fieldview_obj->get_field());
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
                break;
            case Save:
                Input_Output().enter_save_msg();
                save_load_path = Input_Output().read_save();
                sl_object.save_game(save_load_path);
                break;
            case Load:
                Input_Output().enter_load_msg();
                save_load_path = Input_Output().read_load(load_choice);
                if (load_choice == 0) {
                    break;
                } //     ../Game/Save_Load/save1.txt



                else if (load_choice == 1) {
                    tmp_fieldview_obj = this->fieldview_obj;
                    try {
                        tmp1_fieldview_obj = new FieldView(sl_object.load_game(save_load_path));
                        this->fieldview_obj = tmp1_fieldview_obj;
                        this->set_logs(1);
                        this->fieldview_obj->show_field();
                        delete tmp_fieldview_obj;
                    }
                    catch (Load_Cell_Exception &excpt) {
                        std::cout << excpt.what();
                        this->fieldview_obj = tmp_fieldview_obj;
                        this->fieldview_obj->show_field();
                        break;
                    }
                    catch (Load_Field_Exception &excpt) {
                        std::cout << excpt.what();
                        this->fieldview_obj = tmp_fieldview_obj;
                        this->fieldview_obj->show_field();
                        break;
                    }
                    catch (Open_File_Error &excpt) {
                        std::cout << excpt.what();
                        this->fieldview_obj = tmp_fieldview_obj;
                        this->fieldview_obj->show_field();
                        break;
                    }
                    break;
                }


            default:
                continue;
        }
    }

}

void Controller::set_logs(int num) {
    if (num == 1) {
        this->log_observer = new Observer(this->fieldview_obj->get_field(), new Console_Log());
    }
    try {
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
    catch(File_Log_Exception& excpt){
        excpt.what();
        this->log_observer = new Observer(this->fieldview_obj->get_field(), new Console_Log());
    }
}

Controller::~Controller() {
    delete this->fieldview_obj;
}
