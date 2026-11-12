#include "types.h"

namespace gfl2 {
namespace debug {
void GFLassert(const char *, u32, s32, const char *);
}
}

extern "C" u32 f_NBR_00006F98();

//! NBR:0x00009AFC f_NBR_00009AFC
extern "C" u32 f_NBR_00009AFC(u8 *self)
{
    u32 idx = f_NBR_00006F98();
    if (idx >= 4) {
        gfl2::debug::GFLassert(0, 0, 0, 0);
    }
    return *(u32 *)(self + idx * 4 + 0x6c);
}
