#include "NetApp/P2PTrade/View/P2PTradeMessageLowerView.h"
#include "app/ui/UIView.h"

namespace NetApp {
namespace P2PTrade {
namespace View {

//! P2PTrade:0x000020BC _ZThn160_N6NetApp8P2PTrade4View24P2PTradeMessageLowerViewD1Ev
P2PTradeMessageLowerView::~P2PTradeMessageLowerView() {
    field_B0->RemoveFromSuperView();
    // the cast stands for the UIView's member at +0x90 (not in the header)
    *(void **)((u8 *)field_B0 + 0x90) = 0;
}

}  // namespace View
}  // namespace P2PTrade
}  // namespace NetApp
