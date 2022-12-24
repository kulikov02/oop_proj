#ifndef OOP_PROJECT_COMMAND_GIVER_H
#define OOP_PROJECT_COMMAND_GIVER_H
#include <iostream>

class Command_Giver {
public:
    virtual std::string get_commands_from_user() = 0;
};


#endif //OOP_PROJECT_COMMAND_GIVER_H
