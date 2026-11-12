#include "types.h"

u32 f_BoxSearch_0000445C(void *);

// open: the game keeps the pointer in r0 and loads the constant 0 into r2; this
// source gives r1 (a register swap). tried: a pointer local, a result local, a zero local.
//! BoxSearch:0x00001F80 f_BoxSearch_00001F80
u32 f_BoxSearch_00001F80(u8 *a1)
{
    u32 result = *(u32 *)(a1 + 0x4c);
    if (result != 0) {
        *(u16 *)(result + 6) = 0;
        result = *(u32 *)(a1 + 0xa4);
        if (result == 2) {
            result = f_BoxSearch_0000445C(*(void **)(a1 + 0x68));
            *(u16 *)(*(u32 *)(a1 + 0x4c) + 6) = result;
        }
    }
    return result;
}
