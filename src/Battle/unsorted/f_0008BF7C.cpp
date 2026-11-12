#include "types.h"

// open: the game loads both words before storing them, with ldr/str pairs. Tried: loads and stores
// in both orders, and a two-word struct copy (which the compiler turns into ldm/stm).
//! Battle:0x0008BF7C f_Battle_0008BF7C
u32 *f_Battle_0008BF7C(u32 *a0, u32 *a1) {
    u32 x = a1[0];
    u32 y = a1[1];
    a0[0] = x;
    a0[1] = y;
    return a0;
}
