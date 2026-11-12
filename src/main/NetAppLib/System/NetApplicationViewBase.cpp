#include "NetAppLib/System/NetApplicationViewBase.h"

namespace NetAppLib {
namespace System {

//! 0x0047E1B4 _ZN9NetAppLib6System22NetApplicationViewBaseD1Ev
//! 0x0047E17C _ZN9NetAppLib6System22NetApplicationViewBaseD0Ev
NetApplicationViewBase::~NetApplicationViewBase()
{
    Delete2D();
    DeleteGraphicsSystem();
}

}  // namespace System
}  // namespace NetAppLib
