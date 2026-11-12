#include "Savedata/ResortSave.h"

//! 0x0044EB3C SetHotSpaPokemonTime
void Savedata::ResortSave::SetHotSpaPokemonTime(int a0, unsigned char a1, unsigned char a2, unsigned char a3)
{
    u8 *base = (u8 *)this + a0 * 3;
    base[22278] = a1;
    base[22277] = a2;
    base[22276] = 0;
}
