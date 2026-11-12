#include "types.h"

// the fade manager's singleton and its end check (names from functions.csv, the rest by address)
extern "C" void *sub_00360D68(void);
extern "C" int sub_00360714(void *, int);

//! 0x00383AA4 sub_00383AA4
extern "C" int sub_00383AA4(void)
{
    if (sub_00360714(sub_00360D68(), 0)) {
        if (sub_00360714(sub_00360D68(), 1)) {
            return 1;
        }
    }
    return 0;
}
