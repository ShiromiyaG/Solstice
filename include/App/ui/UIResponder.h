#ifndef APP_UI_UIRESPONDER_H
#define APP_UI_UIRESPONDER_H

#include "app/tool/ButtonManager.h"
// not needed by this class any more (its member at +0x10 was a wrong guess); kept because other
// headers may reach it through this one
#include "NetAppLib/UI/NetAppCommonMessageWindowManipulator.h"

#include "types.h"

namespace app { namespace tool { class ButtonManager; } }
namespace app { namespace ui { class ButtonInfoEx; } }
namespace app { namespace ui { class ButtonInfoLytWk; } }
namespace app { namespace ui { class UIInputListener; } }
namespace app { namespace ui { class UIView; } }
namespace app { namespace util { class Heap; } }
namespace gfl2 { namespace lyt { class LytWk; } }
namespace gfl2 { namespace ui { class Button; } }
namespace gfl2 { namespace ui { class DeviceManager; } }
namespace gfl2 { namespace ui { class TouchPanel; } }
namespace gfl2 { namespace ui { class VectorDevice; } }

namespace app {
namespace ui {

// 0x34 bytes: the constructor (code.bin:002EE160) sets every member; app::ui::UIView's members
// start at +0x34.
class UIResponder : public ::app::tool::ButtonManager::IButtonCallback {
public:
    // slots 0 to 4 override app::tool::ButtonManager::IButtonCallback (slot 2 is its own).
    // slots 0 and 1: the code of 002EE0A0 and 002EE0D8 returns nothing (r0 is only the value
    // stored to +0x2c), so the real return type is void. They stay bool here because ~215
    // derived headers redeclare them as bool; config/us-v1.2/returns.csv needs void for both.
    virtual void CallbackFuncOnButtonSelected(unsigned int);  // slot 0, code.bin:002EE0A0; returns nothing (its versions leave r0)
    virtual void CallbackFuncOnButtonLongPressed(unsigned int);  // slot 1, code.bin:002EE0D8; returns nothing
    virtual void CallbackFuncOnButtonSelectedBeforeAnime(unsigned int);  // slot 3, code.bin:002EE13C
    virtual void CallBackFuncOnButtonTouchTrigger(unsigned int);  // slot 4, code.bin:002EE110
    virtual ~UIResponder();  // slots 5 (code.bin:002EE240) and 6 (code.bin:002EE1FC)
    virtual void OnSetInputEnabled(bool);  // slot 7, code.bin:002EDD1C (empty, out of line)
    virtual bool IsButtonAnimation() const;  // slot 8, code.bin:004AAD04

    // member functions the game names. static or not is not in a name, nor is the return type
    // (void until config/<version>/returns.csv has it)
    void CreateButtonManager(::app::util::Heap*, ::app::ui::ButtonInfoLytWk const*, unsigned int);  // code.bin:002EDD20
    void CreateButtonManager(::app::util::Heap*, ::gfl2::lyt::LytWk*, ::app::ui::ButtonInfoEx const*, unsigned int);  // code.bin:002EDDE4
    ::app::tool::ButtonManager *GetButtonManager();  // code.bin:002EDC9C; returns field_10
    bool IsHoldTouchPanel() const;  // code.bin:004B5F54; field_28's IsTouch (a tail call)
    // returns field_2D; ldrsb in the code. a guess: bool (a getter of a bool member); the
    // generated header had s8
    bool IsInputEnabled() const;  // code.bin:004AACFC
    void ReleaseButtonManager();  // code.bin:002EE01C
    void ReloadButtonManager(::app::util::Heap*, ::gfl2::lyt::LytWk*, ::app::ui::ButtonInfoEx const*, unsigned int);  // code.bin:002EDEA0
    void SetButtonEnable(unsigned int, bool, bool);  // code.bin:002EDB84
    void SetInputEnabled(bool);  // code.bin:002EDC7C; writes field_2D, then calls slot 7
    void SetInputExclusiveKeyByButtonAnimation(bool);  // code.bin:002EE134; writes field_31
    void SetInputListener(::app::ui::UIInputListener*);  // code.bin:002EDD14; writes field_14
    void SetStickEmulationMode(bool);  // code.bin:002EE04C; field_24 and field_1C again from field_18
    void SetTouchEnabled(bool);  // code.bin:002EDC8C; writes field_30

    // unnamed: its name sorts between ReloadButtonManager and ReleaseButtonManager. it erases
    // every element of the list at +0x4 and deletes the object each one points to (a guess:
    // the buttons' data); ReleaseButtonManager and ~UIResponder call it first
    void sub_002EDFBC();  // code.bin:002EDFBC

    // data members (from the constructor 002EE160 and the functions above; types from what
    // they are passed to, names are guesses)
    // +0x4..+0xF: a linked list as nw::ut::internal::LinkListImpl lays it out (a guess: its
    // erase 00289654 is called on +0x4): the count, then the end node's next and prev, both
    // set to +0x8 by the constructor. its elements hold the node at +0x4.
    u32 field_4;  // +0x4: the list's count
    void *field_8;  // +0x8: the end node's next
    void *field_C;  // +0xc: the end node's prev
    ::app::tool::ButtonManager *field_10;  // +0x10: GetButtonManager; deleted by ReleaseButtonManager
    ::app::ui::UIInputListener *field_14;  // +0x14: SetInputListener; the button callbacks call its slots 2 to 5
    ::gfl2::ui::DeviceManager *field_18;  // +0x18: GameSys::GameManager::GetUiDeviceManager
    ::gfl2::ui::VectorDevice *field_1C;  // +0x1c: field_18->GetCrossKey(1); SetStickEmulationMode(b) takes GetCrossKey(b)
    ::gfl2::ui::VectorDevice *field_20;  // +0x20: field_18->GetStick(0)
    ::gfl2::ui::Button *field_24;  // +0x24: field_18->GetButton(1); SetStickEmulationMode(b) takes GetButton(b)
    ::gfl2::ui::TouchPanel *field_28;  // +0x28: field_18->GetTouchPanel(0)
    bool field_2C;  // +0x2c: set when the listener answered 0 (a guess: input locked for the frame); false at first
    bool field_2D;  // +0x2d: input enabled (SetInputEnabled, IsInputEnabled); true at first
    bool field_2E;  // +0x2e: false at first
    bool field_2F;  // +0x2f: true at first
    bool field_30;  // +0x30: touch enabled (SetTouchEnabled); true at first
    bool field_31;  // +0x31: SetInputExclusiveKeyByButtonAnimation; true at first
};

}  // namespace ui
}  // namespace app

#endif
