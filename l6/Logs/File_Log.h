#ifndef OOP_PROJECT_FILE_LOG_H
#define OOP_PROJECT_FILE_LOG_H
#include "ILogger.h"
#include "File_Log_Exception.h"
#include <fstream>

class File_Log:public ILogger  {
std::ofstream output_file;
public:
    explicit File_Log(const std::string& file_path);
    void output_logs(Observed_Obj* obj) override;
    ~File_Log();
};


#endif //OOP_PROJECT_FILE_LOG_H
