#include "NetApp/Gift/Frame_Instruction.h"

// the callees of vf10, named by their addresses (guessed argument types)
void f_MysteryGift_0000B168(u32, u32);
void f_MysteryGift_0000C4BC(u32, u32);
void f_MysteryGift_00009CC8(u32, u32);
void f_MysteryGift_0000D8E4(void *);

namespace NetApp {
namespace Gift {

//! MysteryGift:0x00006500 vf10
bool Frame_Instruction::vf10() {
    f_MysteryGift_0000B168(field_30, 3);
    f_MysteryGift_0000C4BC(field_30, 1);
    f_MysteryGift_00009CC8(field_3C, 2);
    f_MysteryGift_0000D8E4(field_40);
    return true;
}

}  // namespace Gift
}  // namespace NetApp
