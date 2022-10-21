#include "Map/FieldView/FieldView.h"
#include "Controller/Controller.h"

int main() {
    int height, width;
    std:: cin >> width >> height;
    Controller game_controller = Controller(width,height);
    game_controller.start_game();
    return 0;
}
