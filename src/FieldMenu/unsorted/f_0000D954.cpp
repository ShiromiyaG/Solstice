#include "types.h"

namespace gfl2 {
namespace heap {
void GflHeapFreeMemoryBlock(void *);
}
}

// frees the block at +0xfc, then the one at +0xec (the second call is a tail call)
//! FieldMenu:0x0000D954 f_FieldMenu_0000D954
void f_FieldMenu_0000D954(u8 *a1) {
    gfl2::heap::GflHeapFreeMemoryBlock(*(void **)(a1 + 0xfc));
    gfl2::heap::GflHeapFreeMemoryBlock(*(void **)(a1 + 0xec));
}
