#include "btl/BattleViewSystem.h"

u32 f_Battle_0005EC3C(void *);
u32 f_Battle_0008F534(void *, u32);

namespace btl {

//! Battle:0x000E3B28 vf51
u32 BattleViewSystem::vf51(u32 a1, u8 a2)
{
    if (field_4 == 0) {
        return a2 & 1;
    }
    u32 v = f_Battle_0005EC3C(field_4);
    return f_Battle_0008F534(field_4, v);
}

}  // namespace btl
