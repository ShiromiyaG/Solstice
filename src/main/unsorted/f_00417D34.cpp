#include "types.h"

// gflnet2 calls, names from functions.csv or by address
extern "C" int sub_0040A414(void);
extern "C" int sub_00187C5C(void);

//! 0x00417D34 sub_00417D34
extern "C" int sub_00417D34(void)
{
    int result = sub_0040A414();
    if (result) {
        return sub_00187C5C();
    }
    return result;
}
