#include "types.h"
#include "Regulation.h"

namespace gfl2 { namespace debug { void GFLassert(const char *, u32, s32, const char *); } }

// the else path calls the assert with four zero arguments (the linker removed the call: mov r0,r0).
// field_10 is a void * in the header: the code reads the byte at +0xc of the object it points to
// (a cast, the type is a guess). the game returns that byte as it is (ldrb, no compare): the
// header's bool is a guess, and a u8 return would be the match (returns.csv, not written here).
//! 0x004924A8 GetLevelRangeType
bool Regulation::GetLevelRangeType() const {
    u8 *p = (u8 *)field_10;
    if (p)
        return p[0xc];
    gfl2::debug::GFLassert(0, 0, 0, 0);
    return 0;
}
