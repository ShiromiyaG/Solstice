#ifndef APP_UI_UIINPUTLISTENER_H
#define APP_UI_UIINPUTLISTENER_H

#include "types.h"

namespace app {
namespace ui {

// no data members, no destructor slot. app::ui::UIResponder (code.bin:002ED874 and the button
// callbacks 002EE0A0..002EE13C) calls every slot through UIResponder::field_14; what it passes
// and what it does with the result is below. The signatures stay as the derived headers
// redeclare them (u32/bool guesses): changing one here would break those redeclarations.
// What the code shows, for the tool (config and the derived headers):
// - slots 0, 1, 2, 3, 6 return a 3-value result that the caller tests against 0 and 2
//   (0: the responder sets UIResponder::field_2C; 2: also passes the view to UIViewManager),
//   so the real return type is an enum, not bool.
// - slot 0: (gfl2::ui::TouchPanel *, bool): field_28, then field_28->IsTouch().
// - slot 1: (gfl2::ui::TouchPanel *): field_28.
// - slots 2, 3, 4, 5: (unsigned int): the button id of IButtonCallback's slots 0, 1, 3, 4
//   (slots 3 and 4 are declared here without it, from what their versions read).
// - slot 4 and slot 5 return nothing.
// - slot 6: (gfl2::ui::Button *, gfl2::ui::VectorDevice *, gfl2::ui::VectorDevice *):
//   field_24, field_1C, field_20.
// slots 0 to 5: code.bin 002EE468..002EE48C return 1 or nothing, and the modules have their own
// copies (Zukan:00000F9C..00000FC0), so their bodies are inline.
class UIInputListener {
public:
    virtual bool UIInputListener_vf0(u32 a1) { return true; }  // slot 0, code.bin:002EE468; the parameters are a guess from its code (types too); the return type is a guess from its code
    virtual bool UIInputListener_vf1() { return true; }  // slot 1, code.bin:002EE478; the return type is a guess from its code
    virtual bool UIInputListener_vf2(u32 a1) { return true; }  // slot 2, code.bin:002EE470; the parameters are a guess from its code (types too); the return type is a guess from its code
    virtual bool UIInputListener_vf3() { return true; }  // slot 3, code.bin:002EE480; the return type is a guess from its code
    virtual void UIInputListener_vf4() {}  // slot 4, code.bin:002EE48C
    virtual void UIInputListener_vf5(u32 a1) {}  // slot 5, code.bin:002EE488; the parameters are a guess from its code (types too)
    virtual bool UIInputListener_vf6(u32 a1, u32 a2, u32 a3);  // slot 6, code.bin:004CAF34; the parameters are a guess from its code (types too); the return type is a guess from its code
};

}  // namespace ui
}  // namespace app

#endif
