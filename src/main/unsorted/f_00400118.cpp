#include "types.h"

// guess: the object's layout is not known; only the offsets this function uses.
struct Obj_00400118 {
    u8 unk_0[0x26];
    u8 field_26;  // guess: a byte flag
    u8 unk_27[0x2c - 0x27];
    s32 field_2c;  // guess: a value, 0 becomes 1
    s32 field_30;  // guess: zeroed
};

//! 0x00400118 f_00400118
void f_00400118(Obj_00400118 *a1, s32 a2)
{
    a1->field_26 = 2;
    if (!a2) {
        a2 = 1;
    }
    a1->field_2c = a2;
    a1->field_30 = 0;
}
