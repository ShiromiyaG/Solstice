#include "btl/BtlvObject_Chara.h"

// f_Battle_00000BE8: the function at Battle:0x0BE8, name from its address (guess of its parameter type).
void f_Battle_00000BE8(void *);

//! Battle:0x000412C8 vf59
void btl::BtlvObject_Chara::vf59() {
    f_Battle_00000BE8(this);
    f_Battle_00000BE8((void *)&field_344);
}
