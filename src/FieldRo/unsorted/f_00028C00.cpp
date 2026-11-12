#include "types.h"

namespace gfl2 {
namespace renderingengine {
namespace scenegraph {
class DagNode {
public:
    void RemoveChild(DagNode *child);
};
}
}
}

extern "C" void f_FieldRo_00066994(u8 *, void *);

//! FieldRo:0x00028C00 f_FieldRo_00028C00
extern "C" void f_FieldRo_00028C00(u8 *self, gfl2::renderingengine::scenegraph::DagNode *arg)
{
    u8 *inner = self + 0x120;
    gfl2::renderingengine::scenegraph::DagNode *node = *(gfl2::renderingengine::scenegraph::DagNode **)(self + 0x1f4);
    if (node) {
        node->RemoveChild(arg);
    }
    f_FieldRo_00066994(inner + 0x38, arg);
}
