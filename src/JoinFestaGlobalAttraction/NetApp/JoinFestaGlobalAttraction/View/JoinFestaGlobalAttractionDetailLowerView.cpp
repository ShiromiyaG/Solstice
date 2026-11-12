#include "NetApp/JoinFestaGlobalAttraction/View/JoinFestaGlobalAttractionDetailLowerView.h"
#include "app/util/G2DUtil.h"
#include "app/util/AppRenderingManager.h"

namespace NetApp {
namespace JoinFestaGlobalAttraction {
namespace View {

// open: the body is right, the register order of the arguments differs (the game loads
// 0x80 into r2 before the field at +0xa4; ours loads it into r1). Tried: a local for the
// rendering manager (one register too many), the expression inline (this).
//! JoinFestaGlobalAttraction:0x00001460 JoinFestaGlobalAttractionDetailLowerView
void JoinFestaGlobalAttractionDetailLowerView::Draw(::gfl2::gfx::CtrDisplayNo a1) {
    GetG2DUtil()->AddDrawableLytWkForOneFrame(*(::app::util::AppRenderingManager **)((u8 *)field_A4 + 0x2c), a1, 0, 0x80, 0);
}

}  // namespace View
}  // namespace JoinFestaGlobalAttraction
}  // namespace NetApp
