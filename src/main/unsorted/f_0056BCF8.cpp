#include "types.h"

// the class is nn::nex::PseudoGlobalVariable<RankingDDLDeclarations> (no header yet): its element is 20 bytes (five words)
// open: the game loads the base pointer and adds the element offset before reading +0x24; this version reads +0x24 first.
// tried: u8 pointer arithmetic (4 words differ), a base local (4), the u32 element pointer (3, this one).
//! 0x0056BCF8 vf4
u8 sub_0056BCF8(u8 *a1, int a2) {
    u32 *e = *(u32 **)(a1 + 8) + a2 * 5;
    e[1] = *(u32 *)(a1 + 0x24);
    *((u8 *)e + 8) = *(u8 *)(a1 + 0x28);
    e[3] = *(u32 *)(a1 + 0x2c);
    u8 v = *(u8 *)(a1 + 0x30);
    *((u8 *)e + 16) = v;
    return v;
}
