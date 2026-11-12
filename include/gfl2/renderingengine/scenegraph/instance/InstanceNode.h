#ifndef GFL2_RENDERINGENGINE_SCENEGRAPH_INSTANCE_INSTANCENODE_H
#define GFL2_RENDERINGENGINE_SCENEGRAPH_INSTANCE_INSTANCENODE_H

#include "gfl2/renderingengine/scenegraph/DagNode.h"

namespace gfl2 {
namespace renderingengine {
namespace scenegraph {
namespace instance {

class InstanceNode : public ::gfl2::renderingengine::scenegraph::NodeTrait<InstanceNode, ::gfl2::renderingengine::scenegraph::DagNode> {
public:
    static ::gfl2::util::FnvHash GetTypeHash()
    {
        return ::gfl2::util::FnvHash(reinterpret_cast<const u8 *>("Node::DagNode::InstanceNode"));
    }

    virtual ~InstanceNode();
};

// a guess: some inline code of the game's headers asks for this class's place in the node
// hierarchy (a cast to it, most likely), which is why a file that includes this header
// builds the class's Inheritance in its static initializer. the name is ours.
inline const ::gfl2::renderingengine::scenegraph::Inheritance *InstanceNodeInheritance()
{
    return InstanceNode::GetInheritanceStatic();
}

}  // namespace instance
}  // namespace scenegraph
}  // namespace renderingengine
}  // namespace gfl2

#endif
