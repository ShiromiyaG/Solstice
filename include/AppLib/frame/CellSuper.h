#ifndef APPLIB_FRAME_CELLSUPER_H
#define APPLIB_FRAME_CELLSUPER_H

#include "gfl2/gfx/CtrDisplayNo.h"

#include "types.h"

namespace applib {
namespace frame {

// the base of every frame (a step of a screen) that applib::frame::Manager runs: InitFunc until
// it is done, then UpdateFunc / DrawFunc each frame, then EndFunc until it is done.
// the game never writes CellSuper's vtable (no constructor or destructor of its own is out of
// line): its constructor and destructor are inline, and its virtual functions are pure or
// inline (slot 6 is emitted beside each vtable that uses it: code.bin:00401A1C, Box:000276C4).
class CellSuper {
public:
    // inline: every derived constructor stores +0x4 and +0x8 before its own vtable
    // (NetAppFrameBase's at code.bin:0047BC58, btl::BattleUIActSelectFrame's at Battle:0004D358)
    CellSuper() : field_4(0), field_8(false) {}
    // inline and empty: NetAppFrameBase's destructor calls no base destructor
    virtual ~CellSuper() {}

    // the results Manager::Main tests (code.bin:00401678): 1 and 2 end the phase (a guess: the
    // real type is an enum of the frame library, its name unknown; 0 continues). the return
    // types are left as tools/headers.py writes them for the overrides (see UpdateFunc).
    virtual s32 InitFunc() = 0;  // slot 2; pure: a guess (every frame overrides it)
    // really returns the same result as InitFunc (Manager::Main tests r0 after slot 3, and
    // NetAppFrameBase::UpdateFunc returns 0 or 2): it stays void until config/us-v1.2/returns.csv
    // gives applib::frame::CellSuper#3 an s32, so the generated overrides agree with it
    virtual s32 UpdateFunc() = 0;  // slot 3; pure: a guess. s32: Manager::Main tests r0, and
                                   // NetAppFrameBase::UpdateFunc returns 0 or 2
    virtual void DrawFunc(::gfl2::gfx::CtrDisplayNo) = 0;  // slot 4; pure: a guess
    virtual s32 EndFunc() = 0;  // slot 5; pure: a guess
    // inline, `return 0` (bool or an integer: a guess) in the game: void here for the same reason
    // as UpdateFunc (the overrides are generated void); its name is not known
    virtual void CellSuper_vf6();  // slot 6

    // data members
    s32 field_4;  // +0x4: the phase's sub-sequence; Manager::Main sets it to 0 before each phase,
                  // NetAppFrameBase::InitFunc/EndFunc switch on it (a guess: int)
    bool field_8;  // +0x8: false from the constructor (a guess: bool; its use is not seen yet)
    u8 unk_9[0x3];  // +0x9: nothing seen to use it
    u8 unk_C[0x8];  // +0xc: nothing seen to use it
    u32 field_14;  // +0x14, a guess: from 2 functions (tools/fields.py, as NetAppFrameBase's)
};

}  // namespace frame
}  // namespace applib

#endif
