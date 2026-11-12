#include "NetApp/NBR/Frame/NBRTeamSelectWaitFrame.h"

// the two functions this one calls, not named yet (the packet's names)
void f_NBR_00007910(void *);
void f_NBR_00007358(void *, u32);

namespace NetApp {
namespace NBR {
namespace Frame {

// +0x68 is in the gap unk_64 of NBRFrameBase (no header field yet): read by offset, as in
// NBRRuleSelectWaitFrame::vf24. field_28 is a view: its +0x5c is the byte cleared here.
//! NBR:0x00005B70 _ZN6NetApp3NBR5Frame22NBRTeamSelectWaitFrame4vf21
void NBRTeamSelectWaitFrame::vf21() {
    f_NBR_00007910(*(void **)(unk_64 + 4));
    f_NBR_00007358(field_74, 0);
    ((u8 *)field_28)[0x5c] = 0;
    exitFrame(2);
}

}  // namespace Frame
}  // namespace NBR
}  // namespace NetApp
