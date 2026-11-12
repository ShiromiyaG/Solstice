#include "NetApp/NBR/Frame/NBRRuleSelectWaitFrame.h"

// the two functions this one calls, not named yet (the packet's names)
void f_NBR_00007910(void *);
void f_NBR_00007358(void *, u32);

namespace NetApp {
namespace NBR {
namespace Frame {

// +0x68 is in the gap unk_64 of NBRFrameBase (no header field yet): read by offset.
// field_28 is a view: its +0x5c is the byte cleared here (NBRTeamSelectWaitFrame::vf21 does the same).
//! NBR:0x0000553C _ZN6NetApp3NBR5Frame22NBRRuleSelectWaitFrame4vf24
void NBRRuleSelectWaitFrame::vf24() {
    f_NBR_00007910(*(void **)(unk_64 + 4));
    f_NBR_00007358(field_74, 0);
    ((u8 *)field_28)[0x5c] = 0;
    exitFrame(2);
}

}  // namespace Frame
}  // namespace NBR
}  // namespace NetApp
