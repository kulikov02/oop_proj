#include "Map/FieldView/FieldView.h"
#include "Controller/Controller.h"

int main() {
    int load_choice;
    std::string load_path;
    Input_Output().enter_load_msg();
    load_path = Input_Output().read_load(load_choice);
    if (load_choice == 0) {
        int height, width;
        Input_Output().enter_w_h_msg();
        Input_Output().read_w_h(height, width);
        int level;
        Input_Output().enter_level_msg();
        Input_Output().read_level(level);
        try {
            Controller game_controller = Controller(width, height, level);
            game_controller.start_game();
        }
        catch(Controller_Exception& excpt){
            std::cout<<excpt.what();
            std::terminate();
        }
        return 0;
    } else if (load_choice == 1) {
        try {
            Controller game_controller = Controller(Save_Load().load_game(load_path));
            game_controller.start_game();
        }

        catch (Load_Cell_Exception &excpt) {
            std::cout << excpt.what();
            std::terminate();
        }
        catch (Load_Field_Exception &excpt) {
            std::cout << excpt.what();
            std::terminate();
        }
        catch (Open_File_Error &excpt) {
            std::cout << excpt.what();
            std::terminate();

        }

    }
}
