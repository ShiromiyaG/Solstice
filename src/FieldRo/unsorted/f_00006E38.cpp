// no class known; a2 holds a pointer at +0x2c, whose child at +0x10 and +0x14 fill the three words.

// open: 4 words, only the registers of the two copies. tools/local/permute.py matches it with
// each copy through a local (int t = ...; w[0] = t;): what an inline getter of the child's class
// would give. left open until that class and its getters are known.
//! FieldRo:0x00006E38 f_FieldRo_00006E38
void *f_FieldRo_00006E38(void *result, int a2) {
    float *f = (float *)result;
    int *w = (int *)result;
    f[0] = 0.0f;
    f[1] = 0.0f;
    f[2] = 0.0f;
    if (*(int *)(a2 + 0x2c)) {
        w[0] = *(int *)(*(int *)(a2 + 0x2c) + 0x10);
        w[2] = *(int *)(*(int *)(a2 + 0x2c) + 0x14);
    }
    return result;
}
