#ifndef OOP_PROJECT_BREAK_WALLS_H
#define OOP_PROJECT_BREAK_WALLS_H
#include "../Map_Change.h"

class Break_Walls: public Map_Change {
public:
    explicit Break_Walls(Field* field);
    void interact() override;
    void break_walls_around();
    std::string get_log() override;
    std::string get_str() override;

};


#endif //OOP_PROJECT_BREAK_WALLS_H
