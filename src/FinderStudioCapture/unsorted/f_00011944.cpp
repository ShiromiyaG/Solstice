#include "types.h"

extern "C" void *f_FinderStudioCapture_0000BFF4(void *p, int a2);

//! FinderStudioCapture:0x00011944 f_FinderStudioCapture_00011944
extern "C" u8 *f_FinderStudioCapture_00011944(u8 *a1, int a2) {
    u8 *v2 = *(u8 **)(a1 + 0x70);
    if (v2[0x4c] != a2) {
        v2[0x4c] = (u8)a2;
        return (u8 *)f_FinderStudioCapture_0000BFF4(*(void **)(a1 + 0x5c), a2);
    }
    return a1;
}
