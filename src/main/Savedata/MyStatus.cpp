#include "types.h"

extern "C" void sub_0035FCA4(u32, u8 *, u32);

// open: GetNameString of Savedata::MyStatus. the method is not declared in
// include/Savedata/MyStatus.h (generated), so this is a free function for now. the code
// has no call: it falls into the next function, 0x0035FCA4, after a nop.
//! 0x0035FC90 f_0035FC90
extern "C" void f_0035FC90(u8 *self, u32 arg)
{
    sub_0035FCA4(arg, self + 0x40, 13);
}
