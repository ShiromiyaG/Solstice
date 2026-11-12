#include "types.h"

//! 0x0045B324 sub_0045B324
extern "C" void sub_0045B324(u8 *a1, unsigned int a2) {
    unsigned int v2 = *(unsigned int *)(a1 + 0x40);
    int v3;
    if (v2 > 0x5A0)
        v2 = 0x5A0;
    *(unsigned int *)(a1 + 0x40) = v2;
    if (v2 < a2)
        v3 = 0;
    else
        v3 = v2 - a2;
    *(int *)(a1 + 0x40) = v3;
}
