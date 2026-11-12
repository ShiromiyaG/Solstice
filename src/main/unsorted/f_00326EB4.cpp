#include "types.h"

namespace pml { namespace wazadata {
unsigned int GetParam(int a1, int id);
u8 GetMaxPP(int a1, unsigned int a2);
} }

// the largest PP: the base PP (param 5) plus a fifth per 20 percent of the count, capped at 3 PP ups.
// open: 1 word differs. the game multiplies with a signed 16 x 16 (smulbb r2, r0, r4), ours with
// a plain mul; the count is copied as a whole word (mov r4, r1), not sign extended. tried: the
// count as a 16-bit signed value (sxth at the start, 2 words differ), and the cast of the count
// to s16 at the multiply (3 words differ, the magic load moves).
//! 0x00326EB4 GetMaxPP
u8 pml::wazadata::GetMaxPP(int a1, unsigned int a2) {
    unsigned int v2 = a2;
    if (a2 > 3)
        v2 = 3;
    s16 param = (u8)pml::wazadata::GetParam(a1, 5);
    return (u8)(param + 20 * param * v2 / 100u);
}
