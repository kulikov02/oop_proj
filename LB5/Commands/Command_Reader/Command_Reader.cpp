#include "Command_Reader.h"
#include <fstream>

Command_Reader::Command_Reader() {
    if(this->giver_flag == 0){
        this->input = new Console_Command_Giver();
    }
}

void Command_Reader::choose_commands() {
    std::ifstream file;
    file.open(std::string("../Game/Commands/Command_Reader/control_options.txt"));
    for(int i = 0; i < 6;i++){
        std::getline(file,this->commands_arr[i]);
    }
}

prog_commands Command_Reader::input_commands() {
    std::string command = this->input->get_commands_from_user();
    if(command == this->commands_arr[0]){
        return MoveUp;
    }
    if(command == this->commands_arr[1]){
        return MoveLeft;
    }
    if(command == this->commands_arr[2]){
        return MoveDown;
    }
    if(command == this->commands_arr[3]){
        return MoveRight;
    }
    if(command == this->commands_arr[4]){
        return ExitGame;
    }
    if(command == this->commands_arr[5]){
        return Stats;
    }
    else{
        return Incorrect;
    }

}
