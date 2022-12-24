#include "Controller_Exception.h"

Controller_Exception::Controller_Exception(int error_id) {
    this->error_id = error_id;
}

std::string Controller_Exception::what() {
    if(this->error_id == 0){
        return "This level does not exist\n";
    }
    if(this->error_id == 1){
        return "This logging does not exist\n";
    }
    if(this->error_id == 2){
        return "Width or height is incorrect\n";
    }
}
