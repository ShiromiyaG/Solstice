#include "Regulation.h"

//! 0x00492530 GetParamMustPokeOR
u16 Regulation::GetParamMustPokeOR(unsigned char index) const {
    if (index < 6) {
        return *(u16 *)((u8 *)field_10 + 0x22 + index * 2);
    }
    return 0;
}
