#include "GameSys/GameEvent.h"

namespace GameSys {

//! 0x00408654 _ZN7GameSys9GameEventC2EPN4gfl24heap11CtrHeapBaseE
GameEvent::GameEvent(::gfl2::heap::CtrHeapBase *pHeap)
    : field_4(0), field_8(0), field_C(pHeap), field_10(0), field_14(0)
{
}

//! 0x00408684 _ZN7GameSys9GameEventD2Ev
//! 0x0040867C _ZN7GameSys9GameEventD0Ev
GameEvent::~GameEvent()
{
}

//! 0x0040864C vf6
bool GameEvent::vf6()
{
    return true;
}

}  // namespace GameSys
