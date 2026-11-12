#include "Field/IFieldActorBase.h"
#include "gfl2/math/Vector3.h"
#include "gfl2/math/Quaternion.h"

namespace Field {

// what the base class answers for slots 12 and 13 (a position and a rotation, guesses from
// FieldMapJumpActor's, which read them from its object): zero
//! FieldRo:0x0008AFF4 vf12
gfl2::math::Vector3 IFieldActorBase::vf12()
{
    return gfl2::math::Vector3(0.0f, 0.0f, 0.0f);
}

//! FieldRo:0x0008B00C vf13
gfl2::math::Quaternion IFieldActorBase::vf13()
{
    return gfl2::math::Quaternion(0.0f, 0.0f, 0.0f, 0.0f);
}

}  // namespace Field
