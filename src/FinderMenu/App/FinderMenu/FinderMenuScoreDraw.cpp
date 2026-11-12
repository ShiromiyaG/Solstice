#include "types.h"
#include "App/FinderMenu/FinderMenuScoreDraw.h"
#include "App/util/G2DUtil.h"

//! FinderMenu:0x00002064 _ZN3App10FinderMenu19FinderMenuScoreDraw4Draw
void App::FinderMenu::FinderMenuScoreDraw::Draw(::gfl2::gfx::CtrDisplayNo display) {
    // a guess: field_90 is the rendering manager the layout work is added to (its header type is u32)
    ::app::util::G2DUtil *util = GetG2DUtil();
    util->AddDrawableLytWkForOneFrame((::app::util::AppRenderingManager *)field_90, display, 0, 0x80, 0);
}
