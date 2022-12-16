#include "Input_Output.h"
#include <iostream>

void Input_Output::enter_level_msg() {
    std::cout<<"Choose the level (1 or 0)\n";
}

void Input_Output::enter_logging_msg() {
    std::cout << "Choose the way of logging. 0 - No logs, 1 - Console logs, 2 -logs in logs.txt logs , 3 - both logs\n";
}

void Input_Output::enter_w_h_msg() {
    std::cout<<"Enter the height and width\n";
}

void Input_Output::read_level(int& level) {
    std::cin >> level;
}

void Input_Output::read_logging(int& logging) {
    std::cin >> logging;
}

void Input_Output::read_w_h(int& height,int& width) {
    std:: cin >> width >> height;
}
