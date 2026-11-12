#ifndef GFL2_PROC_BASEPROCESS_H
#define GFL2_PROC_BASEPROCESS_H

#include "gfl2/gfx/CtrDisplayNo.h"

#include "types.h"

namespace gfl2 { namespace proc { class Manager; } }
namespace nn { namespace ro { class Module; } }
namespace gfl2 { namespace heap { void GflHeapFreeMemoryBlock(void *p); } }  // its header is not written yet

namespace gfl2 {
namespace proc {

// what InitFunc, UpdateFunc and EndFunc return. gfl2::proc::Manager (code.bin:00364144) moves a
// process on when one returns 1, and keeps calling it otherwise. the names of the type and of
// its values are guesses
enum Result {
    RES_CONTINUE = 0,
    RES_FINISH = 1
};

class BaseProcess {
public:
    // inline: every program has its own copies of what it uses, and GameSys::GameProc's
    // constructor and destructor have them inlined (code.bin:00407B14, 00407B44)
    BaseProcess()
        : field_4(0), field_8(0), field_C(0), field_10(0), field_14(0), field_18(0)
    {
    }
    // inline, as the game has it (the owner, 2026-11-12): the derived classes' destructors have
    // its body in them (GameProc's at code.bin:00407B44/00407B7C), and every program has its own
    // copies of it, of PreDrawFunc and of DrawFunc, emitted with the vtable by a file of a class
    // built on this one (src/main/GameSys/GameProc.cpp in code.bin; tools/structors.py elsewhere)
    virtual ~BaseProcess()
    {
        if (field_14) {
            ::gfl2::heap::GflHeapFreeMemoryBlock((void *)field_14);
            field_14 = 0;
        }
    }
    virtual Result InitFunc(::gfl2::proc::Manager *pManager) = 0;    // slot 2
    virtual Result UpdateFunc(::gfl2::proc::Manager *pManager) = 0;  // slot 3
    virtual void PreDrawFunc(::gfl2::proc::Manager *pManager) {}     // slot 4
    virtual void DrawFunc(::gfl2::proc::Manager *pManager, ::gfl2::gfx::CtrDisplayNo displayNo) {}  // slot 5
    virtual Result EndFunc(::gfl2::proc::Manager *pManager) = 0;     // slot 6

    // data members (offsets checked; names are the tool's, types from the code)
    u32 field_4;  // +0x4: the process's sequence (InitFunc and the others switch on it; Manager sets it to 0 when a step ends)
    u8 field_8;  // +0x8, a guess: from 9 functions
    u8 unk_9[0x3];  // +0x9: nothing seen to use it
    u32 field_C;  // +0xc, a guess: from 4 functions
    ::nn::ro::Module *field_10;  // +0x10: the process's module; Manager disposes of it after deleting the process (code.bin:00363E14)
    ::nn::ro::Module **field_14;  // +0x14: the modules it depends on, field_18 of them (a block of the heap, freed by the destructor; Manager disposes of each)
    u32 field_18;  // +0x18: how many entries field_14 has (at most 16, code.bin:00363E14)
};

}  // namespace proc
}  // namespace gfl2

#endif
