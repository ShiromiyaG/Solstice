#include "types.h"

namespace gfl2 { namespace debug { void GFLassert(const char *, u32, s32, const char *); } }

//! Resort:0x00004660 f_Resort_00004660
u32 f_Resort_00004660(u8 *a0)
{
    u8 *v1 = *(u8 **)(a0 + 0x38);
    if (v1 != 0) {
        return v1[0xa8];
    }
    gfl2::debug::GFLassert(0, 0, 0, 0);
    return 0;
}
