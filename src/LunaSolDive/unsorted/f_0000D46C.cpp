#include "types.h"
#include "gfl2/Effect/Handle.h"

//! LunaSolDive:0x0000D46C f_LunaSolDive_0000D46C
void *f_LunaSolDive_0000D46C(u8 *a0)
{
    u8 *result = (u8 *)((::gfl2::Effect::Handle *)*(u32 *)(a0 + 4))->GetEmitterSet();
    if (result != 0 && *(s32 *)(result + 4) > 0) {
        if (result[0x284] == 0) {
            result[0x284] = 1;
        }
    }
    return result;
}
