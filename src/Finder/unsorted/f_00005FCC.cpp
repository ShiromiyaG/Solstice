#include "types.h"

extern int f_Finder_00008D6C(int a1, int a2);
extern int f_Finder_00005FF8(int a1, int a2, int a3);

//! Finder:0x00005FCC f_Finder_00005FCC
int f_Finder_00005FCC(int a1) {
    int v2 = f_Finder_00008D6C(*(int *)(a1 + 160), *(int *)(a1 + 180));
    return f_Finder_00005FF8(*(int *)(a1 + 160), *(int *)(a1 + 180), v2 ^ 1);
}
