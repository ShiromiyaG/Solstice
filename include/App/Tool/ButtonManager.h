#ifndef APP_TOOL_BUTTONMANAGER_H
#define APP_TOOL_BUTTONMANAGER_H

#include "types.h"

namespace gfl2 { namespace heap { class CtrHeapBase; } }
namespace gfl2 { namespace lyt { class LytWk; } }
namespace gfl2 { namespace ui { class DeviceManager; } }
namespace nw { namespace lyt { class Pane; } }

namespace app {
namespace tool {

class ButtonManager {
public:
    // 1 byte, unsigned: a guess: no caller shows it, the smallest that holds the constants passed. the values are placeholders that give it that size
    enum BindKeyMode { BindKeyMode_placeholder_low = 0, BindKeyMode_placeholder_high = 0xFF };
    // 1 byte, unsigned: a guess: no caller shows it, the smallest that holds the constants passed. the values are placeholders that give it that size
    enum ButtonProcess { ButtonProcess_placeholder_low = 0, ButtonProcess_placeholder_high = 0xFF };
    // 1 byte, unsigned: a guess: no caller shows it, the smallest that holds the constants passed. the values are placeholders that give it that size
    enum InputMode { InputMode_placeholder_low = 0, InputMode_placeholder_high = 0xFF };
    // 1 byte, unsigned: a guess: no caller shows it, the smallest that holds the constants passed. the values are placeholders that give it that size
    enum NotifyTimming { NotifyTimming_placeholder_low = 0, NotifyTimming_placeholder_high = 0xFF };

    class Button {
    public:
        virtual void vf0();  // slot 0, code.bin:002F51B8
        virtual void vf1();  // slot 1, code.bin:002F51B4
    };

    // the interface app::ui::UIResponder implements (its slots 0 to 4). the game never writes
    // its vtable, so the slots are known from UIResponder's. pure or not is a guess for slots
    // 0, 1, 3, 4 (no body of this class is found for them). slots 0 and 1: their code returns
    // nothing, so the real return type is void; they stay bool while the derived headers
    // redeclare them so (see app/ui/UIResponder.h).
    class IButtonCallback {
    public:
        virtual void CallbackFuncOnButtonSelected(unsigned int) = 0;  // slot 0; returns nothing (UIResponder's leaves r0)
        virtual void CallbackFuncOnButtonLongPressed(unsigned int) = 0;  // slot 1; returns nothing
        // slot 2, code.bin:002F3248 (bx lr), with copies in the modules (so inline). its name
        // is not known; it sorts between ButtonManager::SetInputEnable and SetButtonActive, so
        // IButtonCallback's is a guess that fits. it reads no parameter
        virtual void vf2() {}
        virtual void CallbackFuncOnButtonSelectedBeforeAnime(unsigned int) = 0;  // slot 3
        virtual void CallBackFuncOnButtonTouchTrigger(unsigned int) = 0;  // slot 4
    };

    class IProcessManager {
    public:
    };

    class MultipleProcessManager : public ::app::tool::ButtonManager::IProcessManager {
    public:
        virtual void vf0();  // slot 0, code.bin:002F3E88
        virtual void vf1();  // slot 1, code.bin:002F3E84
        virtual void vf2(u32 a1, u32 a2, u32 a3);  // slot 2, code.bin:002F3CB0; the parameters are a guess from its code (types too)
        virtual bool vf3();  // slot 3, code.bin:004AB6C4; the return type is a guess from its code
        virtual void vf4();  // slot 4, code.bin:004AB708
        virtual void vf5();  // slot 5, code.bin:004AB750
        virtual void vf6();  // slot 6, code.bin:004AB67C
        virtual void vf7();  // slot 7, code.bin:004AB7E4
        virtual bool vf8();  // slot 8, code.bin:004AB638; the return type is a guess from its code
        virtual s8 vf9();  // slot 9, code.bin:004AB5F4
        virtual bool vf10();  // slot 10, code.bin:004AB5B0; the return type is a guess from its code
        virtual bool vf11();  // slot 11, code.bin:004AB798; the return type is a guess from its code
        virtual void vf12(u32 a1);  // slot 12, code.bin:002F3BC8; the parameters are a guess from its code (types too)
        virtual void vf13();  // slot 13, code.bin:002F3B7C
        virtual void vf14(u32 a1);  // slot 14, code.bin:002F3C54; the parameters are a guess from its code (types too)

        // data members, from how the class's functions use this (tools/fields.py)
        void *field_4;  // +0x4, a guess: a pointer, from 17 functions
        void *field_8;  // +0x8, a guess: a pointer, from 26 functions
    };

    class SingleProcessManager : public ::app::tool::ButtonManager::IProcessManager {
    public:
        virtual void vf0();  // slot 0, code.bin:002F3B24
        virtual void vf1();  // slot 1, code.bin:002F3B20
        virtual void vf2(u32 a1, u32 a2, u32 a3);  // slot 2, code.bin:002F3900; the parameters are a guess from its code (types too)
        virtual bool vf3();  // slot 3, code.bin:004AB4BC; the return type is a guess from its code
        virtual void vf4();  // slot 4, code.bin:004AB4CC
        virtual void vf5();  // slot 5, code.bin:004AB504
        virtual void vf6();  // slot 6, code.bin:004AB484
        virtual void vf7();  // slot 7, code.bin:004AB578
        virtual bool vf8();  // slot 8, code.bin:004AB460; the return type is a guess from its code
        virtual s8 vf9();  // slot 9, code.bin:004AB43C
        virtual bool vf10();  // slot 10, code.bin:004AB418; the return type is a guess from its code
        virtual bool vf11();  // slot 11, code.bin:004AB53C; the return type is a guess from its code
        virtual void vf12(u32 a1);  // slot 12, code.bin:002F3818; the parameters are a guess from its code (types too)
        virtual void vf13();  // slot 13, code.bin:002F37D4
        virtual void vf14(u32 a1);  // slot 14, code.bin:002F38AC; the parameters are a guess from its code (types too)

