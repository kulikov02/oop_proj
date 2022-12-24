#ifndef OOP_PROJECT_CONTROLLER_EXCEPTION_H
#define OOP_PROJECT_CONTROLLER_EXCEPTION_H
#include<exception>
#include <string>

class Controller_Exception:public std::exception {
int error_id;
public:
    Controller_Exception(int error_id);
    std::string what();
};


#endif //OOP_PROJECT_CONTROLLER_EXCEPTION_H
