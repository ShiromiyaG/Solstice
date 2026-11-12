#ifndef FIELD_FIELDNODE_H
#define FIELD_FIELDNODE_H

#include "gfl2/renderingengine/scenegraph/instance/InstanceNode.h"

namespace Field {

class FieldNode : public ::gfl2::renderingengine::scenegraph::NodeTrait<FieldNode, ::gfl2::renderingengine::scenegraph::instance::InstanceNode> {
public:
    static ::gfl2::util::FnvHash GetTypeHash()
    {
        return ::gfl2::util::FnvHash(reinterpret_cast<const u8 *>("Node::DagNode::InstanceNode::FieldNode"));
    }
};

// a guess: some inline code of the game's headers asks for this class's place in the node
// hierarchy (a cast to it, most likely), which is why a file that includes this header
// builds the class's Inheritance in its static initializer. the name is ours.
inline const ::gfl2::renderingengine::scenegraph::Inheritance *FieldNodeInheritance()
{
    return FieldNode::GetInheritanceStatic();
}

}  // namespace Field

#endif
