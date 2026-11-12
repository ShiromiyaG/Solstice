#ifndef FIELD_TRIALMODEL_FIELDTRIALMODEL_H
#define FIELD_TRIALMODEL_FIELDTRIALMODEL_H

#include "Field/IField3DObjectNode.h"

namespace Field {
namespace TrialModel {

// its virtual functions are not written yet: config/us-v1.2/vtables.csv has them by slot
class FieldTrialModel : public ::gfl2::renderingengine::scenegraph::NodeTrait<FieldTrialModel, ::Field::IField3DObjectNode> {
public:
    static ::gfl2::util::FnvHash GetTypeHash()
    {
        return ::gfl2::util::FnvHash(reinterpret_cast<const u8 *>("Node::DagNode::InstanceNode::FieldNode::Field3DObjectNode::FieldTrialModel"));
    }
};

// a guess: some inline code of the game's headers asks for this class's place in the node
// hierarchy (a cast to it, most likely), which is why a file that includes this header
// builds the class's Inheritance in its static initializer. the name is ours.
inline const ::gfl2::renderingengine::scenegraph::Inheritance *FieldTrialModelInheritance()
{
    return FieldTrialModel::GetInheritanceStatic();
}

}  // namespace TrialModel
}  // namespace Field

#endif
