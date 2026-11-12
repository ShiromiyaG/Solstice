#include "gfl2/str/StrBuf.h"

namespace print {

extern int sub_003D2A6C(int a1, void *a2, int a3, int a4);

//! 0x003D27F4 SetStringForLytTextBox
int SetStringForLytTextBox(int a1, gfl2::str::StrBuf const *a2, int a3)
{
    return sub_003D2A6C(a1, a2->GetPtr(), 0, a3);
}

}  // namespace print
