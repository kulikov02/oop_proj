#ifndef OOP_PROJECT_CONSOLE_COMMAND_GIVER_H
#define OOP_PROJECT_CONSOLE_COMMAND_GIVER_H
#include "../Command_Giver.h"

class Console_Command_Giver: public Command_Giver {
public:
    std::string get_commands_from_user() override;
};


#endif //OOP_PROJECT_CONSOLE_COMMAND_GIVER_H
