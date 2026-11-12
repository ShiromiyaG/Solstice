// open: a2 < 2 chooses the element address and the load; ours compiles the select differently.
// the game emits the element address (add under lo), the zero (mov under hs), then the load (ldr
// under lo): ours loads before the zero. Tried: an if/else on a2, the ternary on the load, an
// indexed pointer (p[a2 + 7]), the two-test shape (worse: a reload of the flag); all DIFFER.
//! 0x004C40CC sub_004C40CC
int sub_004C40CC(int a1, unsigned int a2) {
    return a2 < 2 ? *(int *)(a1 + 4 * a2 + 0x1c) : 0;
}
