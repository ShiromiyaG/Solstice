#include "gfl2/animation/KeyAnimationSlot.h"
#include "types.h"

namespace gfl2 {
namespace animation {

// open: this is the constructor of KeyAnimationSlot (vtable 0x0064B690, the base constructor at
// 0x0036BA28). It writes this+0x34, +0x38 and +0x3c, which the generated header has as unk_34[8]
// and field_3C. The header must name +0x34 (u32) and +0x38 (u32) before this can be written.
//! 0x0036A874 KeyAnimationSlot
KeyAnimationSlot::KeyAnimationSlot() {
}

}  // namespace animation
}  // namespace gfl2
