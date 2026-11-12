#include "types.h"

// open: the game has a removed call (`mov r0, r0`) before the operator delete: a call to the
// destructor of the pointed-to class, which only returns. the class is not known yet, so this
// source has no call there. tried: a plain delete of the pointer at +4 (the first check).
//! FieldRo:0x00037664 f_FieldRo_00037664
u8 *f_FieldRo_00037664(u8 *a1) {
    if (*(void **)(a1 + 4) != 0) {
        ::operator delete(*(void **)(a1 + 4));
        *(void **)(a1 + 4) = 0;
    }
    return a1;
}
