#ifndef OOP_PROJECT_OPEN_FILE_ERROR_H
#define OOP_PROJECT_OPEN_FILE_ERROR_H
#include <string>
#include <exception>

class Open_File_Error:public std::exception {
public:
    std::string what();
};


#endif //OOP_PROJECT_OPEN_FILE_ERROR_H
