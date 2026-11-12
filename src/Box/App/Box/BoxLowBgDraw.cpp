#include "App/Box/BoxLowBgDraw.h"
#include "App/Box/BoxDrawPartsListener.h"
#include "gfl2/lyt/LytWk.h"

// the override of BoxDrawPartsListener's slot 0 (a new slot of this class's own vtable, 24); the
// compiler also emits the thunk the listener's vtable holds, which adjusts this by 0x84
//! Box:0x00002FDC BoxLowBgDraw24BoxDrawPartsListener_vf0
//! Box:0x000277A4 Thn132_N3App3Box12BoxLowBgDraw24BoxDrawPartsListener_vf0
void App::Box::BoxLowBgDraw::BoxDrawPartsListener_vf0(u32 a1) {
    ::gfl2::lyt::LytWk *layout_work = GetLayoutWork(0);
    if (a1 < 0x1e) {
        layout_work->GetPartsPane(a1 + 0xe2);
    } else {
        layout_work->GetPartsPane(a1 + 0x11e);
    }
}

// overrides App::Box::BoxDrawPartsListener's slot 1, through the base at +0x84 (its thunk Box:000277DC)
//! Box:0x000277DC _ZThn132_N3App3Box12BoxLowBgDraw24BoxDrawPartsListener_vf1
void App::Box::BoxLowBgDraw::BoxDrawPartsListener_vf1(u32 a1) {
    ::gfl2::lyt::LytWk *layout_work = GetLayoutWork(0);
    layout_work->GetPartsPane(a1 + 0x100);
}

