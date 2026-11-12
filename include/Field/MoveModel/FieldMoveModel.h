#ifndef FIELD_MOVEMODEL_FIELDMOVEMODEL_H
#define FIELD_MOVEMODEL_FIELDMOVEMODEL_H

#include "Field/IField3DObjectNode.h"

namespace Field {
namespace MoveModel {

// its virtual functions are not written yet: config/us-v1.2/vtables.csv has them by slot
// its type name is its base's, letter for letter: that is what the game hashes
class FieldMoveModel : public ::gfl2::renderingengine::scenegraph::NodeTrait<FieldMoveModel, ::Field::IField3DObjectNode> {
public:
    static ::gfl2::util::FnvHash GetTypeHash()
    {
        return ::gfl2::util::FnvHash(reinterpret_cast<const u8 *>("Node::DagNode::InstanceNode::FieldNode::Field3DObjectNode"));
    }
};

// a guess: some inline code of the game's headers asks for this class's place in the node
// hierarchy (a cast to it, most likely), which is why a file that includes this header
// builds the class's Inheritance in its static initializer. the name is ours.
inline const ::gfl2::renderingengine::scenegraph::Inheritance *FieldMoveModelInheritance()
{
    return FieldMoveModel::GetInheritanceStatic();
}

}  // namespace MoveModel
}  // namespace Field

#endif
