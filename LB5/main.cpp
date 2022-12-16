#include "Map/FieldView/FieldView.h"
#include "Controller/Controller.h"

int main() {

    int height, width;
    Input_Output().enter_w_h_msg();
    Input_Output().read_w_h(height,width);
    int level;
    Input_Output().enter_level_msg();
    Input_Output().read_level(level);
    Controller game_controller = Controller(width,height,level);
    game_controller.start_game();
    return 0;
}
