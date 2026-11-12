#include "types.h"

// the global array of four pointers (data_006A5DB8)
extern int data_006A5DB8[];

// counts the entries whose object has a non-zero word at +0x5018. the object's part at +0x5000
// is taken as its own pointer first, as the game's code adds 0x5000 before the load.
// open: the loop is the game's (four entries, signed index), but armcc -O3 unrolls it (128 bytes
// against 60). tried: a for loop with the index in it (unrolled), an unsigned index (no unroll,
// but blo for blt: 1 word differs, not a match), an index declared before the loop (unrolled),
// and a while loop (unrolled).
//! 0x00415974 sub_00415974
int sub_00415974() {
    int result = 0;
    for (int i = 0; i < 4; ++i) {
        int v2 = data_006A5DB8[i];
        if (v2) {
            int *p = (int *)(v2 + 0x5000);
            if (p[6]) {
                ++result;
            }
        }
    }
    return result;
}
