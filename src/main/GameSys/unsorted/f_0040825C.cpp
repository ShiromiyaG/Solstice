#include "types.h"

extern "C" void sub_0045B348(u8 *);
extern "C" u16 *sub_003AA2D0(u8 *, u32);

//! 0x0040825C f_0040825C
extern "C" void f_0040825C(u8 *self)
{
    u8 *save = *(u8 **)(self + 4);
    sub_0045B348(save + 0x3b38);
    u16 *flag = sub_003AA2D0(*(u8 **)(self + 4) + 0x15d8, 0x40a0);
    *flag = 1;
}
