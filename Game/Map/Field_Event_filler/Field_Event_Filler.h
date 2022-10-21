#ifndef OOP_PROJECT_FIELD_EVENT_FILLER_H
#define OOP_PROJECT_FIELD_EVENT_FILLER_H
#include "../Field/Field.h"
#include "../Field/Cell/Cell_Event/Trap/Fire_Trap/Fire_Trap.h"
#include "../Field/Cell/Cell_Event/Trap/Frost_Trap/Frost_Trap.h"
#include "../Field/Cell/Cell_Event/Map_Change/Show_Exit/Show_Exit.h"
#include "../Field/Cell/Cell_Event/Map_Change/Break_Walls/Break_Walls.h"
#include "../Field/Cell/Cell_Event/Stats_Change/Increase_Health/Increase_Health.h"
#include "../Field/Cell/Cell_Event/Stats_Change/Increase_Frost_Armor/Increase_Frost_Armor.h"
#include "../Field/Cell/Cell_Event/Stats_Change/Increase_Fire_Armor/Increase_Fire_Armor.h"
#include "../Field/Cell/Cell_Event/Stats_Change/Increase_Agility/Increase_Agility.h"
#include <ctime>

class Field_Event_Filler {
    Field* field_obj;
public:
    explicit Field_Event_Filler(Field* field);
    void fill_the_field();
};


#endif //OOP_PROJECT_FIELD_EVENT_FILLER_H
