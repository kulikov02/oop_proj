#include "Console_Command_Giver.h"

std::string Console_Command_Giver::get_commands_from_user() {
    std::string command;
    std::cin >> command;
    return command;
}