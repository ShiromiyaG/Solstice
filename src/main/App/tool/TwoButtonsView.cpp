#include "app/tool/TwoButtonsView.h"

namespace gfl2 { namespace heap { void GflHeapFreeMemoryBlock(void *p); } }

namespace app {
namespace tool {

// the complete (D1) and base (D2) destructors of the base class: one definition, two copies in
// the game (0x002F7D44 stores the base's vtable, 0x648AB4). the packet's DefaultResourceLoader
// label for 0x002F7D44 is wrong: it is this class's own destructor, not the derived one.
//! 0x002F7D44 ResourceLoaderBaseD1Ev
//! 0x002F7AD4 ResourceLoaderBaseD2Ev
TwoButtonsView::ResourceLoaderBase::~ResourceLoaderBase() {
    gfl2::heap::GflHeapFreeMemoryBlock((void *)field_8);
}

}  // namespace tool
}  // namespace app
