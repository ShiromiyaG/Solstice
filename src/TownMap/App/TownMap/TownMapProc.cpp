#include "App/TownMap/TownMapProc.h"
#include "AppLib/frame/Manager.h"
#include "App/util/AppRenderingManager.h"

namespace App {
namespace TownMap {

//! TownMap:0x000012C8 _ZN3App7TownMap11TownMapProc8DrawFunc
void TownMapProc::DrawFunc(::gfl2::proc::Manager *pManager, ::gfl2::gfx::CtrDisplayNo displayNo) {
    field_50->Draw(displayNo);
    field_4C->Draw(displayNo);
}

}  // namespace TownMap
}  // namespace App
