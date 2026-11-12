#include "NetAppLib/JoinFestaUI/JoinFestaPlayerListBGUpperView.h"

namespace NetAppLib {
namespace JoinFestaUI {

//! 0x0046B674 _ZN9NetAppLib11JoinFestaUI30JoinFestaPlayerListBGUpperView4Draw
void JoinFestaPlayerListBGUpperView::Draw(::gfl2::gfx::CtrDisplayNo displayNo) {
    // the cast stands for the member's real type (field_A0 is void * in the header)
    field_60->AddDrawableLytWkForOneFrame(*(::app::util::AppRenderingManager **)((u8 *)field_A0 + 0x2c), displayNo, 0, 0x80, 0);
}

}  // namespace JoinFestaUI
}  // namespace NetAppLib
