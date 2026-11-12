#include "types.h"

// callee without a name: f_MovieLib_00000C88
void f_MovieLib_00000C88();

//! MovieLib:0x000017F0 f_MovieLib_000017F0
int f_MovieLib_000017F0(u8 *a1) {
    int result = *(int *)(a1 + 0xc);
    if (result != -1 && a1[0x24] == 1) {
        f_MovieLib_00000C88();
        a1[0x24] = 0;
        a1[0x25] = 1;
        return 1;
    }
    return result;
}
