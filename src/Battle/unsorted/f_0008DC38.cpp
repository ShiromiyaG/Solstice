#include "types.h"

// the next function of the module (0x0008DC5C), called as a tail call
int f_Battle_0008DC5C(u16, void *);

// the call at the end is a tail call the linker removed (mov r0, r0)
//! Battle:0x0008DC38 f_Battle_0008DC38
int f_Battle_0008DC38(u8 *a1) {
    void *v = *(void **)(a1 + 0x10);
    return f_Battle_0008DC5C(*(u16 *)(a1 + 0x1a), v);
}
