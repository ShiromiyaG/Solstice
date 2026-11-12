// no class known; the object's vtable slot 56 (offset 0xe0) is called with the object's field at 0x9c as the second argument.

//! Object:0x00005B9C f_Object_00005B9C
int f_Object_00005B9C(int *a1, int a2, int a3) {
    return (*(int (**)(int *, int, int, int))(*a1 + 0xe0))(a1, *(int *)((char *)a1 + 0x9c), a2, a3);
}
