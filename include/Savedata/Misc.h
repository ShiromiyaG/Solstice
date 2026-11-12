#ifndef SAVEDATA_MISC_H
#define SAVEDATA_MISC_H

#include "Savedata/SaveDataInterface.h"
#include "types.h"

namespace Savedata {

class Misc : public ::Savedata::SaveDataInterface {
public:
    virtual void vf0();  // slot 0, code.bin:00459540
    virtual void vf1();  // slot 1, code.bin:0045953C
    virtual void vf2();  // slot 2, code.bin:00459404
    virtual void vf3();  // slot 3, code.bin:00458F64
    virtual void vf4();  // slot 4, code.bin:00459298
    virtual void vf5();  // slot 5, code.bin:0045940C
    void SetKawaigariTutorial();  // code.bin:00459218
    u32 field_04;  // +0x4, guess: unknown
    u32 field_08;  // +0x8, guess: unknown
    u32 flags_0c;  // +0xc, guess: a flag word, the tutorial bit is 0x80000
};

}  // namespace Savedata

#endif
