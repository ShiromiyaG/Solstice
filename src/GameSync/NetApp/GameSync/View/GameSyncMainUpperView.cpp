#include "NetApp/GameSync/View/GameSyncMainUpperView.h"
#include "App/util/G2DUtil.h"

namespace NetApp {
namespace GameSync {
namespace View {

// field_A0 is an object whose +0x2c is the app::util::AppRenderingManager the view draws with
// (its class has no header yet): read by offset.
//! GameSync:0x00000938 _ZN6NetApp8GameSync4View21GameSyncMainUpperView4Draw
void GameSyncMainUpperView::Draw(::gfl2::gfx::CtrDisplayNo display) {
    ::app::util::G2DUtil *g2d = GetG2DUtil();
    g2d->AddDrawableLytWkForOneFrame((::app::util::AppRenderingManager *)*(void **)((u8 *)field_A0 + 0x2c), display, 0, 0x80, 0);
}

}  // namespace View
}  // namespace GameSync
}  // namespace NetApp
