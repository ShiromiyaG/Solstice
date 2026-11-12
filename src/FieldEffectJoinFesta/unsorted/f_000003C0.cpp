#include "types.h"

// open: the game stores the pair with one vstmia (add r1, r0, #8; vstmia r1, {s0, s1});
// tried separate stores, a struct copy: both DIFFER.
// a pair of floats, the element of the object's second member (guess: a 2d vector)
struct FieldEffectPair {
    f32 x;
    f32 y;
};

//! FieldEffectJoinFesta:0x000003C0 f_FieldEffectJoinFesta_000003C0
extern "C" f32 *f_FieldEffectJoinFesta_000003C0(f32 *result)
{
    FieldEffectPair p;

    result[0] = 0.0f;
    result[1] = 0.0f;
    p.x = 0.0f;
    p.y = 1.0f;
    *(FieldEffectPair *)(result + 2) = p;
    return result;
}
