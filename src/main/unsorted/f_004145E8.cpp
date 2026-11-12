#include "types.h"

extern char data_006925E8[];

// open: the game loads the vtable into r2 and ours into r1 (3 words differ);
// tried: typed function pointer, return 0 on the empty path, a second load.
//! 0x004145E8 f_004145E8
void *f_004145E8() {
    void *obj = *(void **)(data_006925E8 + 8);
    if (obj) {
        return ((void *(*)(void *))(*(void ***)obj)[8])(obj);
    }
    return obj;
}
