#include "types.h"

typedef int (*VirtualFn)(void *);

// open: the game keeps r1 free and uses r2 for the kind byte and the vtable loads; this uses r1.
// Tried: the vtable in a local, the kind tested with 0 first, the 0 case last. Same register
// choice, and one order gives 48 bytes against the game's 52. Second try: the zero as a result
// local returned at the end (the game sets r0 to 0 before a branch to one shared bx lr).
//! MantainSurf:0x0001D894 f_MantainSurf_0001D894
int f_MantainSurf_0001D894(void *a1, u8 *a2) {
    s8 kind = *(s8 *)(a2 + 4);
    int result = 0;
    if (kind == 0)
        return (*(VirtualFn **)a1)[2](a1);
    if (kind == 1)
        return (*(VirtualFn **)a1)[3](a1);
    return result;
}
