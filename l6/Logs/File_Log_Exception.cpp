#include "File_Log_Exception.h"

std::string File_Log_Exception::what() {
    return "Could not open file for logging at given path";
}
