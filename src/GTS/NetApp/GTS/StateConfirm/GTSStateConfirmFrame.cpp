#include "NetApp/GTS/StateConfirm/GTSStateConfirmFrame.h"
#include "NetApp/GTS/ApplicationSystem/GTSWork.h"
#include "NetApp/GTS/ApplicationSystem/GTSViewObjects.h"
#include "NetApp/GTS/Window/GTSMessageWindowLowerView.h"
#include "app/ui/UIResponder.h"
#include "app/ui/UIView.h"

// callees without a name; the parameter types are guesses from what is passed
// (each is probably a member function of the class of its first argument)
void f_GTS_000128C8(::NetApp::GTS::Window::GTSMessageWindowLowerView *view, u32 a1, u32 a2);
void f_GTS_00012AB4(::NetApp::GTS::GTSFrameBase *frame);
void f_GTS_00012A88(::NetApp::GTS::GTSFrameBase *frame, void *view);
void f_GTS_000129FC(void *view, u32 a1, u32 a2);
// request sequences added to the ServerClientRequestManager (templates, by their listener)
void f_GTS_00012914(::NetApp::GTS::RequestSequence::GTSDownloadTradePokemonResponseListener *listener, ::NetApp::GTS::ApplicationSystem::GTSWork *work);
void f_GTS_00012988(::NetApp::GTS::RequestSequence::GTSRestorePokemonResponseListener *listener, ::NetApp::GTS::ApplicationSystem::GTSWork *work);
void f_GTS_00012B58(::NetApp::GTS::ApplicationSystem::GTSViewObjects *views);

namespace NetApp {
namespace GTS {
namespace StateConfirm {

// The virtual calls below (exitFrame, slot 9; vf17, slot 17) come out one slot too far
// (+0x28 for +0x24): CellSuper, NetAppFrameBase and GTSFrameBase declare a `vf1` after their
// destructor, but slot 1 is the deleting destructor, so every later slot moves by one.

//! GTS:0x00003BB8 vf18
void GTSStateConfirmFrame::vf18() {
    exitFrame(0);
}

//! GTS:0x00003BA8 vf19
void GTSStateConfirmFrame::vf19() {
    exitFrame(1);
}

//! GTS:0x00003B20 vf22
void GTSStateConfirmFrame::vf22() {
    exitFrame(4);
}

// GTSViewObjects::field_34 stands for a pointer to the message window (GTSMessageWindowLowerView)

//! GTS:0x0000393C vf12
void GTSStateConfirmFrame::vf12() {
    ((Window::GTSMessageWindowLowerView *)field_44->field_34)->field_148 = unk_48;
}
// vf12 and vf13 differ in register choice only: the game computes the value first (r1) and the
// view in r0, as an inlined setter of GTSMessageWindowLowerView (this = view, r1 = listener)
// would; that header has no such setter (field_148 written directly). Tried: a local for the
// value (closer, registers still swapped; not kept, a temporary for the compiler).

//! GTS:0x00012B40 vf13
void GTSStateConfirmFrame::vf13() {
    ((Window::GTSMessageWindowLowerView *)field_44->field_34)->field_148 = 0;
    f_GTS_00012B58(field_44);
}

//! GTS:0x00003B48 vf20
void GTSStateConfirmFrame::vf20() {
    f_GTS_000128C8((Window::GTSMessageWindowLowerView *)field_44->field_34, 2, 0);
    ((Window::GTSMessageWindowLowerView *)field_44->field_34)->SetInputEnabled(true);
}

//! GTS:0x00003B78 vf21
void GTSStateConfirmFrame::vf21() {
    f_GTS_000128C8((Window::GTSMessageWindowLowerView *)field_44->field_34, 4, 0);
    ((Window::GTSMessageWindowLowerView *)field_44->field_34)->SetInputEnabled(true);
}

//! GTS:0x00003A44 vf17
void GTSStateConfirmFrame::vf17() {
    if (field_4C == 0) {
        switch (field_50) {
        case 2:
            f_GTS_00012AB4(this);
            f_GTS_00012A88(this, field_44->field_44);
            f_GTS_000129FC(field_44->field_44, 5, 1);
            f_GTS_00012914(this, field_40);
            field_88 = 1;
            field_58.TimeOutStart(3000);
            break;
        case 4:
            f_GTS_00012AB4(this);
            f_GTS_00012A88(this, field_44->field_44);
            f_GTS_000129FC(field_44->field_44, 35, 1);
            f_GTS_00012988(this, field_40);
            field_88 = 1;
            field_58.TimeOutStart(3000);
            break;
        }
    }
}

// The deleting destructor differs only in the vtable addresses it stores (+0x74/+0x90 for the
// game's +0x70/+0x8c): our primary vtable is one slot too long, the bases' `vf1` again.
//! GTS:0x00003CB0 GTSStateConfirmFrameD0Ev
GTSStateConfirmFrame::~GTSStateConfirmFrame() {
}

// Open, not written (they need other headers):
// - GTS:0x00003950 vf14: switch on field_88 (0: this->vf17(); 2, 3, 4: when
//   field_58.IsTimeOut(NULL), field_40's byte at +0xf0 = 4 / - / 5 and exitFrame(2 / 4 / 3));
//   then field_4C = -1. Needs GTSWork's byte at +0xf0 (an unk array in GTSWork.h) and the
//   vtable slots fixed (vf17 at +0x44, exitFrame at +0x24).
// - GTS:0x00003BC8 vf10: f_GTS_00012B58(field_44); RemoveAllSubView() on the UIViews at
//   GTSWork +0x98 and +0x9c (inside GTSWork's unk_3C); then calls on field_44->field_34
//   (f_GTS_00012A88(this, view), f_GTS_0001284C(view, 1, 1), f_GTS_00012C78(view, 0),
//   f_GTS_00012C28(view, 0)), f_GTS_0000747C(GTSStartStateConfirmResponseListener base, field_40);
//   returns true. Needs those two GTSWork members.
// - GTS:0x0001AC50, GTS:0x0001AC60: the thunks of this class's overrides of
//   GTSStartStateConfirmResponseListener's slots 4 and 2 (same bodies as vf22 and vf20). The
//   listeners all name their slots vf0, vf1..., so one override cannot be told from another:
//   they need the listeners' real names.

}  // namespace StateConfirm
}  // namespace GTS
}  // namespace NetApp
