typedef int (*VFn)(int, int, int, int);

//! 0x00339090 sub_00339090
int sub_00339090(int a1, int a2, int a3) {
    return (*(VFn *)(*(int *)a2 + 8))(a2, *(int *)(a1 + 4), a1 + 0x70, a3);
}
