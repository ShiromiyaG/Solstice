#ifndef GFL2_DEBUG_ASSERT_H
#define GFL2_DEBUG_ASSERT_H

#include "types.h"

// the assert functions the executable exports (static.crs). the parameters are their names'
// (expression or message, line, ...); the return types are not in a name: void, a guess
// (an assert's call is a statement). in a release build their calls are often NOPs the linker
// left (a call to a function that only returns).
namespace gfl2 {
namespace debug {

void GFLassert(const char *, unsigned int, int, const char *);  // code.bin, exported
void GFLassertStop(const char *, unsigned int, const char *);    // code.bin, exported

}  // namespace debug
}  // namespace gfl2

#endif
