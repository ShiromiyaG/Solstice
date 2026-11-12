#include "types.h"

void f_JoinFesta_00000B10(u32);
void f_JoinFesta_00000B18(u32);

//! JoinFesta:0x0000C8E4 f_JoinFesta_0000C8E4
void f_JoinFesta_0000C8E4(u8 *a0) {
    if (*(u32 *)(a0 + 0x14)) {
        f_JoinFesta_00000B10(*(u32 *)(a0 + 0x14));
    }
    if (*(u32 *)(a0 + 0x18)) {
        f_JoinFesta_00000B18(*(u32 *)(a0 + 0x18));
    }
}
