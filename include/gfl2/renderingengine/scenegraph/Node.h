#ifndef GFL2_RENDERINGENGINE_SCENEGRAPH_NODE_H
#define GFL2_RENDERINGENGINE_SCENEGRAPH_NODE_H

#include "gfl2/gfx/GLMemory.h"
#include "gfl2/renderingengine/scenegraph/NodeTrait.h"

namespace gfl2 {
namespace renderingengine {
namespace scenegraph {

// the root node class. bases and their order: the game's type information (NodeTrait at +8)
class Node : public ::gfl2::gfx::GLMemory, public NodeTrait<Node, NullType> {
public:
    virtual void vf0();  // overrides  // slot 0, code.bin:0032D900
    virtual void vf1();  // overrides  // slot 1, code.bin:0032D888
    virtual void IsTransformType() const;  // slot 2, code.bin:004B1BEC
};

}  // namespace scenegraph
}  // namespace renderingengine
}  // namespace gfl2

#endif
