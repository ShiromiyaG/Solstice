#include "types.h"

u32 f_FieldRo_00066ADC(u8 *, u32 *);

//! FieldRo:0x00026930 f_FieldRo_00026930
u32 f_FieldRo_00026930(u8 *a1, u32 a2)
{
    return f_FieldRo_00066ADC(a1 + 0x38, &a2);
}
