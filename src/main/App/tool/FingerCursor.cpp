#include "app/tool/FingerCursor.h"

#include "types.h"

extern "C" u32 data_005BE3E8[];

namespace app {
namespace tool {

// the handle at +0x60 is the G2DUtil object the animation is on (field_60 is a guess: a u32 here);
// the call is a tail call to its IsAnimeEnd, with the handle as this.
//! 0x002F2AD0 IsEndPushAnime
bool FingerCursor::IsEndPushAnime(FormType t) {
    return ((::app::util::G2DUtil *)field_60)->IsAnimeEnd(0, data_005BE3E8[2 * t + 1]);
}

}  // namespace tool
}  // namespace app
