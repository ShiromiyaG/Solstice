#ifndef GFL2_UTIL_FNVHASH_H
#define GFL2_UTIL_FNVHASH_H

#include "types.h"

namespace gfl2 {
namespace util {

// a 32-bit FNV hash of a string. it starts from the FNV prime itself, not from the usual
// offset basis: that is what the game does.
class FnvHash {
public:
    u32 value;

    explicit FnvHash(const u8 *str) : value(0x01000193)
    {
        for (; *str; ++str) {
            value *= 0x01000193;
            value ^= *str;
        }
    }
};

}  // namespace util
}  // namespace gfl2

#endif
