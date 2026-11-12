#include "types.h"

// the module's functions at 0x00092678, 0x0002981C and 0x0008FCC0
int f_Battle_00092678(void *, u8);
void f_Battle_0002981C();
void f_Battle_0008FCC0(int);

//! Battle:0x000066AC f_Battle_000066AC
int f_Battle_000066AC(u8 *a1, int a2, u32 *a3) {
    int v3 = f_Battle_00092678(*(void **)(a1 + 0xc), (u8)*a3);
    f_Battle_0002981C();
    f_Battle_0008FCC0(v3);
    return 1;
}
