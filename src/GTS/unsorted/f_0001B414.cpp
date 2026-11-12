#include "types.h"

// open, not attempted: a deleting destructor of a secondary base (this - 8,
// `mov r0, r0` = an empty base destructor call, then operator delete). It needs
// the class's virtual destructor and its second base at +8, which the generated
// header does not have. GTSStartStateConfirmRequestSequence.h, not edited.
// NetApp::GTS::RequestSequence::GTSStartStateConfirmRequestSequence, slot -8:1.
