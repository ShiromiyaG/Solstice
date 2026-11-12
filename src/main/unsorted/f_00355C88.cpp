#include "types.h"

extern "C" int sub_003563F4(void *a, int b, int c, int d);
extern "C" void *data_00670D34;

// open: the game's code stores r12 as a fifth argument at [sp] (str ip,[sp]) before the call,
// and this source passes four. Not reached yet; a fifth argument with no source is not written.
//! 0x00355C88 sub_00355C88
extern "C" int sub_00355C88(int a1, int a2, int a3) {
    return sub_003563F4(data_00670D34, 3, a3, a2);
}
