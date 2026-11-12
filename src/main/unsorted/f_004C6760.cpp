#include "types.h"

// the instance and the item table are reached through pointers the game follows; the
// struct is not in include/ yet, so the offsets are written as they are (guesses).
u8 *sub_0038DDB8();
int sub_004C678C(u8 *, u32);

//! 0x004C6760 sub_004C6760
int sub_004C6760(u8 *, const u32 *a2) {
    u16 v2 = (u16)a2[1];
    u8 *s = sub_0038DDB8();
    u8 *a = *(u8 **)(s + 0x1c);
    u8 *b = *(u8 **)(a + 0x24);
    u8 *c = *(u8 **)(b + 4);
    return sub_004C678C(c + 8, v2);
}
