#include "types.h"

// copies three words to +0x54..+0x5c and sets the flag at +0x38. the struct is not known yet.
// open: the three copies match, but the compiler puts `mov #1` before the first store; the game
// loads the words and stores each one, then sets the flag in r1 (the register a2[2] was loaded
// into). tried: a struct copy (ldm/strd, 24 bytes), a struct member copy per word, and word
// indexed stores with the flag last (this one; 7 words differ).
//! Battle:0x00040224 f_Battle_00040224
void f_Battle_00040224(u8 *a1, u32 *a2) {
    u32 *dst = (u32 *)a1;
    dst[0x54 / 4] = a2[0];
    dst[0x58 / 4] = a2[1];
    dst[0x5c / 4] = a2[2];
    a1[0x38] = 1;
}
