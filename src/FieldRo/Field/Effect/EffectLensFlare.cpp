#include "Field/Effect/EffectLensFlare.h"
#include "poke_3d/model/BaseModel.h"
#include "types.h"

namespace Field {
namespace Effect {

// the model at +0x10 is a poke_3d BaseModel (a guess: the header's unk_9 covers it); its SetVisible
// is called without the virtual dispatch (the game's bl goes straight to it). then a tail call with
// the two fields from +0xfc and +0xf4 (guesses: their types and the callee's are not known).
void f_FieldRo_00073B68(u32, void *);

//! FieldRo:0x00044F58 vf6
void EffectLensFlare::vf6() {
    ((::poke_3d::model::BaseModel *)((u8 *)this + 0x10))->::poke_3d::model::BaseModel::SetVisible(0);
    f_FieldRo_00073B68(field_FC, field_F4);
}

}  // namespace Effect
}  // namespace Field
