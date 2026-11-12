#ifndef GFL2_RENDERINGENGINE_SCENEGRAPH_INSTANCE_TRANSFORMNODE_H
#define GFL2_RENDERINGENGINE_SCENEGRAPH_INSTANCE_TRANSFORMNODE_H

#include "gfl2/renderingengine/scenegraph/instance/InstanceNode.h"

namespace gfl2 {
namespace renderingengine {
namespace scenegraph {
namespace instance {

class TransformNode : public ::gfl2::renderingengine::scenegraph::NodeTrait<TransformNode, ::gfl2::renderingengine::scenegraph::instance::InstanceNode> {
public:
    static ::gfl2::util::FnvHash GetTypeHash()
    {
        static ::gfl2::util::FnvHash hash(reinterpret_cast<const u8 *>("Node::DagNode::InstanceNode::TransformNode"));
        return hash;
    }

    virtual ~TransformNode();
    virtual void AddChild(::gfl2::renderingengine::scenegraph::DagNode*);  // overrides  // slot 4, code.bin:003303A8
    virtual void vf5();  // slot 5, code.bin:00330380
};

// a guess: some inline code of the game's headers asks for this class's place in the node
// hierarchy (a cast to it, most likely), which is why a file that includes this header
// builds the class's Inheritance in its static initializer. the name is ours.
inline const ::gfl2::renderingengine::scenegraph::Inheritance *TransformNodeInheritance()
{
    return TransformNode::GetInheritanceStatic();
}

}  // namespace instance
}  // namespace scenegraph
}  // namespace renderingengine
}  // namespace gfl2

#endif
