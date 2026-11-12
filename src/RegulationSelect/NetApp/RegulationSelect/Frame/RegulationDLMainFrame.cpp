#include "types.h"
#include "NetApp/RegulationSelect/Frame/RegulationDLMainFrame.h"
#include "App/ui/UIResponder.h"

// the field at +0x3c is a guess (a pointer); the object it points to holds the responder at +0x10
//! RegulationSelect:0x0000358C vf12
void NetApp::RegulationSelect::Frame::RegulationDLMainFrame::vf12() {
    u8 *responder = *(u8 **)((u8 *)field_3C + 0x10);
    *(void **)(responder + 0xB0) = (u8 *)this + 0x40;
    ((app::ui::UIResponder *)(*(u8 **)((u8 *)field_3C + 0x10)))->SetInputEnabled(true);
}
