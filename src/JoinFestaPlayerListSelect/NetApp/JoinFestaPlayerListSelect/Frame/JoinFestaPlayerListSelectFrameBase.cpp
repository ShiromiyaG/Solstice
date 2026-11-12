#include "types.h"
#include "NetApp/JoinFestaPlayerListSelect/Frame/JoinFestaPlayerListSelectFrameBase.h"
#include "NetAppLib/System/NetAppFrameBase.h"

// the function after exitFrame (JoinFestaPlayerListSelect:0x1B2C, unnamed) is called with field_2C
// as its only argument; the call at its end is a tail call, which the linker made a mov r0, r0.
// its signature is a guess from this call.
void f_JoinFestaPlayerListSelect_00001B2C(void *);

//! JoinFestaPlayerListSelect:0x00001B14 exitFrame
void NetApp::JoinFestaPlayerListSelect::Frame::JoinFestaPlayerListSelectFrameBase::exitFrame(int a1)
{
    NetAppLib::System::NetAppFrameBase::exitFrame(a1);
    f_JoinFestaPlayerListSelect_00001B2C(field_2C);
}
