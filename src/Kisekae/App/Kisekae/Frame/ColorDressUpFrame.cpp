#include "types.h"

namespace gfl2 { namespace debug { void GFLassert(const char *, u32, int, const char *); } }

// sub_6370 (Kisekae:00006370), not named yet: a guess of its parameters from the call
u32 f_Kisekae_00006370(u32 a1, u32 a2);

//! Kisekae:0x0000A5DC f_Kisekae_0000A5DC
u32 f_Kisekae_0000A5DC(u8 *a1)
{
    u32 v1 = *(u32 *)(*(u8 **)(a1 + 4) + 0x44);
    if (!v1)
        gfl2::debug::GFLassert(0, 0, 0, 0);
    return f_Kisekae_00006370(v1, 1);
}
