#include "Save_Load.h"

Save_Load::Save_Load(Field *field_object) {
    this->field_object = field_object;
}

void Save_Load::save_game(const std::string &saving_path) {
    std::string save_cell_arr[this->field_object->get_width()][this->field_object->get_height()];
    for (int i = 0; i < this->field_object->get_width(); i++) {
        for (int j = 0; j < this->field_object->get_height(); j++) {
            save_cell_arr[i][j] = this->field_object->get_field()[i][j].save();
        }
    }
    std::string save_field_str = this->field_object->save();
    std::fstream saving_file;
    saving_file.open(saving_path);
    if (saving_file.is_open()) {
        saving_file << save_field_str << "\n";

        for (int i = 0; i < this->field_object->get_width(); i++) {
            for (int j = 0; j < this->field_object->get_height(); j++) {
                saving_file << save_cell_arr[i][j] << "\n";
            }
        }
        saving_file.close();
    }
}

Field *Save_Load::load_game(const std::string &load_path) {
    std::ifstream loading_file;
    loading_file.open(load_path);
    std::string load_field_str;
    std::string load_cell_str;
    if (loading_file.is_open() == 0) {
        throw Open_File_Error();
    }
    std::getline(loading_file, load_field_str);
    auto *ret_field = new Field();
    ret_field->restore(load_field_str);

    int i = 0;
    int j = 0;
    for (i = 0; i < ret_field->get_width(); i++) {
        for (j = 0; j < ret_field->get_height(); j++) {
            try {
                std::getline(loading_file, load_cell_str);
                ret_field->get_field()[i][j].restore(load_cell_str);
            }
            catch (Load_Cell_Exception &excpt) {
                throw Load_Cell_Exception(i, j);
            }
        }


    }
    Field_Event_Filler fif_obj(ret_field);
    fif_obj.fill_loading_field(ret_field);


    return ret_field;

}
