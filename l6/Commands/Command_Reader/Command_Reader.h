#ifndef OOP_PROJECT_COMMAND_READER_H
#define OOP_PROJECT_COMMAND_READER_H
#include <iostream>
#include "Command_Reader_Exception.h"

#include "../Command_Giver/Console_Command_Giver/Console_Command_Giver.h"

enum prog_commands{
    MoveUp,MoveLeft,MoveDown,MoveRight,ExitGame,Stats,Load,Save,Incorrect
};

class Command_Reader {
    Command_Giver* input;
    std::string commands_arr[8];
    int giver_flag = 0;
public:
    explicit Command_Reader();
    void choose_commands();
    prog_commands input_commands();

};


#endif //OOP_PROJECT_COMMAND_READER_H
