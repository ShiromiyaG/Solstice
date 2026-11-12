#include "types.h"
#include "version.h"

// two neighbours that ask which version this is; names unknown, return types guesses
//! SequencePlayer:0x00005D80 f_SequencePlayer_00005D80
bool f_SequencePlayer_00005D80()
{
    return GAME_VERSION == VERSION_ULTRA_SUN;
}

//! SequencePlayer:0x00005D88 f_SequencePlayer_00005D88
bool f_SequencePlayer_00005D88()
{
    return GAME_VERSION == VERSION_ULTRA_MOON;
}
