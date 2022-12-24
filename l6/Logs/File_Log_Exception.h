#ifndef OOP_PROJECT_FILE_LOG_EXCEPTION_H
#define OOP_PROJECT_FILE_LOG_EXCEPTION_H

#include <string>
#include <exception>


class File_Log_Exception : public std::exception {
public:
    std::string what();
};


#endif //OOP_PROJECT_FILE_LOG_EXCEPTION_H
