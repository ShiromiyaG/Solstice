#include "NetApp/GTS/Window/GTSMessageWindowLowerView.h"

namespace NetApp {
namespace GTS {
namespace Window {

// the class's complete destructor (GTS:0x00018510) is the body; the secondary thunk at
// GTS:0x0001A658 (_ZThn164_) is not emitted by the compiler for this file (the vtable is,
// the thunk symbol is not). Tried: the thunk's symbol as the --sym (not found).
// The check of the body says RESULT MATCH? : the branch to the base destructor is unverified
// (the base's destructor at GTS:0x00012C24 has no mangled name in symbols.txt).

//! GTS:0x0001A658 _ZThn164_N6NetApp3GTS6Window25GTSMessageWindowLowerViewD1Ev
GTSMessageWindowLowerView::~GTSMessageWindowLowerView() {
}

}  // namespace Window
}  // namespace GTS
}  // namespace NetApp
