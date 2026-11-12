#include "types.h"

namespace gfl2 { namespace debug { void GFLassert(const char *, unsigned int, int, const char *); } }

// callees without names: f_FinderStudioCapture_000005DC takes the viewer, f_FinderStudioCapture_0000633C is the tail call
void f_FinderStudioCapture_000005DC(void *viewer);
void *f_FinderStudioCapture_0000633C(void *p);

//! FinderStudioCapture:0x00006300 f_FinderStudioCapture_00006300
void *f_FinderStudioCapture_00006300(u8 *a1) {
    if (!*(u32 *)(a1 + 4)) {
        gfl2::debug::GFLassert(0, 0, 0, 0);
    }
    f_FinderStudioCapture_000005DC(*(void **)(a1 + 4));
    return f_FinderStudioCapture_0000633C(a1);
}
