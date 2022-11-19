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

char Command_Reader::input_commands() {
    std::string command = this->input->get_commands_from_user();
    if(command == this->commands_arr[0]){
        return 'w';
    }
    if(command == this->commands_arr[1]){
        return 'a';
    }
    if(command == this->commands_arr[2]){
        return 's';
    }
    if(command == this->commands_arr[3]){
        return 'd';
    }
    if(command == this->commands_arr[4]){
        return 'e';
    }
    if(command == this->commands_arr[5]){
        return 'c';
    }
    else{
        return 'p';
    }

}
