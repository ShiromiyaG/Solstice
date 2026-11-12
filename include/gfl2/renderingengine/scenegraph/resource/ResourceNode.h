#ifndef GFL2_RENDERINGENGINE_SCENEGRAPH_RESOURCE_RESOURCENODE_H
#define GFL2_RENDERINGENGINE_SCENEGRAPH_RESOURCE_RESOURCENODE_H

#include "gfl2/renderingengine/scenegraph/DagNode.h"

namespace gfl2 {
namespace renderingengine {
namespace scenegraph {
namespace resource {

class ResourceNode : public ::gfl2::renderingengine::scenegraph::NodeTrait<ResourceNode, ::gfl2::renderingengine::scenegraph::DagNode> {
public:
    static ::gfl2::util::FnvHash GetTypeHash()
    {
        static ::gfl2::util::FnvHash hash(reinterpret_cast<const u8 *>("Node::DagNode::ResourceNode"));
        return hash;
    }

    virtual ~ResourceNode();
    virtual void vf5();  // slot 5, code.bin:004B1F58
};

// a guess: some inline code of the game's headers asks for this class's place in the node
// hierarchy (a cast to it, most likely), which is why a file that includes this header
// builds the class's Inheritance in its static initializer. the name is ours.
inline const ::gfl2::renderingengine::scenegraph::Inheritance *ResourceNodeInheritance()
{
    return ResourceNode::GetInheritanceStatic();
}

}  // namespace resource
}  // namespace scenegraph
}  // namespace renderingengine
}  // namespace gfl2

#endif
