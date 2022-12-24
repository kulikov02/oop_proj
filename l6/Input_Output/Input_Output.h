#ifndef OOP_PROJECT_INPUT_OUTPUT_H
#define OOP_PROJECT_INPUT_OUTPUT_H
#include <iostream>

class Input_Output {
public:
    void enter_w_h_msg();
    void enter_level_msg();
    void enter_logging_msg();
    void enter_load_msg();
    void enter_save_msg();
    std::string read_save();
    std::string read_load(int& sl_choice);
    void read_w_h(int& height,int& width);
    void read_level(int& level);
    void read_logging(int& logging);

};


#endif //OOP_PROJECT_INPUT_OUTPUT_H
