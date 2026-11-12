#include "App/Kisekae/View/LowerInfoView.h"
#include "app/ui/UIView.h"

namespace App {
namespace Kisekae {
namespace View {

//! Kisekae:0x00009DD0 IsDrawing
bool LowerInfoView::IsDrawing() const {
    bool result = false;
    if (::app::ui::UIView::IsDrawing()) {
        result = true;
    }
    return result;
}

}  // namespace View
}  // namespace Kisekae
}  // namespace App