        // data members, from how the class's functions use this (tools/fields.py)
        void *field_4;  // +0x4, a guess: a pointer, from 13 functions
        void *field_8;  // +0x8, a guess: a pointer, from 16 functions
        u8 field_C;  // +0xc, a guess: from 5 functions
        u8 unk_D[0x3];  // +0xd: nothing seen to use it
        u32 field_10;  // +0x10, a guess: from 8 functions
    };

    virtual ~ButtonManager();

    // member functions the game names. static or not is not in a name, nor is the return type
    // (void until config/<version>/returns.csv has it)
    void AddButton(::gfl2::heap::CtrHeapBase*, unsigned int, ::gfl2::lyt::LytWk*, ::nw::lyt::Pane*, ::nw::lyt::Pane*, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, unsigned int, ::app::tool::ButtonManager::IButtonCallback*);  // code.bin:002F52B8
    ButtonManager(::gfl2::heap::CtrHeapBase*, ::gfl2::ui::DeviceManager const*, unsigned int, unsigned int);  // code.bin:002F5408
    void ChangeButtonProcessMode(::app::tool::ButtonManager::ButtonProcess, ::gfl2::heap::CtrHeapBase*);  // code.bin:002F3E8C
    void GetButtonPos(unsigned int) const;  // code.bin:004AB1C8
    void GetButtonPosByGfVec3(unsigned int) const;  // code.bin:004AB3F4
    u32 GetHoldingButtonId() const;  // code.bin:004AB390; the return type is a guess from its callers: used as a 32-bit integer
    u32 GetSelectedButtonId() const;  // code.bin:004AB3A0; the return type is a guess from its callers: used as a 32-bit integer
    u32 GetUpdateState() const;  // code.bin:004AB294; the return type is a guess from its callers: used as a 32-bit integer
    s8 IsButtonActive(unsigned int) const;  // code.bin:004AB30C; the return type is a guess from its callers: used as an integer; the width is what its own returns write
    bool IsButtonHit(unsigned int, unsigned short, unsigned short) const;  // code.bin:004AB154; the return type is a guess from its callers: only tested, and the name asks
    s8 IsButtonInputEnable(unsigned int) const;  // code.bin:004AB3B0; the return type is a guess from its callers: used as an integer; the width is what its own returns write
    bool IsButtonVisible(unsigned int) const;  // code.bin:004AB350; the return type is a guess from its callers: only tested, and the name asks
    void LinkButton(unsigned int const*, unsigned int);  // code.bin:002F30F0
    void ResetHoldState();  // code.bin:002F3230
    void SetButtonActive(unsigned int, bool);  // code.bin:002F3264
    void SetButtonActiveAnimeFrameLast(unsigned int);  // code.bin:002F3FD8
    void SetButtonActiveForce(unsigned int, bool);  // code.bin:002F3734
    void SetButtonBindKey(unsigned int, unsigned int, ::app::tool::ButtonManager::BindKeyMode);  // code.bin:002F32C0
    void SetButtonInputEnable(unsigned int, bool);  // code.bin:002F3788
    void SetButtonInvisible(unsigned int);  // code.bin:002F36D4
    void SetButtonLongPressFrame(unsigned int, unsigned int);  // code.bin:002F3F98
    void SetButtonPassive(unsigned int, bool);  // code.bin:002F331C
    void SetButtonPassiveAnimeFrameLast(unsigned int);  // code.bin:002F407C
    void SetButtonPassiveForce(unsigned int, bool);  // code.bin:002F3B28
    void SetButtonSelectSE(unsigned int, unsigned int);  // code.bin:002F35A8
    void SetButtonVisible(unsigned int, bool);  // code.bin:002F3378
    void SetInputEnable(bool);  // code.bin:002F3240
    void SetInputMode(::app::tool::ButtonManager::InputMode);  // code.bin:002F31F8
    void SetNotifyTimming(::app::tool::ButtonManager::NotifyTimming);  // code.bin:002F34FC
    void SetNotifyTimming(unsigned int, ::app::tool::ButtonManager::NotifyTimming);  // code.bin:002F352C
    void StartSelectedAct(unsigned int);  // code.bin:002F358C
    u32 Update();  // code.bin:002F51BC; the return type is a guess from its callers: used as a 32-bit integer

    // data members, from how the class's functions use this (tools/fields.py)
    f32 field_4;  // +0x4, a guess: from 3 functions
    f32 field_8;  // +0x8, a guess: from 3 functions
    u32 field_C;  // +0xc, a guess: from 2 functions
    void *field_10;  // +0x10, a guess: a pointer, from 40 functions
    u32 field_14;  // +0x14, a guess: from 1 function
    u32 field_18;  // +0x18, a guess: from 22 functions
    u8 unk_1C[0x4];  // +0x1c: nothing seen to use it
    u32 field_20;  // +0x20, a guess: from 1 function
    u8 field_24;  // +0x24, a guess: from 2 functions
    s8 field_25;  // +0x25, a guess: from 3 functions
    u8 unk_26[0x2];  // +0x26: nothing seen to use it
    void *field_28;  // +0x28, a guess: a pointer, from 21 functions
    u8 field_2C;  // +0x2c, a guess: from 3 functions
};

}  // namespace tool
}  // namespace app

#endif
