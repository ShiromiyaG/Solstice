#ifndef FIELD_FIELDTRANSFORMNODE_H
#define FIELD_FIELDTRANSFORMNODE_H

#include "gfl2/renderingengine/scenegraph/instance/TransformNode.h"

namespace Field {

class FieldTransformNode : public ::gfl2::renderingengine::scenegraph::NodeTrait<FieldTransformNode, ::gfl2::renderingengine::scenegraph::instance::TransformNode> {
public:
    static ::gfl2::util::FnvHash GetTypeHash()
    {
        return ::gfl2::util::FnvHash(reinterpret_cast<const u8 *>("Node::DagNode::InstanceNode::TransformNode::FieldTransformNode"));
    }
};

// a guess: some inline code of the game's headers asks for this class's place in the node
// hierarchy (a cast to it, most likely), which is why a file that includes this header
// builds the class's Inheritance in its static initializer. the name is ours.
inline const ::gfl2::renderingengine::scenegraph::Inheritance *FieldTransformNodeInheritance()
{
    return FieldTransformNode::GetInheritanceStatic();
}

}  // namespace Field

#endif
