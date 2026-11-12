#include "btl/app/BattleUIPokeListLowerButtonCtrl.h"

namespace gfl2 { namespace debug { void GFLassert(const char *, unsigned int, int, const char *); } }

namespace btl {
namespace app {

//! Battle:0x000A76EC _ZN3btl3app31BattleUIPokeListLowerButtonCtrl4vf12
void BattleUIPokeListLowerButtonCtrl::vf12(u32 a1) {
    // a guess: field_4 is an object of a class not in the headers yet;
    // slot 12 of its vtable (offset 0x30) is called with a1, as a tail call
    void *obj = field_4;
    if (obj) {
        typedef void (*Slot)(void *, u32);
        Slot f = (Slot)(*(u32 **)obj)[12];
        f(obj, a1);
    }
}

//! Battle:0x000A7724 vf13
void BattleUIPokeListLowerButtonCtrl::vf13(u32 a1) {
    // a guess: field_4 is an object of a class not in the headers yet;
    // slot 13 of its vtable (offset 0x34) is called with a1, as a tail call
    void *obj = field_4;
    if (obj) {
        typedef void (*Slot)(void *, u32);
        Slot f = (Slot)(*(u32 **)obj)[13];
        f(obj, a1);
    }
}

//! Battle:0x000A78B0 _ZN3btl3app31BattleUIPokeListLowerButtonCtrl4vf22
void BattleUIPokeListLowerButtonCtrl::vf22(u32 a1, u32 a2) {
    if (!a1) {
        gfl2::debug::GFLassert(0, 0, 0, 0);
    }
    // a guess: a1 is a record of 16 bytes with no known type yet
    *(u32 *)(a1 + 4) = 0;
    *(u32 *)(a1 + 8) = 0;
    *(u16 *)(a1 + 12) = 0;
    *(u32 *)a1 = a2;
}

}  // namespace app
}  // namespace btl
