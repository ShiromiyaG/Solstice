#include "types.h"

// the class is not known (Field's sound set); its fields are words at their offsets (guesses).
// the order of the stores is the game's (found by tools/local/permute.py, then written plainly).
//! 0x0037E7D0 sub_0037E7D0
void sub_0037E7D0(u32 *result, u32 *a2) {
    result[1] = (u32)a2;
    result[2] = a2[21];
    result[13] = 0;
    result[5] = 0xffffffffu;
    result[3] = 0;
}
