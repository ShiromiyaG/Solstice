#include "App/Resort/LowerFarmDraw.h"

namespace App {
namespace Resort {

// guesses: free functions of Resort that take this (their names and types are not known)
void f_Resort_0000B498(LowerFarmDraw *self);
void f_Resort_0001534C(LowerFarmDraw *self);

void sub_000140A8(LowerFarmDraw *self);  // guess: the function after Update, called as a tail call

//! Resort:0x00014090 Update
void LowerFarmDraw::Update() {
    ::app::ui::UIView::Update();
    sub_000140A8(this);
}

//! Resort:0x0000B774 vf26
void LowerFarmDraw::vf26() {
    f_Resort_0000B498(this);
    f_Resort_0001534C(this);
    SetVisible(true);
    ::app::ui::UIResponder::SetInputEnabled(true);
}

}  // namespace Resort
}  // namespace App
