#include "types.h"
#include "version.h"
#include "System/Version.h"

// the version the program was built for: 32 in Ultra Sun, 33 in Ultra Moon
//! 0x003F6674 _ZN6System10GetVersionEv
u32 System::GetVersion()
{
    return GAME_VERSION;
}
