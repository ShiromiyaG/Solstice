// callees named by their module offsets (no names yet)
int f_Battle_00087D18(int);
void f_Battle_0005FC38(int);

//! Battle:0x000DA070 f_Battle_000DA070
int f_Battle_000DA070(int a1, int a2, int a3, int *a4) {
    int result = f_Battle_00087D18(2);
    if (result == a3) {
        result = *a4;
        if (result == 1) {
            f_Battle_0005FC38(a1);
            *a4 = 0;
            return 0;
        }
    }
    return result;
}
