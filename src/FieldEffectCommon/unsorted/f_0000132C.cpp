#include "types.h"

int f_FieldEffectCommon_00000190(void *a1, void *a2, int a3, int a4, int a5, int a6, int a7);

//! FieldEffectCommon:0x0000132C f_FieldEffectCommon_0000132C
int f_FieldEffectCommon_0000132C(u8 *a1, int a2) {
    int result = f_FieldEffectCommon_00000190(*(void **)(a1 + 0x18), *(void **)(a1 + 0x1c), a2, 0, 17, 0, -1);
    *(u8 *)(a1 + 0xd) = 17;
    return result;
}
