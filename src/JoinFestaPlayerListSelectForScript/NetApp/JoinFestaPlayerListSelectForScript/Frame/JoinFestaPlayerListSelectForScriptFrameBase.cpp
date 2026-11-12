#include "NetApp/JoinFestaPlayerListSelectForScript/Frame/JoinFestaPlayerListSelectForScriptFrameBase.h"

void f_JoinFestaPlayerListSelectForScript_000033E4(void *);

namespace NetApp {
namespace JoinFestaPlayerListSelectForScript {
namespace Frame {

//! JoinFestaPlayerListSelectForScript:0x000033CC exitFrame
void JoinFestaPlayerListSelectForScriptFrameBase::exitFrame(int a1) {
    ::NetAppLib::System::NetAppFrameBase::exitFrame(a1);
    // the game's next function, reached by a tail call the linker made a mov r0, r0
    f_JoinFestaPlayerListSelectForScript_000033E4(field_2C);
}

}  // namespace Frame
}  // namespace JoinFestaPlayerListSelectForScript
}  // namespace NetApp
