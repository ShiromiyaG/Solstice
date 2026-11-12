#include "Field/FieldProc.h"
#include "types.h"

namespace Field {

// the callee at 0x000897D8 of this module (a guess of its arguments: a pointer and a pointer)
void f_FieldRo_000897D8(void *, void *);

//! FieldRo:0x00083128 FieldProc8InitFunc
::gfl2::proc::Result FieldProc::InitFunc(::gfl2::proc::Manager *) {
    u8 *a = (u8 *)GetGameManager();
    u8 *b = (u8 *)GetGameManager();
    u8 *c = *(u8 **)(b + 0x30);
    f_FieldRo_000897D8(*(void **)(c + 0x90), *(void **)(a + 0x5c));
    return ::gfl2::proc::RES_FINISH;
}

}  // namespace Field
