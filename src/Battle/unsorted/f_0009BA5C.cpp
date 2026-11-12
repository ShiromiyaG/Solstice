#include "types.h"
#include "App/ui/UIView.h"
#include "App/util/G2DUtil.h"
#include "btl/app/BtlvUiMsgWin.h"

// the display number is typed as the enum (no byte mask on the argument).
//! Battle:0x0009BA5C f_Battle_0009BA5C
extern "C" void f_Battle_0009BA5C(btl::app::BtlvUiMsgWin *a1, gfl2::gfx::CtrDisplayNo a2) {
    app::util::G2DUtil *g2d = a1->GetG2DUtil();
    if (g2d)
        g2d->AddDrawableLytWkForOneFrame(*(app::util::AppRenderingManager **)((u8 *)a1 + 0x98), a2, 0, 128, 0);
}
