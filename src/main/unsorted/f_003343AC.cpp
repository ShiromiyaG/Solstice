#include "types.h"
#include "gfl2/renderingengine/scenegraph/instance/LocatorInstanceNode.h"

// callees without names: sub_0032E324 returns a pointer, sub_003305F0 is the tail call
void *sub_0032E324(void *p);
void sub_003305F0(void *p);

//! 0x003343AC vf0
void gfl2::renderingengine::scenegraph::instance::LocatorInstanceNode::vf0() {
    void *v1 = sub_0032E324((u8 *)this + 0x7c);
    return sub_003305F0((u8 *)v1 - 0x7c);
}
