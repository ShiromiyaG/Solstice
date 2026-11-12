#include "app/tool/TwoButtonsView.h"
#include "App/Tool/ButtonManager.h"

namespace gfl2 { namespace heap { void GflHeapFreeMemoryBlock(void *p); } }

namespace app {
namespace tool {

// the complete (D1) and base (D2) destructors of the base class: one definition, two copies in
// the game (0x002F7D44 stores the base's vtable, 0x648AB4). the packet's DefaultResourceLoader
// label for 0x002F7D44 is wrong: it is this class's own destructor, not the derived one.
//! 0x002F7D44 ResourceLoaderBaseD1Ev
//! 0x002F7AD4 ResourceLoaderBaseD2Ev
TwoButtonsView::ResourceLoaderBase::~ResourceLoaderBase() {
    gfl2::heap::GflHeapFreeMemoryBlock((void *)field_8);
}


// the button manager is at +0x10 of this view and the event's object at +0x10 too; neither
// offset has a member in the headers yet (inherited from app::ui::UIView, untyped here)
// open: DIFFER (28 bytes, the game's 40). the game keeps a1 in r4 (push {r4, lr}, mov r4, r1
// before the compare) and reads it after the sub of the thunk; ours reads it from r1 and is a
// leaf. Tried: a local pointer for a1 before the if (same bytes), the test inverted with an
// early return (same bytes). The reason for the saved r4 is not known yet.
//! 0x004CBF48 _ZThn132_N3app4tool14TwoButtonsView17IEventHandler_vf2
void TwoButtonsView::IEventHandler_vf2(u32 a1, u32 a2) {
    if (a2 != 1) {
        return;
    }
    ButtonManager *manager = *(ButtonManager **)((u8 *)this + 0x10);
    manager->StartSelectedAct(*(u32 *)((u8 *)a1 + 0x10));
}

}  // namespace tool
}  // namespace app
