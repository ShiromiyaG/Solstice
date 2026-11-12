#include "types.h"

extern "C" u8 data_BattleVideoRecording_00004410[];

// guess: the class is not in include/ yet; the word at +0 is a vtable address (off_4410 in the game)
//! BattleVideoRecording:0x000012C8 f_BattleVideoRecording_000012C8
u8 *f_BattleVideoRecording_000012C8(u8 *a0)
{
    *(u32 *)a0 = (u32)data_BattleVideoRecording_00004410;
    *(u32 *)(a0 + 4) = 0;
    *(u8 *)(a0 + 8) = 0;
    *(u32 *)(a0 + 24) = 0;
    return a0;
}
