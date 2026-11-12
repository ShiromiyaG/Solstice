#include "btl/BattleViewSystem.h"

void f_Battle_00081D1C();

namespace btl {

//! Battle:0x000E3834 vf71
void BattleViewSystem::vf71()
{
    if (field_4 != 0) {
        f_Battle_00081D1C();
    }
}

}  // namespace btl
