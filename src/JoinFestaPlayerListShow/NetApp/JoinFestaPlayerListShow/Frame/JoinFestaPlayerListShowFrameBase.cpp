#include "NetApp/JoinFestaPlayerListShow/Frame/JoinFestaPlayerListShowFrameBase.h"

// the function right after this one (JoinFestaPlayerListShow:0x000029C8), called with field_2C
// as its last step: a tail call the linker turns into the mov r0, r0 the game has. Its name is
// not known yet.
void f_JoinFestaPlayerListShow_000029C8(void *);

namespace NetApp {
namespace JoinFestaPlayerListShow {
namespace Frame {

//! JoinFestaPlayerListShow:0x000029B0 _ZN6NetApp23JoinFestaPlayerListShow5Frame32JoinFestaPlayerListShowFrameBase9exitFrame
void JoinFestaPlayerListShowFrameBase::exitFrame(int a1) {
    ::NetAppLib::System::NetAppFrameBase::exitFrame(a1);
    f_JoinFestaPlayerListShow_000029C8(field_2C);
}

}  // namespace Frame
}  // namespace JoinFestaPlayerListShow
}  // namespace NetApp
