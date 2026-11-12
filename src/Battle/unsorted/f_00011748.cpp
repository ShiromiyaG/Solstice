#include "types.h"

// callee without a name: f_Battle_0008BEB4
void f_Battle_0008BEB4(void *a1, u8 *a2, int a3);

//! Battle:0x00011748 f_Battle_00011748
int f_Battle_00011748(u8 *a1) {
    f_Battle_0008BEB4(*(void **)(a1 + 0xa3c), a1, 0);
    f_Battle_0008BEB4(*(void **)(a1 + 0xa40), a1, 1);
    return 1;
}
