#include "gfl2/gfx/ctr/CTRBlendStateObject.h"

namespace gfl2 {
namespace gfx {
namespace ctr {

//! 0x0035243C vf11
void CTRBlendStateObject::vf11(u32 a1, u8 a2)
{
    vf10(a1, a2, a1, a2);
    field_54 = 0;
}

}  // namespace ctr
}  // namespace gfx
}  // namespace gfl2
