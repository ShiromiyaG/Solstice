#include "types.h"

int f_JoinFestaPlayerDetail_00000348(void *a1);

//! JoinFestaPlayerDetail:0x00001B98 f_JoinFestaPlayerDetail_00001B98
int f_JoinFestaPlayerDetail_00001B98(u8 *a1, void *a2) {
    int result = f_JoinFestaPlayerDetail_00000348(*(void **)(a1 + 0x10));
    *(void **)(a1 + 0x10) = a2;
    return result;
}
