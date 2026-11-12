#include "types.h"

//! FieldRo:0x0002248C f_FieldRo_0002248C
int f_FieldRo_0002248C(u8 *a1) {
    unsigned int i;
    for (i = 0; i < 0xA; ++i) {
        u8 *v2 = *(u8 **)(a1 + 4 * i + 0x38);
        int v3 = *(int *)(v2 + 0xe4);
        if (v3 != 0x23 && *(u8 *)(v2 + 0x10f) != 0) {
            return 0;
        }
    }
    return 1;
}
