#include "app/title/TitleUpperUIDraw.h"
#include "app/util/G2DUtil.h"
#include "app/ui/UIView.h"

// the header types field_84 as u32 (a guess of tools/fields.py); the game passes it as the
// AppRenderingManager pointer, so the cast stands for that member's real type until the
// header has it.

//! Title:0x00001A18 Draw
void app::title::TitleUpperUIDraw::Draw(::gfl2::gfx::CtrDisplayNo disp) {
    ::app::util::G2DUtil *g2d = GetG2DUtil();
    g2d->AddDrawableLytWkForOneFrame((::app::util::AppRenderingManager *)field_84, disp, 0, 0x80, 0);
}
