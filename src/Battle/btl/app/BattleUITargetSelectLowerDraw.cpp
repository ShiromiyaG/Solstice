#include "btl/app/BattleUITargetSelectLowerDraw.h"

namespace btl {
namespace app {

// the override of UIInputListener's slot 2 (at +0x80): the header does not declare it yet.
// field_8C is an object whose vtable slot 2 (offset 8) is called with (object, this, a1);
// its class has no header, so the call goes through a function pointer as the other sources do.
//! Battle:0x000E6064 f_Battle_000E6064
bool BattleUITargetSelectLowerDraw::UIInputListener_vf2(u32 a1) {
    void *obj = field_8C;
    if (obj) {
        typedef bool (*Slot)(void *, void *, u32);
        Slot f = (Slot)(*(u32 **)obj)[2];
        if (f(obj, this, a1)) {
            return false;
        }
    }
    return true;
}

}  // namespace app
}  // namespace btl
