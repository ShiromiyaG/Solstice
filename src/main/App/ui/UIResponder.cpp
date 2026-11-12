#include "App/ui/UIResponder.h"
#include "App/ui/UIInputListener.h"
#include "App/tool/ButtonManager.h"

namespace app {
namespace ui {

//! 0x002EE01C ReleaseButtonManager
void UIResponder::ReleaseButtonManager()
{
    sub_002EDFBC();
    if (field_10 != 0) {
        delete field_10;
        field_10 = 0;
    }
}

//! 0x002EE240 UIResponderD1Ev
//! 0x002EE1FC UIResponderD0Ev
UIResponder::~UIResponder()
{
    ReleaseButtonManager();
}

//! 0x002EE110 CallBackFuncOnButtonTouchTrigger
void UIResponder::CallBackFuncOnButtonTouchTrigger(unsigned int buttonId)
{
    if (field_2D && field_14 != 0) {
        field_14->UIInputListener_vf5(buttonId);
    }
}

//! 0x002EE13C CallbackFuncOnButtonSelectedBeforeAnime
void UIResponder::CallbackFuncOnButtonSelectedBeforeAnime(unsigned int buttonId)
{
    // open: UIInputListener slot 4 is declared without the button id the game passes it, so
    // the compiler frees r1 and the registers differ (r1 against the game's r2). It matches
    // once slot 4 takes (unsigned int) in UIInputListener and in every listener that overrides it.
    if (field_2D && field_14 != 0) {
        field_14->UIInputListener_vf4();
    }
}

//! 0x004AAD04 IsButtonAnimation
bool UIResponder::IsButtonAnimation() const
{
    if (field_10 != 0) {
        return field_10->GetUpdateState() != 0;
    }
    return false;
}

//! 0x004AACFC IsInputEnabled
bool UIResponder::IsInputEnabled() const
{
    return field_2D;
}

}  // namespace ui
}  // namespace app
