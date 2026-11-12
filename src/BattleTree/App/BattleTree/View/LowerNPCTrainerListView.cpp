#include "App/BattleTree/View/LowerNPCTrainerListView.h"

namespace App {
namespace BattleTree {
namespace View {

// the override of ScrollPaneManager::Listener's slot 1 (through the base at +0xa0): the compiler
// makes the thunk at -160 from it.
//! BattleTree:0x0000372C _ZThn160_N3App10BattleTree4View23LowerNPCTrainerListView12Listener_vf1
void LowerNPCTrainerListView::Listener_vf1(u32 a1, u32 a2) {
    field_CC = a2;
    field_A8 = 3;
    field_C8 = true;
    SetInputEnabledAllView(false);
}

}  // namespace View
}  // namespace BattleTree
}  // namespace App
