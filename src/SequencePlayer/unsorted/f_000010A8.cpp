#include "types.h"

// the object's vtable slot 38 (0x98) takes an int after this; the float fields are at +4.
//! SequencePlayer:0x000010A8 f_SequencePlayer_000010A8
void f_SequencePlayer_000010A8(u8 *a0, float s0, float s1, float s2) {
    float *p = (float *)(a0 + 4);
    p[0] = s0;
    p[1] = s1;
    p[2] = s2;
    void **vt = *(void ***)a0;
    ((void (*)(void *, int))vt[38])(a0, 1);
}
