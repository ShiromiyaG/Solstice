#include "NetApp/QuickMatch/View/QuickMatchLowerView.h"
#include "App/Tool/MenuCursor.h"

//! QuickMatch:0x00000E50 Update
void NetApp::QuickMatch::View::QuickMatchLowerView::Update() {
    app::ui::UIView::Update();
    field_AC->Update();
}
