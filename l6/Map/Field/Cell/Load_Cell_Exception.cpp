#include "Load_Cell_Exception.h"


Load_Cell_Exception::Load_Cell_Exception(int x, int y) {
    this->x = x;
    this->y = y;
}
std::string Load_Cell_Exception::what() {
    return "Error occured during loading cell [" + std::to_string(x) + std::string("]") + std::string("[") +
           std::to_string(y) + std::string("]") + '\n';
}