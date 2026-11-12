#include "types.h"

// the game's Battle module: data at 0x13C3AC (a guess: a plain u32 global).
extern u32 data_0013C3AC;
u32 f_Battle_00078664(void *, u32);

// open: the game compares the global with 3601 and stores it through a register pair
// the compiler swaps (the address in r2 and the constant in r1 in the game; the reverse here).
// tried: a plain global, a pointer local, both give the same swap.
//! Battle:0x0003A068 f_Battle_0003A068
u32 f_Battle_0003A068(u8 *a1)
{
    u32 *flag = &data_0013C3AC;
    if (*flag != 3601) {
        *flag = 3601;
    }
    return f_Battle_00078664(*(void **)(a1 + 216), 0);
}

