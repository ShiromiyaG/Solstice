#include "Savedata/Misc.h"

// open: the code is right, but the table has this function 60 bytes long. the 44 bytes after
// it are another function that Ghidra joined to this one (it starts at 0x00459228): once that
// start is in config/us-v1.2/extra_starts.txt this one can be checked whole.
// the fields at +0x4, +0x8 and +0xc are guesses in include/Savedata/Misc.h.
//! 0x00459218 SetKawaigariTutorial
void Savedata::Misc::SetKawaigariTutorial()
{
    flags_0c |= 0x80000;
}
