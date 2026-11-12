#include "types.h"
#include "Savedata/JoinFestaDataSave.h"

namespace gfl2 {
namespace debug {
void GFLassert(const char *, u32, s32, const char *);
}
}

// the index is below 11 (0xb) or the assert runs (its call is a mov r0, r0 in the game's code:
// four zero arguments). the value is a byte loaded from +0x544 + index, returned without a compare.
//! 0x004C5E40 GetRewardState
u8 Savedata::JoinFestaDataSave::GetRewardState(::JoinFestaScript::RewardType a2) const
{
    if (a2 < 0xb)
    {
        return ((const u8 *)this)[0x544 + a2];
    }
    gfl2::debug::GFLassert(0, 0, 0, 0);
    return 0;
}
