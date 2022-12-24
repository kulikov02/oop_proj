#ifndef OOP_PROJECT_LOAD_CELL_EXCEPTION_H
#define OOP_PROJECT_LOAD_CELL_EXCEPTION_H
#include <exception>
#include <string>

class Load_Cell_Exception:public std::exception {
    int x;
    int y;
public:
    Load_Cell_Exception(int x = 0,int y = 0);
    std::string what();
};


#endif //OOP_PROJECT_LOAD_CELL_EXCEPTION_H
