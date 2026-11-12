#include "types.h"

//! 0x004733CC sub_004733CC
extern "C" u8 *sub_004733CC(u8 *a1) {
    u8 *result = a1 + 0x119E7C;
    if (*result == 1)
        *result = 2;
    return result;
}
