#include "types.h"

void f_EndRoll_000002D8(u32);

//! EndRoll:0x00000D68 f_EndRoll_00000D68
void f_EndRoll_00000D68(u8 *a0) {
    f_EndRoll_000002D8(*(u32 *)(a0 + 0x4));
    f_EndRoll_000002D8(*(u32 *)(a0 + 0x8));
}
