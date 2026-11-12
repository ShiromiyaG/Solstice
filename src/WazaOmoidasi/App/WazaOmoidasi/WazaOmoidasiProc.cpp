#include "App/WazaOmoidasi/WazaOmoidasiProc.h"
#include "AppLib/frame/Manager.h"
#include "App/util/AppRenderingManager.h"
#include "types.h"

namespace App {
namespace WazaOmoidasi {

// the two members are void * in the header (a guess): the code uses them as these pointers.
// the second parameter is the display (r2 in the game, u32 in the header: a guess), passed on
// as it is to both draws; the last call is a tail call.
//! WazaOmoidasi:0x00002AF0 vf5
void WazaOmoidasiProc::vf5(u32 a1, u32 a2) {
    ((::applib::frame::Manager *)field_50)->Draw((::gfl2::gfx::CtrDisplayNo)a2);
    ((::app::util::AppRenderingManager *)field_4C)->Draw((::gfl2::gfx::CtrDisplayNo)a2);
}

}  // namespace WazaOmoidasi
}  // namespace App
