#include "NetApp/TeamSelect/TeamSelectTopSeqSelectFrame.h"
#include "types.h"

namespace NetApp {
namespace TeamSelect {

// the module's function at 0x00005C90 (a guess of its argument: a pointer)
void f_TeamSelect_00005C90(void *);

//! TeamSelect:0x00002F3C EndFunc
s32 TeamSelectTopSeqSelectFrame::EndFunc() {
    void *a = ((void **)field_18)[1];
    void *b = ((void **)a)[1];
    f_TeamSelect_00005C90(b);
    return 2;
}

}  // namespace TeamSelect
}  // namespace NetApp
