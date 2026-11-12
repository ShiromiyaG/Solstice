#include "types.h"
#include "App/Status/StatusFrame.h"

// the callees of the frame, not named yet (a guess at their parameters)
extern "C" void f_Status_000073EC(void *);
extern "C" void f_Status_00007400(void *, u32);
extern "C" void f_Status_00008058(void *, u32);
extern "C" u32 f_Status_00007D10(void *, u32);
extern "C" void f_Status_00007D74(void *, u32);

//! Status:0x00002598 _ZN3App6Status11StatusFrame23StatusDrawListener_vf22
void App::Status::StatusFrame::StatusDrawListener_vf22() {
    if (field_80) {
        f_Status_000073EC(field_80);
    }
    if (field_84) {
        f_Status_00007400(field_84, 0);
    }
    if (field_AC) {
        // a guess: field_AC is an object pointer (its header type is u32)
        f_Status_00008058((void *)field_AC, 0);
    }
}

// overrides StatusDrawListener's slot 11, through the base at +0x18 (its thunk Status:0000B4FC)
//! Status:0x0000B4FC _ZThn24_N3App6Status11StatusFrame23StatusDrawListener_vf11
void App::Status::StatusFrame::StatusDrawListener_vf11() {
    if (field_70) {
        // a guess: the member at +0xbc is not in the header yet, read as a u32
        u32 v = f_Status_00007D10((::App::Status::StatusDrawListener *)this, *(u32 *)((u8 *)this + 0xbc));
        f_Status_00007D74(this, v);
    }
}
