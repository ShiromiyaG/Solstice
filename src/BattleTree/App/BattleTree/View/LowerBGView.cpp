#include "App/BattleTree/View/LowerBGView.h"

namespace App {
namespace BattleTree {
namespace View {

//! BattleTree:0x000006F0 _ZN3App10BattleTree4View11LowerBGView4Draw
void LowerBGView::Draw(::gfl2::gfx::CtrDisplayNo displayNo) {
    // the cast stands for the member's real type (field_A0 is void * in the header)
    GetG2DUtil()->AddDrawableLytWkForOneFrame(*(::app::util::AppRenderingManager **)((u8 *)field_A0 + 0x2c), displayNo, 0, 0x80, 0);
}

}  // namespace View
}  // namespace BattleTree
}  // namespace App
