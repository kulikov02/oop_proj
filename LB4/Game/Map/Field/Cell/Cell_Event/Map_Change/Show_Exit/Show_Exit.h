#ifndef OOP_PROJECT_SHOW_EXIT_H
#define OOP_PROJECT_SHOW_EXIT_H
#include "../Map_Change.h"

class Show_Exit: public Map_Change {
public:
    explicit Show_Exit(Field* field);
    void set_exit_shown_flag();
    void interact() override;
    std::string get_log() override;

};


#endif //OOP_PROJECT_SHOW_EXIT_H
