#include "NetApp/JoinFestaAttractionListSelect/Frame/JoinFestaAttractionListSelectEntryFrame.h"

int f_JoinFestaAttractionListSelect_00000218();
void f_JoinFestaAttractionListSelect_00000258(void *a1, int a2);

namespace NetApp {
namespace JoinFestaAttractionListSelect {
namespace Frame {

//! JoinFestaAttractionListSelect:0x00001600 vf17
void JoinFestaAttractionListSelectEntryFrame::vf17() {
    int wlan = f_JoinFestaAttractionListSelect_00000218();
    return f_JoinFestaAttractionListSelect_00000258(*(void **)(*(u8 **)((u8 *)this + 0x2c) + 0x14), wlan);
}

}  // namespace Frame
}  // namespace JoinFestaAttractionListSelect
}  // namespace NetApp
