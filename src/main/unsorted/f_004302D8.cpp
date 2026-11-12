#include "types.h"

// open. callees without names: sub_00430304 takes this + 0x64 and three floats. the class is not
// known (the scope is poke_3d::renderer). the game reads the three floats from the caller's stack
// area (vldmia at sp + 0x10, the incoming stack arguments) and passes them on through its own
// outgoing area: a by-value struct on the stack, not in s0..s2. tried: a three-float struct
// by value (DIFFER: it arrives in s registers, 8 bytes against 36).
struct sub_004302D8_vec3 {
    float x, y, z;
};

int sub_00430304(u8 *self, sub_004302D8_vec3 v);

//! 0x004302D8 sub_004302D8
int sub_004302D8(u8 *a1, sub_004302D8_vec3 v) {
    return sub_00430304(a1 + 0x64, v);
}
