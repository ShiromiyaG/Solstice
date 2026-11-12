#include "types.h"

// no class header yet: the words and the byte are written at their offsets (guesses).
//! BattleVideoPlayer:0x0000091C f_BattleVideoPlayer_0000091C
void f_BattleVideoPlayer_0000091C(u8 *result) {
    result[0] = 0;
    int *w = (int *)result;
    w[2] = 4;
    w[1] = 0x20;
    w[3] = 0x10;
    w[4] = 4;
    w[5] = 4;
    result[24] = 0;
}
