#include "types.h"
#include <math.h>

// open: the game computes a2[1]*a2[1] first, then reads the pair a2[2], a2[3]
// with `add r1, r1, #8` and one vldmia (a pointer at +8). Tried: a pointer
// v = a2 + 2 (loads separate), a struct with the pair as pos (loads reordered),
// and an accumulator local (loads z alone). None gives the game's register
// order or its extra pointer add; not matched.

// names are guesses: the struct's first word is not used here
struct Vec3 {
    float x;
    float y;
    float z;
};

struct PosHolder {
    int field_0;
    Vec3 pos;
};

//! 0x00382068 sub_00382068
extern "C" float sub_00382068(int, PosHolder *a2)
{
    float sq = a2->pos.x * a2->pos.x;
    sq += a2->pos.y * a2->pos.y;
    sq += a2->pos.z * a2->pos.z;
    return sqrtf(sq);
}
