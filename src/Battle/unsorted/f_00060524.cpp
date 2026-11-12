// no class known; the callee at 0x92670 returns a pointer whose u16 fields at +12 and +18 go to the callee at 0x6B11C.

char *f_Battle_00092670();
int f_Battle_0006B11C(int a1, unsigned short a2, unsigned short a3);

//! Battle:0x00060524 f_Battle_00060524
int f_Battle_00060524(int a1) {
    char *v2 = f_Battle_00092670();
    unsigned short v3 = *(unsigned short *)(v2 + 12);
    unsigned short v4 = *(unsigned short *)(v2 + 18);
    return f_Battle_0006B11C(a1, v3, v4) != 0;
}
