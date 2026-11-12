#include "types.h"

namespace gfl2 {
namespace debug {
void GFLassert(const char *, u32, s32, const char *);
}
}

// callee without a name: f_FieldRo_000007B4 (the packet's bl #0x7b4)
void f_FieldRo_000007B4(s32 p);

// guess: the layout of the chain from a1 is taken from the packet
struct FieldRoChainA { u8 unk_0[0x44]; u8 *p44; };
struct FieldRoChainB { u8 unk_0[0x94]; u8 *p94; };
struct FieldRoChainC { u8 unk_0[0x2c]; u8 *p2c; };

//! FieldRo:0x0000CBFC f_FieldRo_0000CBFC
s32 f_FieldRo_0000CBFC(s32 a1) {
    s32 v1 = *(s32 *)(*(u8 **)(*(u8 **)(*(u8 **)(a1 + 0x44) + 0x94) + 0x2c) + 0xdc);
    if (!v1) {
        gfl2::debug::GFLassert(0, 0, 0, 0);
    }
    f_FieldRo_000007B4(v1);
    return 0;
}
