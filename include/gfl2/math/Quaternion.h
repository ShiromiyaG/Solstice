#ifndef GFL2_MATH_QUATERNION_H
#define GFL2_MATH_QUATERNION_H

#include "types.h"

namespace gfl2 {
namespace math {

// four floats, built like Vector3 (see there): Field::FieldMapJumpActor slot 13
// (FieldRo:0008B144) returns one through r0 and copies it by a setter, and matches with
// this. that it is a quaternion, and not a Vector4, is a guess (config/us-v1.2/returns.csv);
// the member names and Set are ours.
class Quaternion {
public:
    f32 x;
    f32 y;
    f32 z;
    f32 w;

    Quaternion() {}
    Quaternion(f32 x_, f32 y_, f32 z_, f32 w_) { Set(x_, y_, z_, w_); }
    Quaternion(const Quaternion &q) { Set(q.x, q.y, q.z, q.w); }

    void Set(f32 x_, f32 y_, f32 z_, f32 w_)
    {
        x = x_;
        y = y_;
        z = z_;
        w = w_;
    }
};

}  // namespace math
}  // namespace gfl2

#endif
