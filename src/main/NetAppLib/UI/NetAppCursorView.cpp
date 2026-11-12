#include "NetAppLib/UI/NetAppCursorView.h"

// the header declares IsDrawing as bool (a guess from its code; the game returns bool here).
// the object at +0x10c is not identified: its class is unknown (a guess), so its slot 3 (+0xc)
// is called by hand through its vtable, as the game does (ldr, ldr, blx).
//! 0x004C90F4 IsDrawing
bool NetAppLib::UI::NetAppCursorView::IsDrawing() const {
    typedef bool (*SlotFn)(void *);
    void *obj = field_10C;
    SlotFn slot3 = *(SlotFn *)(*(u32 *)obj + 0xc);
    return slot3(obj) && app::ui::UIView::IsDrawing();
}

//! 0x00475C80 _ZN9NetAppLib2UI16NetAppCursorViewD1Ev
//! 0x00475C40 _ZN9NetAppLib2UI16NetAppCursorViewD0Ev
NetAppLib::UI::NetAppCursorView::~NetAppCursorView() {}

//! 0x00475B4C Update
void NetAppLib::UI::NetAppCursorView::Update() {
    app::ui::UIView::Update();
    if (field_120) {
        field_10C->OnUpdate();
    }
}

//! 0x00475B2C Draw
void NetAppLib::UI::NetAppCursorView::Draw(::gfl2::gfx::CtrDisplayNo displayNo) {
    if (field_120) {
        field_10C->OnDraw(displayNo);
    }
}

//! 0x00475A88 SetCursorController
void NetAppLib::UI::NetAppCursorView::SetCursorController(::app::tool::CursorController* pController) {
    if (pController == 0) {
        pController = &field_AC;
    }
    field_10C = pController;
}
