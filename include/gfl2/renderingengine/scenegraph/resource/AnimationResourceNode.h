#ifndef GFL2_RENDERINGENGINE_SCENEGRAPH_RESOURCE_ANIMATIONRESOURCENODE_H
#define GFL2_RENDERINGENGINE_SCENEGRAPH_RESOURCE_ANIMATIONRESOURCENODE_H

#include "gfl2/renderingengine/scenegraph/resource/ResourceNode.h"

namespace gfl2 {
namespace renderingengine {
namespace scenegraph {
namespace resource {

class AnimationResourceNode : public ::gfl2::renderingengine::scenegraph::NodeTrait<AnimationResourceNode, ::gfl2::renderingengine::scenegraph::resource::ResourceNode> {
public:
    static ::gfl2::util::FnvHash GetTypeHash()
    {
        static ::gfl2::util::FnvHash hash(reinterpret_cast<const u8 *>("Node::DagNode::ResourceNode::AnimationResourceNode"));
        return hash;
    }

    virtual ~AnimationResourceNode();
};

// a guess: some inline code of the game's headers asks for this class's place in the node
// hierarchy (a cast to it, most likely), which is why a file that includes this header
// builds the class's Inheritance in its static initializer. the name is ours.
inline const ::gfl2::renderingengine::scenegraph::Inheritance *AnimationResourceNodeInheritance()
{
    return AnimationResourceNode::GetInheritanceStatic();
}

}  // namespace resource
}  // namespace scenegraph
}  // namespace renderingengine
}  // namespace gfl2

#endif
