#include "NetApp/RegulationSelect/Frame/RegulationDLLoadFrame.h"

// the call after the store is removed by the linker: its callee takes field_90 in r0
void f_RegulationSelect_00006098(void *);

namespace NetApp {
namespace RegulationSelect {
namespace Frame {

//! RegulationSelect:0x00006080 vf13
void RegulationDLLoadFrame::vf13() {
    // guess: field_90 points to an object whose +0x10 is a pointer to one with a u32 at +0xb0
    u8 *inner = *(u8 **)((u8 *)field_90 + 0x10);
    *(u32 *)(inner + 0xb0) = 0;
    f_RegulationSelect_00006098(field_90);
}

}  // namespace Frame
}  // namespace RegulationSelect
}  // namespace NetApp
