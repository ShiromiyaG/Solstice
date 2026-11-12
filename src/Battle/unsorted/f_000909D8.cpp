#include "types.h"

int f_Battle_00092178(int a1, int a2, int a3);

typedef int (*VirtualFn)(int);

// open: the game loads the virtual function pointer into r2 and keeps r1 free; this compiles the
// pointer into r1 (vtable slot 97 at 0x184, then the call through it). Tried: a vtable pointer as a
// local, the slot called in one expression, a function-pointer variable, an int this, an extra
// unused parameter (diagnostic only, reverted). Each differs in r1/r2 only.
//! Battle:0x000909D8 f_Battle_000909D8
int f_Battle_000909D8(int a1) {
    VirtualFn fn = (*(VirtualFn **)a1)[97];
    int v = fn(a1);
    return f_Battle_00092178(a1, v, 5);
}
