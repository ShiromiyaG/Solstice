#ifndef NETAPPLIB_UI_NETAPPCURSORVIEW_H
#define NETAPPLIB_UI_NETAPPCURSORVIEW_H

#include "NetAppLib/System/NetApplicationViewBase.h"
#include "app/ui/UIInputListener.h"
#include "app/tool/CursorController.h"
#include "gfl2/gfx/CtrDisplayNo.h"
#include "gfl2/lyt/LytMultiResID.h"

#include "types.h"

namespace NetAppLib { namespace System { class ApplicationWorkBase; } }
namespace gfl2 { namespace ui { class Button; } }
namespace gfl2 { namespace ui { class VectorDevice; } }
namespace nw { namespace lyt { class Pane; } }

namespace NetAppLib {
namespace UI {

// a NetApplicationViewBase that listens to its own input (UIInputListener at +0xa0, set as the
// listener by the constructor) and owns a cursor (CursorController at +0xac, the one in use at
// +0x10c; its events come back through IEventHandler at +0xa4).
//
// the primary vtable has 25 slots (the secondary vtables start at +0x6c and +0x90 of it):
// 22 OnLayoutPaneTouchTriggerEvent and 23 OnKeyAction are the overriders of UIInputListener's
// slots 5 and 6 (each has a thunk at -0xa0), 24 CursorController_OnEvent the overrider of
// IEventHandler's slot 2 (thunk at -0xa4); IEventHandler's slots 0 and 1 are its destructor
// (the thunks code.bin:004CC718, 004CC6D8 are ~NetAppCursorView).
// UIInputListener.h and CursorController.h do not have those names yet, so the overriders are
// declared here in their primary slots and do not override (the secondary vtables keep the
// bases' functions until those headers are fixed).
class NetAppCursorView : public ::NetAppLib::System::NetApplicationViewBase, public ::app::ui::UIInputListener, public ::app::tool::CursorController::IEventHandler {
public:
    NetAppCursorView(::NetAppLib::System::ApplicationWorkBase*);  // code.bin:00475B7C
    virtual ~NetAppCursorView();  // slots 5, 6: code.bin:00475C80, 00475C40
    virtual void Update();  // overrides  // slot 13, code.bin:00475B4C
    virtual void Draw(::gfl2::gfx::CtrDisplayNo);  // overrides  // slot 14, code.bin:00475B2C
    virtual bool IsDrawing() const;  // overrides  // slot 17, code.bin:004C90F4
    virtual void OnLayoutPaneTouchTriggerEvent(unsigned int);  // slot 22, code.bin:00475ADC; UIInputListener slot 5
    virtual void OnKeyAction(::gfl2::ui::Button*, ::gfl2::ui::VectorDevice*, ::gfl2::ui::VectorDevice*);  // slot 23, code.bin:004754D0; UIInputListener slot 6 (that slot returns bool there: a guess)
    virtual void CursorController_OnEvent(::app::tool::CursorController*, ::app::tool::CursorController::IEventHandler::EventCode);  // slot 24, code.bin:00475A98; IEventHandler slot 2

    void CreateCursor(int, unsigned int, unsigned int);  // code.bin:00475634
    void CreateCursor(int, unsigned int, unsigned int, unsigned int const*, unsigned int const*, unsigned int const*, int);  // code.bin:00475724
    void CursorMoveToButton(unsigned int);  // code.bin:00475A38
    void CursorMoveToIndex(unsigned int);  // code.bin:00475A20
    void ReleaseCursor();  // code.bin:00475908
    void SetCursorController(::app::tool::CursorController*);  // code.bin:00475A88: NULL means the own one (+0xac)
    void SetCursorVisible(bool);  // code.bin:002FA484
    void SetCusorPosPanes(::nw::lyt::Pane**, unsigned int const*, int);  // code.bin:0047595C

    ::NetAppLib::System::ApplicationWorkBase *field_A8;  // +0xa8: the work passed to the constructor
    ::app::tool::CursorController field_AC;  // +0xac: the own cursor, built with the work's heap (+0x8) and its rendering manager (+0x2c)
    ::app::tool::CursorController *field_10C;  // +0x10c: the cursor in use (the own one by default; SetCursorController)
    u32 field_110;  // +0x110, a guess: set to 0
    ::gfl2::lyt::LytMultiResID field_114;  // +0x114: built by LytMultiResID(), its empty destructor is the NOP in ~NetAppCursorView
    void *field_118;  // +0x118, a guess: a pointer, from 8 functions
    u32 field_11C;  // +0x11c, a guess: from 5 functions
    bool field_120;  // +0x120: the cursor is visible (SetCursorVisible; Update and Draw test it); set to true
    u32 field_124;  // +0x124..+0x13c: seven words set from one global (code.bin:005BE550); a guess: one array
    u32 field_128;
    u32 field_12C;
    u32 field_130;
    u32 field_134;
    u32 field_138;
    u32 field_13C;
};

}  // namespace UI
}  // namespace NetAppLib

#endif
