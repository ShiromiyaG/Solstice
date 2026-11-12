#include "StaticActor.h"

// the deleting destructor: the complete one (FieldRo:0x00074BF0) is called, then the
// object is freed by the compiler's delete. the rest of the game's body (a load through
// the base's field at +4 and a virtual call at slot 4) is not explained yet.
//! FieldRo:0x00002760 _ZN11StaticActorD0Ev
StaticActor::~StaticActor() {
}
