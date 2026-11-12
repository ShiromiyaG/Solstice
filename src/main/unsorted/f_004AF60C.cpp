#include "types.h"

// callees without names: sub_00322CB0 (no arguments), sub_00322C38 (this), sub_004AF23C returns a pointer to a record
void sub_00322CB0();
void sub_00322C38(const u8 *a1);
u8 *sub_004AF23C(const u8 *a1, int a2);

// the member of pml::pokepara::CoreParam is not known yet (its name lies between GetGetBall and GetSeikaku)
//! 0x004AF60C sub_004AF60C
int sub_004AF60C(const u8 *a1) {
    sub_00322CB0();
    u8 v2 = *(u8 *)(sub_004AF23C(a1, 0) + 44);
    sub_00322C38(a1);
    return v2;
}
