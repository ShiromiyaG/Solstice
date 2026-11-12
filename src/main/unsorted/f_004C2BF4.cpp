#include "types.h"

u32 sub_005AF7E4(u8 *, u32, u32);
extern "C" u32 data_005E8810[2];

//! 0x004C2BF4 poke_3d::model const member (class unknown)
u32 f_004C2BF4(u8 *a1)
{
    return sub_005AF7E4(a1, data_005E8810[0], data_005E8810[1]);
}
