#include "types.h"

// callee without a name, the packet's bl #0x57477c: this, then 4 words from the caller's r1..r3 and 4 zero stack words
s32 sub_0057477C(void *a, u32 b, u32 c, u32 d, u32 e, u32 f, u32 g, u32 h);

//! 0x004D30AC f_004D30AC
s32 f_004D30AC(u8 *a1, u32 b, u32 c, u32 d) {
    return sub_0057477C(a1 - 0x5c, b, c, d, 0, 0, 0, 0);
}
