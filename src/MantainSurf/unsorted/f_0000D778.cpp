#include "types.h"

extern "C" u8 *f_MantainSurf_000145E0();
extern "C" u8 data_MantainSurf_0002D3C0[];

//! MantainSurf:0x0000D778 f_MantainSurf_0000D778
extern "C" u8 *f_MantainSurf_0000D778()
{
    u8 *obj = f_MantainSurf_000145E0();
    u8 *vt = data_MantainSurf_0002D3C0;
    *(u8 **)obj = vt;
    f32 *f = (f32 *)(obj + 0xc4);
    f[0] = 0.0f;
    f[1] = 0.0f;
    f[2] = 0.0f;
    return obj;
}
