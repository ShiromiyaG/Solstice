#include "App/Finder/FinderFrame.h"

// the function this one tail-calls (Finder:0x00006400), not named yet (the packet's name)
void f_Finder_00006400(void *);

namespace App {
namespace Finder {

// the override of FinderDrawListener's slot 6 (through the base at +0x18): the compiler makes
// the thunk at -24 from it. The header does not declare it in FinderFrame yet.
//! Finder:0x00009124 _ZThn24_N3App6Finder11FinderFrame22FinderDrawListener_vf6
void FinderFrame::FinderDrawListener_vf6(u32 a1) {
    ((u8 *)field_54)[0x16] = a1;
    if (field_58) {
        f_Finder_00006400(field_58);
    }
}

}  // namespace Finder
}  // namespace App
