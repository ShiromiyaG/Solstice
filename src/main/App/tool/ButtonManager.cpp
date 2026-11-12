#include "App/Tool/ButtonManager.h"

// the slot returns the signed byte of the button at index field_10 (a guess: the index is read
// first, then the count through field_8, which the header types as a pointer: cast to u32 *, a guess).
//! 0x004AB43C vf9
s8 app::tool::ButtonManager::SingleProcessManager::vf9()
{
    u32 *count = (u32 *)field_8;
    if (field_10 < *count) {
        return *(s8 *)(((u32 *)field_4)[field_10] + 77);
    }
    return 0;
}
