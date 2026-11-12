#include "GameSys/DeviceDate.h"

namespace GameSys {

// open: the game's function stores the vtable, calls the base Date's
// destructor on the subobject at +8 (this + 8) and then deletes this - 8.
// The header has no base at +8 (only INijiDate), so the empty destructor
// compiles to a branch to itself. Needs the real base layout before a
// retry; not matched.

//! GameClearSave:0x0000149C D0Ev
DeviceDate::~DeviceDate()
{
}

}  // namespace GameSys
