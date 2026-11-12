#include "types.h"
#include "NetApp/GameSync/Frame/GameSyncFrameBase.h"

// the function after this one, reached by a tail call (not named yet)
extern "C" void sub_00003B38(void *);

//! GameSync:0x00003B24 _ZN6NetApp8GameSync5Frame17GameSyncFrameBase9exitFrame
void NetApp::GameSync::Frame::GameSyncFrameBase::exitFrame(int a1) {
    NetAppLib::System::NetAppFrameBase::exitFrame(a1);
    sub_00003B38(field_2C);
}
