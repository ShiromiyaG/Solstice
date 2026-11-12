#include "types.h"
#include "NetApp/BattleSpot/Frame_InternetBattleMatching.h"

// the callee of the frame, not named yet (a guess at its parameters)
extern "C" void f_BattleSpot_0000E84C(void *, u32);

//! BattleSpot:0x00013A6C _ZN6NetApp10BattleSpot28Frame_InternetBattleMatching4vf21
void NetApp::BattleSpot::Frame_InternetBattleMatching::vf21() {
    f_BattleSpot_0000E84C(field_44, 0);
    field_4C = 7;
    field_48 = 7;
}
