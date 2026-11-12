#include "types.h"

extern void f_Battle_0008A9D4(int a1, int a2, u8 *a3, u8 *a4);

//! Battle:0x000110E8 f_Battle_000110E8
int f_Battle_000110E8(int a1, int a2) {
    int result = *(u8 *)(*(int *)(a1 + 12) + 0x3d5);
    if (result == 6) {
        u8 v4;
        u8 v5;
        f_Battle_0008A9D4(a1, a2, &v5, &v4);
        result = v4;
        *(u8 *)(*(int *)(a1 + 12) + 0x3d5) = v4;
    }
    return result;
}
