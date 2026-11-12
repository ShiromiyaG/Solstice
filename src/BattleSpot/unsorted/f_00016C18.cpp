#include "types.h"

extern "C" u8 *f_BattleSpot_0000B7D4(u8 *);
void operator delete(void *);

//! BattleSpot:0x00016C18 f_BattleSpot_00016C18
extern "C" void f_BattleSpot_00016C18(u8 *self)
{
    u8 *obj = f_BattleSpot_0000B7D4(self - 0x34);
    operator delete(obj);
}
