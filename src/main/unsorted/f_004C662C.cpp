#include "types.h"

// a const getter of three words at +0x128 (Savedata::Misc, a guess); no struct yet.
// returns nothing: the value left in r0 is the last one loaded, and the void form matches.
//! 0x004C662C sub_004C662C
void sub_004C662C(u32 *a1, u32 *a2, u32 *a3, u32 *a4) {
    *a2 = a1[74];
    *a3 = a1[75];
    *a4 = a1[76];
}
