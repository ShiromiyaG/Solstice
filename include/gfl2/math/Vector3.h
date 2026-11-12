#ifndef GFL2_MATH_VECTOR3_H
#define GFL2_MATH_VECTOR3_H

#include "types.h"

namespace gfl2 {
namespace math {

// a vector of three floats. what the game shows of it (Field::FieldMapJumpActor slot 12,
// FieldRo:0008B130, and its base's, FieldRo:0008AFF4, both match with this):
// - it is 12 bytes of floats, and it is returned through r0 (with this in r1): not plain
//   data, so it has constructors of its own;
// - a copy reads all three before it writes one (vldmia then vstmia): the copy constructor
//   hands them to a setter, which a copy by members does not do.
// the member names, Set and the constructor from values (with Set or a member list, the
// game's code cannot tell) are ours.
class Vector3 {
public:
    f32 x;
    f32 y;
    f32 z;

    Vector3() {}
    Vector3(f32 x_, f32 y_, f32 z_) { Set(x_, y_, z_); }
    Vector3(const Vector3 &v) { Set(v.x, v.y, v.z); }

    void Set(f32 x_, f32 y_, f32 z_)
    {
        x = x_;
        y = y_;
        z = z_;
    }
};

}  // namespace math
}  // namespace gfl2

#endif
