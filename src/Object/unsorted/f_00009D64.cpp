#include "types.h"

extern s8 *data_Object_00013000[];

//! Object:0x00009D64 f_Object_00009D64
s8 f_Object_00009D64(u32 a1, u32 a2)
{
    return data_Object_00013000[a2][a1 + 520];
}
