#include "types.h"
#include "version.h"

// the version again, in Field::FieldScript's part of the executable (config/us-v1.2/bounds.csv):
// a function of its own, not a call to System::GetVersion. name and return type unknown
//! 0x003801B8 sub_003801B8
u32 sub_003801B8()
{
    return GAME_VERSION;
}
