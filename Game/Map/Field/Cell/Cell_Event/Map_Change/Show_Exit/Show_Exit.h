#ifndef OOP_PROJECT_SHOW_EXIT_H
#define OOP_PROJECT_SHOW_EXIT_H
#include "../Map_Change.h"

class Show_Exit: public Map_Change {
public:
    Show_Exit(Cell** map, int width, int height);
    void set_exit_shown_flag();
    void interact(Player* hero, int player_x_coord, int player_y_coord) override;

};


#endif //OOP_PROJECT_SHOW_EXIT_H
