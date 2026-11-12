#include "NetEvent/JoinFestaPlayerDetail/JoinFestaPlayerDetailEvent.h"
#include "GameSys/GameManager.h"

// callee without a name: its result is compared with 0, its arguments are guesses
u32 sub_004B95D4(u32 a1, u32 a2);

namespace NetEvent {
namespace JoinFestaPlayerDetail {

// GameManager's +0x14 is not in its header (unk_0 covers it): read as a u32 here. the header
// needs a field there, reported

//! 0x0043A61C _ZN8NetEvent21JoinFestaPlayerDetail26JoinFestaPlayerDetailEvent3vf4
::GameSys::GameEventResult JoinFestaPlayerDetailEvent::vf4(::GameSys::GameManager *pGameManager) {
    ::GameSys::GameEventResult result = ::GameSys::GAMEEVENT_RES_CONTINUE;
    if (sub_004B95D4(*(u32 *)((u8 *)pGameManager + 0x14), field_2F0) == 0) {
        result = ::GameSys::GAMEEVENT_RES_FINISH;
    }
    return result;
}

}  // namespace JoinFestaPlayerDetail
}  // namespace NetEvent
