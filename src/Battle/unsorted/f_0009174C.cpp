#include "types.h"

//! Battle:0x0009174C f_Battle_0009174C
extern "C" void f_Battle_0009174C(u8 *a1, int a2) {
    u16 v2 = *(u16 *)(a1 + 0xe);
    u16 v3 = (u16)(a2 + *(u16 *)(a1 + 0x10));
    *(u16 *)(a1 + 0x10) = v3;
    if (v3 > v2)
        *(u16 *)(a1 + 0x10) = v2;
}
