#include "NetApp/NBR/ApplicationSystem/NBRBuilder.h"
#include "gfl2/heap/CtrHeapBase.h"

// guesses: the layouts behind field_8 and field_4 (only the offsets used here).
struct NBRLevel2_00000840 {
    u8 unk_0[8];
    gfl2::heap::CtrHeapBase *heap;  // +8
};

struct NBRLevel1_00000840 {
    u8 unk_0[8];
    NBRLevel2_00000840 *child;  // +8
};

void *operator new(u32, gfl2::heap::CtrHeapBase *);
void *f_NBR_000009FC(void *, u32, u32, u32);

namespace NetApp {
namespace NBR {
namespace ApplicationSystem {

//! NBR:0x00000840 vf1
void *NBRBuilder::vf1()
{
    NBRLevel1_00000840 *l1 = (NBRLevel1_00000840 *)field_8;
    void *result = operator new(16, l1->child->heap);
    if (result) {
        return f_NBR_000009FC(result, 0, 0, 0);
    }
    return result;
}

}  // namespace ApplicationSystem
}  // namespace NBR
}  // namespace NetApp
