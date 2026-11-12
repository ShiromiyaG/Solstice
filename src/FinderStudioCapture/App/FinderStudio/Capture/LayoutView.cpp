#include "App/FinderStudio/Capture/LayoutView.h"

namespace App {
namespace FinderStudio {
namespace Capture {

//! FinderStudioCapture:0x00003658 _ZN3App12FinderStudio7Capture10LayoutView4Show
void LayoutView::Show() {
    SetModal(true);
    _Show();
}

}  // namespace Capture
}  // namespace FinderStudio
}  // namespace App
