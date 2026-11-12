#include "GameSys/GameProc.h"

namespace GameSys {

//! 0x00407B14 _ZN7GameSys8GameProcC1Ev
GameProc::GameProc()
    : field_1C(0)
{
}

//! 0x00407B0C InitFunc
::gfl2::proc::Result GameProc::InitFunc(::gfl2::proc::Manager *pManager)
{
    return ::gfl2::proc::RES_FINISH;
}

//! 0x00407ADC UpdateFunc
::gfl2::proc::Result GameProc::UpdateFunc(::gfl2::proc::Manager *pManager)
{
    return ::gfl2::proc::RES_CONTINUE;
}

//! 0x00407AE4 PreDrawFunc
void GameProc::PreDrawFunc(::gfl2::proc::Manager *pManager)
{
}

//! 0x00407B08 DrawFunc
void GameProc::DrawFunc(::gfl2::proc::Manager *pManager, ::gfl2::gfx::CtrDisplayNo displayNo)
{
}

//! 0x00407B00 EndFunc
::gfl2::proc::Result GameProc::EndFunc(::gfl2::proc::Manager *pManager)
{
    return ::gfl2::proc::RES_FINISH;
}

//! 0x004C12D8 GameProc_vf7
bool GameProc::GameProc_vf7() const
{
    return true;
}

// NextFrameMainFunc (0x00407AF8, returns 0) is not here: GameProc.h declares it void for now
// (see there); src/main/generated/tiny_005.cpp has it

//! 0x00407AE8 EventCheckFunc
void GameProc::EventCheckFunc(::GameSys::GameManager *pGameManager)
{
}

}  // namespace GameSys

// ~GameProc is inline (GameProc.h); its out-of-line copies are emitted here with the vtable,
// and so are BaseProcess's (its destructor, PreDrawFunc and DrawFunc are inline in its header)
//! 0x00407B7C _ZN7GameSys8GameProcD1Ev
//! 0x00407B44 _ZN7GameSys8GameProcD0Ev
//! 0x00363D48 _ZN4gfl24proc11BaseProcessD1Ev
//! 0x00363D10 _ZN4gfl24proc11BaseProcessD0Ev
//! 0x00363C98 _ZN4gfl24proc11BaseProcess11PreDrawFunc
//! 0x00363D0C _ZN4gfl24proc11BaseProcess8DrawFunc
