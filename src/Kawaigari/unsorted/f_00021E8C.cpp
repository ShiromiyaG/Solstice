#include "types.h"

typedef void (*VirtualFn)(u8 *, u32);

// open: the game keeps the address this+0x1c in r2 for the stores; ours keeps it in r1 (2 of 6
// words differ). Tried: a three-float struct argument (it arrives in r1..r3, not s0..s2).
// the class is not known: this is shared code, so the vtable slot is called by its address.
//! Kawaigari:0x00021E8C f_Kawaigari_00021E8C
void f_Kawaigari_00021E8C(u8 *a0, f32 a1, f32 a2, f32 a3) {
    f32 *p = (f32 *)(a0 + 0x1c);
    p[0] = a1;
    p[1] = a2;
    p[2] = a3;
    VirtualFn *vt = *(VirtualFn **)a0;
    vt[38](a0, 1);
}
