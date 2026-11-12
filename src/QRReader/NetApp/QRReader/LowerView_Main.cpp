#include "NetApp/QRReader/LowerView_Main.h"

namespace NetApp {
namespace QRReader {

// the override of app::ui::UIInputListener's slot 3 (at +0xa0 in LowerView_Main): the header
// does not declare it yet, so this is the honest source with the declaration missing.
//! QRReader:0x00009340 f_QRReader_00009340
bool LowerView_Main::UIInputListener_vf3() {
    bool result = field_CD == 0;
    field_CE = 1;
    return result;
}

}  // namespace QRReader
}  // namespace NetApp
