#include "types.h"

//! Battle:0x000E1FE4 f_Battle_000E1FE4
bool f_Battle_000E1FE4(u8 *a0)
{
    if (*(u8 *)(*(u32 *)(a0 + 12) + 0x32f) != 0) {
        return 0;
    }
    return 1;
}
