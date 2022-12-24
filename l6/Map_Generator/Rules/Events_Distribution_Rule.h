#ifndef OOP_PROJECT_EVENTS_DISTRIBUTION_RULE_H
#define OOP_PROJECT_EVENTS_DISTRIBUTION_RULE_H


#include "../../Map/Field/Field.h"

template <int n>
class Events_Distribution_Rule {
public:
    void set_event_distribution(Field* field){
        if(n == 0){
            return;
        }
        if(n == 1){
            for(int i = 0;i < field->get_width();i+=2){
                for(int j = 0;j < field->get_height();j+=2){
                    field->get_field()[i][j].set_event(nullptr);
                }
            }
        }
    }


};


#endif //OOP_PROJECT_EVENTS_DISTRIBUTION_RULE_H
