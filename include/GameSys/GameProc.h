#ifndef GAMESYS_GAMEPROC_H
#define GAMESYS_GAMEPROC_H

#include "gfl2/proc/BaseProcess.h"
#include "gfl2/gfx/CtrDisplayNo.h"

#include "types.h"

namespace GameSys { class GameManager; }
namespace GameSys { class GameProcManager; }
namespace gfl2 { namespace proc { class Manager; } }

namespace GameSys {

class GameProc : public ::gfl2::proc::BaseProcess {
public:
    GameProc();  // code.bin:00407B14
    // inline: the processes' destructors have it inlined (e.g. JoinFestaBeacon:0000083C)
    virtual ~GameProc() {}
    virtual ::gfl2::proc::Result InitFunc(::gfl2::proc::Manager *pManager);  // slot 2, code.bin:00407B0C
    virtual ::gfl2::proc::Result UpdateFunc(::gfl2::proc::Manager *pManager);  // slot 3, code.bin:00407ADC
    virtual void PreDrawFunc(::gfl2::proc::Manager *pManager);  // slot 4, code.bin:00407AE4
    virtual void DrawFunc(::gfl2::proc::Manager *pManager, ::gfl2::gfx::CtrDisplayNo displayNo);  // slot 5, code.bin:00407B08
    virtual ::gfl2::proc::Result EndFunc(::gfl2::proc::Manager *pManager);  // slot 6, code.bin:00407B00
    // slot 7, code.bin:004C12D8: const (its name sorts among the _ZNK ones); the name is not known,
    // the return type is a guess from its code (it returns true)
    virtual bool GameProc_vf7() const;
    // slot 8, code.bin:00407AF8. KNOWN WRONG, left so for now: it returns a value (0 here and in
    // FieldRo:00083090; ::gfl2::proc::Result is the likely type), but the generated headers of the
    // processes declare their overrides void, and a different return type here stops them compiling
    virtual void NextFrameMainFunc(::gfl2::proc::Manager *pManager);
    virtual void EventCheckFunc(::GameSys::GameManager *pGameManager);  // slot 9, code.bin:00407AE8

    // code.bin:00407AEC: returns field_1C's GameManager (the member at +0x14 of what field_1C points to)
    ::GameSys::GameManager *GetGameManager();

    // data members (offsets checked)
    // +0x1c: a guess: the GameProcManager that runs the process (a gfl2::proc::Manager, 0x14 bytes,
    // with the GameManager right after: GetGameManager reads +0x14 of it)
    ::GameSys::GameProcManager *field_1C;
};

}  // namespace GameSys

#endif
