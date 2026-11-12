#include "Field/EventRizaadonRide.h"
#include "GameSys/GameManager.h"

#include "types.h"

// gfl2::heap::Manager::GetHeapByHeapId, a static function of the gfl2 library, named by its address
void *sub_00107374(u32 heapId);

namespace Field {

// the game manager's +0x24 is a pointer whose +0xcc holds a pointer with the values this stores
// (GameManager has no such member yet: the offsets are as the code reads them, untyped)

//! 0x0039D9CC _ZN5Field17EventRizaadonRide3vf3
void EventRizaadonRide::vf3(::GameSys::GameManager *pGameManager) {
    field_58 = (u32)sub_00107374(11);
    field_54 = (u32)pGameManager;
    u32 *pObj = *(u32 **)((u8 *)pGameManager + 0x24);
    field_4C = pObj[0xcc / 4];
    field_50 = ((u32 *)field_4C)[0xc / 4];
}

}  // namespace Field
