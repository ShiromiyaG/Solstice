#include "NetAppLib/Util/NetAppPokeModelUtility.h"
#include "types.h"

namespace NetAppLib {
namespace Util {

// open: the vtable store is the compiler's. The body calls a function with four zero arguments
// (r0..r3 = 0), which the linker removed (a mov r0, r0 at 0x00479720). Its callee is not known yet.
//! 0x004796F4 ~ModelEnvironment
NetAppPokeModelUtility::ModelEnvironment::~ModelEnvironment() {
}

}  // namespace Util
}  // namespace NetAppLib
