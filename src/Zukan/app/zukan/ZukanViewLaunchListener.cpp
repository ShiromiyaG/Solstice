#include "app/zukan/ZukanViewLaunchListener.h"

// unnamed; field_4 is passed to it as its first argument (the header types field_4 as
// app::ui::UIResponder *, a guess of tools/fields.py)
void f_Zukan_00015B14(::app::ui::UIResponder *, u32, u32);

namespace app {
namespace zukan {

// UIInputListener slot 2 (a button selected; a1 is its id). 0 and 1 stand for the values of
// the listener's result (an enum; the header has bool)
//! Zukan:0x0001F2AC vf2
bool ZukanViewLaunchListener::UIInputListener_vf2(u32 a1)
{
    // open: DIFFER in 3 words, field_8 is held in ip where the game uses r2. Tried: if/else and
    // switch with a result (both this), returns from each case (the 1 set up front is lost).
    // a guess: the result's real type (an enum) or f_Zukan_00015B14's real signature
    bool result = true;
    switch (field_8) {
    case 1:
        result = false;
        break;
    case 2:
        f_Zukan_00015B14(field_4, 5, a1);
        result = false;
        break;
    }
    return result;
}

}  // namespace zukan
}  // namespace app
