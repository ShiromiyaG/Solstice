#include "NetAppLib/System/NetAppFrameBase.h"
#include "NetAppLib/System/ApplicationWorkBase.h"
#include "types.h"

// a static function of gflnet2::ServerClient::ServerClientRequestManager by its place in the
// name order (between GetHeapInternal and AddRequestSequenceInternal); its name is not known
void sub_00408B30();

namespace NetAppLib {
namespace System {

//! 0x0047BCC4 _ZN9NetAppLib6System15NetAppFrameBaseD1Ev
//! 0x0047BCA0 _ZN9NetAppLib6System15NetAppFrameBaseD0Ev
NetAppFrameBase::~NetAppFrameBase() {
    sub_00408B30();
}

//! 0x0047BC30 exitFrame
void NetAppFrameBase::exitFrame(int result) {
    vf13();
    field_18->field_20 = result;
}

}  // namespace System
}  // namespace NetAppLib
