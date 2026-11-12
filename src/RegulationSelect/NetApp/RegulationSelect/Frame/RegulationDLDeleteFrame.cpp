#include "types.h"
#include "NetApp/RegulationSelect/Frame/RegulationDLDeleteFrame.h"

// the function after this one, reached by a tail call (not named yet; a guess at its parameters)
extern "C" void sub_00005918(u32, u32, u32, u32);

//! RegulationSelect:0x00005904 _ZN6NetApp16RegulationSelect5Frame23RegulationDLDeleteFrame4vf17
void NetApp::RegulationSelect::Frame::RegulationDLDeleteFrame::vf17() {
    // a guess: field_98 is an object whose word at +0x10 is passed on
    sub_00005918(*(u32 *)((u8 *)field_98 + 0x10), field_A8, 0xf, 0);
}
