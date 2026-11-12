#include "app/bag/BagDraw.h"
#include "app/tool/MenuCursor.h"
#include "App/Tool/ItemEffect.h"

namespace app {
namespace bag {

// the override of UIView's slot 13 (Update), reached through the UIView subobject at +4: the
// compiler makes the thunk at -4 from it. field_C8 and field_104 are pointers the code calls
// Update on (the header has them as u32).
//! Bag:0x000151F0 f_Bag_000151F0
void BagDraw::Update() {
    ::app::ui::UIView::Update();
    if (field_C8) {
        ((::app::tool::MenuCursor *)field_C8)->Update();
    }
    if (field_104) {
        ((::App::Tool::ItemEffect *)field_104)->Update();
    }
}

// Bag:0x00015220 (f_Bag_00015220) is the deleting destructor of the UIView subobject (UIView's
// slot 6, at -4): it is UIView's destructor, then the delete of the object. It is written as
// BagDraw's virtual destructor, which the header does not declare (~BagDraw is missing), so it is
// not written here yet.

}  // namespace bag
}  // namespace app
