#include "App/ui/UIView.h"
#include "App/util/G2DUtil.h"

namespace app {
namespace ui {

//! 0x004AADF4 IsDrawing
bool UIView::IsDrawing() const
{
    bool isDrawing = false;
    if (field_60 != 0) {
        isDrawing = field_60->IsDrawing();
    }
    return isDrawing;
}

//! 0x004AAD34 GetLayoutWork
::gfl2::lyt::LytWk *UIView::GetLayoutWork(unsigned int lytId) const
{
    if (field_60 != 0) {
        return field_60->GetLayoutWork(lytId);
    }
    return 0;
}

}  // namespace ui
}  // namespace app
