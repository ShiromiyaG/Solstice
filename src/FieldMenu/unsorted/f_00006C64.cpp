#include "types.h"
#include "version.h"

// app::util::FileAccessor::IsFileOpen(unsigned int) is exported by name; a namespace or a
// class with a static member is not in the name, and the return type is a guess
namespace app {
namespace util {
namespace FileAccessor {
bool IsFileOpen(u32 arcId);
}
}
}

// whether an archive whose number depends on the version is open: 101 in Ultra Sun, 102 in
// Ultra Moon. the archive's name is not known
//! FieldMenu:0x00006C64 f_FieldMenu_00006C64
bool f_FieldMenu_00006C64()
{
#if GAME_VERSION == VERSION_ULTRA_SUN
    return app::util::FileAccessor::IsFileOpen(101);
#else
    return app::util::FileAccessor::IsFileOpen(102);
#endif
}
