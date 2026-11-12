#ifndef NETAPPLIB_SYSTEM_NETAPPFRAMEBASE_H
#define NETAPPLIB_SYSTEM_NETAPPFRAMEBASE_H

#include "applib/frame/CellSuper.h"
#include "gfl2/gfx/CtrDisplayNo.h"

#include "types.h"

namespace NetAppLib { namespace System { class ApplicationWorkBase; } }

namespace NetAppLib {
namespace System {

// the base of the network applications' frames (about 80 classes). its own steps:
// InitFunc: sets up gflnet2's ServerClientRequestManager with the work's heap, waits for vf10,
// fades in (if field_1C and not field_20), then calls vf12. UpdateFunc: vf14 each frame, vf15 /
// vf16 when the WLAN switch turns on / off, then the result from the work's next frame.
// EndFunc: vf13 first, waits for vf11. the names of slots 6-8 and 10-16 are not known; the
// parameters and return types of the slots stay as tools/headers.py writes them for the
// overrides (see each line).
class NetAppFrameBase : public ::applib::frame::CellSuper {
public:
    NetAppFrameBase(::NetAppLib::System::ApplicationWorkBase*);  // code.bin:0047BC58
    virtual ~NetAppFrameBase();
    virtual s32 InitFunc();  // overrides  // slot 2, code.bin:0047BB2C; returns 0 or 2
    // returns 0 or 2 in the game (see CellSuper::UpdateFunc): void until returns.csv has it
    virtual s32 UpdateFunc();  // overrides  // slot 3, code.bin:0047B754; returns 0 or 2
    virtual void DrawFunc(::gfl2::gfx::CtrDisplayNo);  // overrides  // slot 4, code.bin:0047BB28 (empty)
    virtual s32 EndFunc();  // overrides  // slot 5, code.bin:0047B8EC
    virtual void CellSuper_vf6();  // overrides  // slot 6, code.bin:00401A1C (CellSuper's inline one, returns 0)
    virtual void vf7();  // slot 7, code.bin:0047BC2C (empty)
    virtual void vf8();  // slot 8, code.bin:0047BC28 (empty)
    // ends the frame: vf13, then the work's field_20 (the result UpdateFunc reads back) = the argument
    virtual void exitFrame(int);  // slot 9, code.bin:0047BC30
    // InitFunc's sequence 1 waits until it is true (loading done: a guess)
    virtual bool vf10();  // slot 10, code.bin:0047BB20 (returns true)
    // EndFunc waits until it is true (a guess: unloading done)
    virtual bool vf11();  // slot 11, code.bin:0047BB18 (returns true)
    virtual void vf12();  // slot 12, code.bin:0047B8D8; called by InitFunc as it ends
    virtual void vf13();  // slot 13, code.bin:0047B8DC; called first by EndFunc and by exitFrame
    // called by UpdateFunc every frame with no argument (code.bin:0047B754 sets no r1-r3): it takes
    // none. the three are tools/slotargs.py's guess, kept until the generated overrides change too
    virtual void vf14();  // slot 14, code.bin:0047B8E0; no arguments: UpdateFunc calls it with this only
    virtual void vf15();  // slot 15, code.bin:0047B8E4; UpdateFunc: the WLAN switch turned on
    virtual void vf16();  // slot 16, code.bin:0047B8E8; UpdateFunc: the WLAN switch turned off

    // member functions the game names. static or not is not in a name, nor is the return type
    // (void until config/<version>/returns.csv has it)
    bool UpdateSave();  // code.bin:0047B7F4; the return type is a guess from its callers: only tested, and it returns only 0 and 1

    // data members
    ::NetAppLib::System::ApplicationWorkBase *field_18;  // +0x18: the constructor's argument
    bool field_1C;  // +0x1c: InitFunc fades in only if set (a guess: bool, false from the constructor)
    bool field_1D;  // +0x1d: EndFunc tests it (a guess: bool, false from the constructor)
    bool field_1E;  // +0x1e: EndFunc tests and clears it (a guess: bool, false from the constructor)
    bool field_1F;  // +0x1f: the WLAN switch was off: !NijiNetworkSystem::IsWLANSwitchEnable() in the constructor, kept by UpdateFunc
    bool field_20;  // +0x20: InitFunc skips the fade if set (a guess: bool, false from the constructor)
    u8 unk_21[0x3];  // +0x21: padding; a second base of the derived classes is at +0x24
};

}  // namespace System
}  // namespace NetAppLib

#endif
