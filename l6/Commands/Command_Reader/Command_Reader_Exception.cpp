#include "Command_Reader_Exception.h"

Command_Reader_Exception::Command_Reader_Exception(int err_id,int err_id2) {
    this->error_id = err_id;
    this->error_id2 = err_id2;
}

std::string Command_Reader_Exception::what() {
    if(this->error_id == 0){
        return "Could not open config file with commands at this path\n";
    }
    if(this->error_id == 1){
        return "Command " + std::to_string(this->error_id2) + " is written incorrect in config file\n";
    }
}