#include "types.h"

// the three words of a string (0 is empty) get the 0x3000 mark; the same value is returned.
// open: the game keeps 0x3000 in r0 from the start (it is the return value) and tests each word
// after its load; the variants with separate ifs or a result local give extra loads or a push.
//! StrInput:0x00004384 f_StrInput_00004384
int f_StrInput_00004384(int a1, u16 *a2) {
    int i;
    for (i = 0; i < 3; i++) {
        if (a2[i] == 0)
            a2[i] = 0x3000;
    }
    return 0x3000;
}
