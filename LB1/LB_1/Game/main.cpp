#include "Map/FieldView.h"
#include "Controller.h"

int main() {
    Controller game_controller = Controller();
    int height, width;
    std:: cin >> width >> height;
    game_controller.set_field_size(width, height);
    game_controller.start_game();
    return 0;
}
