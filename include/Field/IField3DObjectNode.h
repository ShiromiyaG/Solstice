#ifndef FIELD_IFIELD3DOBJECTNODE_H
#define FIELD_IFIELD3DOBJECTNODE_H

#include "Field/FieldNode.h"

namespace Field {

class IField3DObjectNode : public ::gfl2::renderingengine::scenegraph::NodeTrait<IField3DObjectNode, ::Field::FieldNode> {
public:
    static ::gfl2::util::FnvHash GetTypeHash()
    {
        return ::gfl2::util::FnvHash(reinterpret_cast<const u8 *>("Node::DagNode::InstanceNode::FieldNode::Field3DObjectNode"));
    }
};

// a guess: some inline code of the game's headers asks for this class's place in the node
// hierarchy (a cast to it, most likely), which is why a file that includes this header
// builds the class's Inheritance in its static initializer. the name is ours.
inline const ::gfl2::renderingengine::scenegraph::Inheritance *IField3DObjectNodeInheritance()
{
    return IField3DObjectNode::GetInheritanceStatic();
}

}  // namespace Field

#endif
