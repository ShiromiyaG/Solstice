#include "types.h"

namespace gfl2 { namespace heap { void *GflHeapAllocMemoryBlock(u32 heap); } }

// the class is not known (its name lies between gfl2::util::UtilTextRenderPath and
// gfl2::debug::LogWindow). open: the stores and the call match, but the game copies the heap
// argument (r2) to r0 before computing the flag, so the flag lives in r2; ours computes the flag
// in r0 and copies late. tried: the flag first (6 of 14 words differ), the store of a1[0] first,
// and the flag as it is (6 of 14). now the flag inline in the second store, in the game's order
// (5 of 14): the heap argument is still copied late (the game copies it to r0 at the start).
//! 0x003654BC sub_003654BC
u32 *sub_003654BC(u32 *a1, u32 a2, int a3) {
    a1[0] = a2;
    a1[1] = (a2 >> 3) + ((a2 & 7) != 0);
    a1[3] = (u32)gfl2::heap::GflHeapAllocMemoryBlock(a3);
    a1[2] = 1;
    return a1;
}
