#ifndef GFL2_RENDERINGENGINE_SCENEGRAPH_DAGNODE_H
#define GFL2_RENDERINGENGINE_SCENEGRAPH_DAGNODE_H

#include "gfl2/renderingengine/scenegraph/Node.h"

namespace gfl2 {
namespace renderingengine {
namespace scenegraph {

class DagNode : public ::gfl2::renderingengine::scenegraph::NodeTrait<DagNode, ::gfl2::renderingengine::scenegraph::Node> {
public:
    static ::gfl2::util::FnvHash GetTypeHash()
    {
        static ::gfl2::util::FnvHash hash(reinterpret_cast<const u8 *>("Node::DagNode"));
        return hash;
    }

    virtual ~DagNode();
    virtual void AddChild(::gfl2::renderingengine::scenegraph::DagNode*);  // slot 4, code.bin:0032DA3C
};

// a guess: some inline code of the game's headers asks for this class's place in the node
// hierarchy (a cast to it, most likely), which is why a file that includes this header
// builds the class's Inheritance in its static initializer. the name is ours.
inline const ::gfl2::renderingengine::scenegraph::Inheritance *DagNodeInheritance()
{
    return DagNode::GetInheritanceStatic();
}

}  // namespace scenegraph
}  // namespace renderingengine
}  // namespace gfl2

#endif
