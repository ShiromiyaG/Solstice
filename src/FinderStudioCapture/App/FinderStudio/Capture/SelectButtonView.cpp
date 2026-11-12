#include "App/FinderStudio/Capture/SelectButtonView.h"
#include "App/FinderStudio/Static/ViewBase.h"

//! FinderStudioCapture:0x0000B0B8 Hide
void App::FinderStudio::Capture::SelectButtonView::Hide() {
    App::FinderStudio::Static::ViewBase::_Hide();
    App::FinderStudio::Static::ViewBase::DeleteKeyRepeatController();
}
