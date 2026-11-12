#include "pml/pokepara/CoreParam.h"

u32 sub_004AFC34(void *, u32);

namespace pml {
namespace pokepara {

// the game loops four times over the index (a byte, Hex-Rays' reading: a guess) and counts
// the calls that return nonzero; the count is a byte too (a guess from the same reading).
// the function is longer than the 36 bytes the table gives: the loop's end is past them.
//! 0x004B0048 GetWazaCount
u32 CoreParam::GetWazaCount() const
{
    u8 count = 0;
    for (u8 i = 0; i < 4; i++) {
        if (sub_004AFC34(field_C, i)) {
            count = count + 1;
        }
    }
    return count;
}

}  // namespace pokepara
}  // namespace pml
