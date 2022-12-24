#ifndef OOP_PROJECT_COMMAND_READER_EXCEPTION_H
#define OOP_PROJECT_COMMAND_READER_EXCEPTION_H
#include <exception>
#include <string>

class Command_Reader_Exception:std::exception {
int error_id;
int error_id2;
public:
    Command_Reader_Exception(int err_id,int err_id2 = -1);
    std::string what();
};


#endif //OOP_PROJECT_COMMAND_READER_EXCEPTION_H
