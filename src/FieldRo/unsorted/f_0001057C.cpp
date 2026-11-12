#include "types.h"
#include "GameSys/GameManager.h"
#include "gfl2/ui/DeviceManager.h"
#include "gfl2/ui/Button.h"

//! FieldRo:0x0001057C f_FieldRo_0001057C
extern "C" int f_FieldRo_0001057C(u8 *a1, u8 *a2) {
    int result = 0;
    GameSys::GameManager *gm = *(GameSys::GameManager **)(*(u8 **)(a1 + 0x44) + 0x94);
    gfl2::ui::DeviceManager *dm = gm->GetUiDeviceManager();
    gfl2::ui::Button *btn = dm->GetButton(0);
    if (btn->IsRelease(*(unsigned int *)(a2 + 4) & ~0x60000u, (gfl2::ui::Button::InputStateID)0) != 0)
        result = 1;
    return result;
}
