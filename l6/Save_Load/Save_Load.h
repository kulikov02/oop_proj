#ifndef OOP_PROJECT_SAVE_LOAD_H
#define OOP_PROJECT_SAVE_LOAD_H
#include "../Map/Field/Field.h"
#include "../Map/Field_Event_filler/Field_Event_Filler.h"
#include "Open_File_Error.h"
#include <fstream>


class Save_Load {
    Field* field_object;
public:
    explicit Save_Load(Field* field_object = nullptr);
    void save_game(const std::string& saving_path);
    Field* load_game(const std::string& load_path);
};


#endif //OOP_PROJECT_SAVE_LOAD_H
