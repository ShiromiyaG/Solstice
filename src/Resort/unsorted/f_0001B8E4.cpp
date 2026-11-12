#include "types.h"

typedef int (*VirtualFn3)(void *, int, int);

// the object at +0x33c, its first virtual slot called with (3, 1) as a tail call
//! Resort:0x0001B8E4 f_Resort_0001B8E4
int f_Resort_0001B8E4(u8 *a1) {
    void *obj = *(void **)(a1 + 0x33c);
    VirtualFn3 fn = **(VirtualFn3 **)obj;
    return fn(obj, 3, 1);
}
