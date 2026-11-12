#include "types.h"

namespace gfl2 { namespace heap { void GflHeapFreeMemoryBlock(void *block); } }

// callees without names: sub_002B8E24 takes two words (its library is not known). the class is not
// known (its name lies between gfl2::debug::GFLassert and gfl2::Effect::EffectRenderPath::Execute);
// the slot is at +0x838 (a guess: a block of the heap), reached as +0x800 then +0x38.
// open: the game tests the slot, branches over the free, and stores 0 through the slot after it
// (both paths meet at the store). tried: the slot from this + 0x838; the store inside the nonzero
// branch (the compiler then emits the call as a separate branch with the store dup'd); a free by
// its name. none gives the game's register use (the slot pointer in r4 before the test).
void sub_002B8E24(u32 a, u32 b);

//! 0x00365FBC sub_00365FBC
int sub_00365FBC(u8 *a1, u32 a2, u32 a3) {
    sub_002B8E24(a2, a3);
    u8 *part = a1 + 0x800;
    void **slot = (void **)(part + 0x38);
    if (*slot != 0) {
        gfl2::heap::GflHeapFreeMemoryBlock(*slot);
    }
    *slot = 0;
    return 0;
}
