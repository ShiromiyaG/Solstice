// no class known; the object at a1 holds a pointer at +0x48 to a child whose vtable slot 27 is called.

//! Resort:0x00002F40 f_Resort_00002F40
int f_Resort_00002F40(int a1) {
    int result = *(int *)(a1 + 0x48);
    if (result) {
        return (*(int (**)(int))(*(int *)result + 0x6c))(result);
    }
    return result;
}
