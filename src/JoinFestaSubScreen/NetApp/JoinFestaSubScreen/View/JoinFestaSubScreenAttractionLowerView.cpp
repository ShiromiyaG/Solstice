#include "NetApp/JoinFestaSubScreen/View/JoinFestaSubScreenAttractionLowerView.h"

namespace NetApp {
namespace JoinFestaSubScreen {
namespace View {

//! JoinFestaSubScreen:0x000032C4 UIInputListener_vf2
bool JoinFestaSubScreenAttractionLowerView::UIInputListener_vf2(u32 a1)
{
    u32 *v = (u32 *)field_A8;
    if (!v)
        return true;
    if (!a1) {
        u32 *vt = (u32 *)*v;
        ((void (*)(u32 *))vt[0])(v);
    }
    return false;
}

}  // namespace View
}  // namespace JoinFestaSubScreen
}  // namespace NetApp
