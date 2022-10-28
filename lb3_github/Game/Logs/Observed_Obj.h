#ifndef OOP_PROJECT_OBSERVED_OBJ_H
#define OOP_PROJECT_OBSERVED_OBJ_H
#include <iostream>



class Observed_Obj {
protected:
    int notify_flag = 0;
public:
    void notify();
    void set_notify_flag(int num);
    int get_notify_flag();
    virtual std::string get_log() = 0;
    friend std::ostream& operator<<(std::ostream &out, Observed_Obj* other_subject);
};


#endif //OOP_PROJECT_OBSERVED_OBJ_H
