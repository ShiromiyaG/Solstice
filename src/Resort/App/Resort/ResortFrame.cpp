#include "App/Resort/ResortFrame.h"

namespace App {
namespace Resort {

//! Resort:0x00007BB4 _ZN3App6Resort11ResortFrame4vf18
void ResortFrame::vf18(u32 a1) {
    ResortFlowListener_vf6();
    // the casts stand for the members' real types (field_40, field_A0 are void * in the header)
    *(u32 *)((u8 *)field_40 + 0x60) = *(u8 *)((u8 *)field_A0 + 0x6e);
    *(u32 *)((u8 *)field_40 + 0x58) = a1;
}

//! Resort:0x000229C4 _ZThn24_N3App6Resort11ResortFrame22ResortDrawListener_vf0
void ResortFrame::ResortDrawListener_vf0(u32 a1) {
    if (a1 == 1) {
        *(u32 *)((u8 *)field_40 + 0x34) = 0;
        field_4 = 2;
        return;
    }
    field_48 = 1;
}

//! Resort:0x00022BB4 _ZThn32_N3App6Resort11ResortFrame22ResortFlowListener_vf2
void ResortFrame::ResortFlowListener_vf2() {
    ResortFlowListener_vf6();
    *(u32 *)((u8 *)field_40 + 0x58) = 6;
}

}  // namespace Resort
}  // namespace App
