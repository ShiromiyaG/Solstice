#ifndef APP_TOOL_FINGERCURSOR_H
#define APP_TOOL_FINGERCURSOR_H

#include "app/ui/UIView.h"
#include "app/util/G2DUtil.h"
#include "gfl2/gfx/CtrDisplayNo.h"

#include "types.h"

namespace app { namespace util { class AppRenderingManager; } }
namespace app { namespace util { class Heap; } }

namespace app {
namespace tool {

class FingerCursor : public ::app::ui::UIView {
public:
    // 1 byte, unsigned: a guess: no caller shows it, the smallest that holds the constants passed. the values are placeholders that give it that size
    enum FormType { FormType_placeholder_low = 0, FormType_placeholder_high = 0xFF };

    virtual ~FingerCursor();
    virtual void Draw(::gfl2::gfx::CtrDisplayNo);  // overrides  // slot 14, code.bin:002F2BC8

    // member functions the game names. static or not is not in a name, nor is the return type
    // (void until config/<version>/returns.csv has it)
    void CreateLytBinData(::app::util::Heap*);  // code.bin:002F2AF8
    void DeleteLytBinData(void*);  // code.bin:002F2BA8
    FingerCursor(::app::util::Heap*, void*, ::app::util::AppRenderingManager*, ::app::util::G2DUtil::SETUP_DISPLAY_TYPE, unsigned char);  // code.bin:002F2C60
    bool IsEndPushAnime(::app::tool::FingerCursor::FormType);  // code.bin:002F2AD0; the return type is a guess from its callers: only tested, and the name asks
    void PushAnime(::app::tool::FingerCursor::FormType);  // code.bin:002F2C00
    void StartAnime(::app::tool::FingerCursor::FormType);  // code.bin:002F2A74

    // data members, from how the class's functions use this (tools/fields.py)
    u32 field_60;  // +0x60, a guess: read by IsEndPushAnime (the animation's handle)
    u32 field_80;  // +0x80, a guess: from 1 function
    u8 field_84;  // +0x84, a guess: from 1 function
};

}  // namespace tool
}  // namespace app

#endif
