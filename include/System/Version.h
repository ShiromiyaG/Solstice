#ifndef SYSTEM_VERSION_H
#define SYSTEM_VERSION_H

#include "types.h"

// System::GetVersion() is exported by name (static.crs); whether System is a namespace or a
// class with a static member is not in the name, nor is the return type (a guess) or the file.
namespace System {
u32 GetVersion();
}

#endif
