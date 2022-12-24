#ifndef OOP_PROJECT_LOAD_FIELD_EXCEPTION_H
#define OOP_PROJECT_LOAD_FIELD_EXCEPTION_H
#include <exception>
#include <string>

class Load_Field_Exception: public std::exception {
public:
    std::string what();

};


#endif //OOP_PROJECT_LOAD_FIELD_EXCEPTION_H
