#include "Observed_Obj.h"

void Observed_Obj::notify() {
    this->notify_flag = 1;
}

void Observed_Obj::set_notify_flag(int num) {
    this->notify_flag = num;
}

int Observed_Obj::get_notify_flag() {
    return this->notify_flag;
}

std::ostream &operator<<(std::ostream &out, Observed_Obj *other_subject) {
    out << other_subject->get_log() << std::endl;
    return out;
}
