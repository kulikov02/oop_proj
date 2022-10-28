#include "File_Log.h"


File_Log::File_Log( const std::string& file_path) {
    this->output_file.open(file_path);
}

void File_Log::output_logs(Observed_Obj *obj) {
    if(this->output_file.is_open())
        this->output_file << obj;
}

File_Log::~File_Log() {
    this->output_file.close();
}