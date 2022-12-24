#include "Open_File_Error.h"

std::string Open_File_Error::what() {
    return "Could not open file from this path\n";
}
