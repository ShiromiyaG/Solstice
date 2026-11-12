#include "App/FinderStudio/Capture/ShootView.h"

// guesses: the class of the static InformationWindow::Hide, and a free function of
// FinderStudioCapture that takes this (their names and types are not known)
namespace App { namespace FinderStudio { namespace Static { class InformationWindow { public: static void Hide(); }; } } }
void f_FinderStudioCapture_0000DEBC(::App::FinderStudio::Capture::ShootView *self);

namespace App {
namespace FinderStudio {
namespace Capture {

//! FinderStudioCapture:0x00015690 _ZThn200_N3App12FinderStudio7Capture9ShootView30InfoWindowBookTypeListener_vf2
void ShootView::InfoWindowBookTypeListener_vf2() {
    Static::InformationWindow::Hide();
    f_FinderStudioCapture_0000DEBC(this);
    ::app::ui::UIResponder::SetInputEnabled(true);
}

}  // namespace Capture
}  // namespace FinderStudio
}  // namespace App
