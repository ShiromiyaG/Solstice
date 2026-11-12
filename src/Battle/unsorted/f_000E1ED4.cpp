#include "types.h"

namespace gfl2 {
namespace debug {
void GFLassert(const char *, u32, s32, const char *);
}
}

// guess: a flag array at +0xa38 (2616) of a battle object
//! Battle:0x000E1ED4 f_Battle_000E1ED4
bool f_Battle_000E1ED4(u8 *a1, u32 a2) {
    if (a2 < 4) {
        return *(a1 + a2 + 2616) != 0;
    }
    gfl2::debug::GFLassert(0, 0, 0, 0);
    return 1;
}
