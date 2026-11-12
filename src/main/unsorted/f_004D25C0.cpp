#include "types.h"

extern "C" u8 *sub_003351FC(u8 *);

typedef void (*VFn)(void *, void *);

//! 0x004D25C0 f_004D25C0
extern "C" void f_004D25C0(u8 *self)
{
    u8 *v = sub_003351FC(self - 8);
    void *obj = *(void **)(v + 4);
    VFn fn = (VFn)((*(void ***)obj)[4]);
    fn(obj, v);
}
