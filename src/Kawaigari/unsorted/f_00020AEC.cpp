#include "types.h"

namespace gfl2 {
namespace heap {
void GflHeapFreeMemoryBlock(void *p);
}
}

//! Kawaigari:0x00020AEC f_Kawaigari_00020AEC
extern "C" u8 *f_Kawaigari_00020AEC(u8 *a1) {
    if (a1[0xc])
        gfl2::heap::GflHeapFreeMemoryBlock(*(void **)(a1 + 4));
    return a1;
}
