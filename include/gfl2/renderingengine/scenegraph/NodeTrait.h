#ifndef GFL2_RENDERINGENGINE_SCENEGRAPH_NODETRAIT_H
#define GFL2_RENDERINGENGINE_SCENEGRAPH_NODETRAIT_H

#include "gfl2/renderingengine/scenegraph/Inheritance.h"
#include "gfl2/renderingengine/scenegraph/NullType.h"

namespace gfl2 {
namespace renderingengine {
namespace scenegraph {

// what every node class derives from: class T : public NodeTrait<T, Base>.
// NodeTrait<T, B> derives from NodeInheritance<T, B>, which derives from B (the game's type
// information), and holds T's Inheritance, made from B's and from T::GetTypeHash().
// the names s_Inheritance, Generate and GetTypeHash are the game's own (its imports);
// GetInheritanceStatic is a guess, GetInheritance is the virtual in slot 3 of DagNode.
template <class T, class B>
class NodeInheritance : public B {
public:
    static const Inheritance *GetInheritanceStatic() { return &s_Inheritance; }
    virtual const Inheritance *GetInheritance() const { return &s_Inheritance; }

    static Inheritance s_Inheritance;
};

template <class T, class B>
Inheritance NodeInheritance<T, B>::s_Inheritance = Inheritance::Generate(B::GetInheritanceStatic(), T::GetTypeHash());

// the root of the hierarchy has no Inheritance: its children's parent is null
template <class T>
class NodeInheritance<T, NullType> : public NullType {
public:
    static const Inheritance *GetInheritanceStatic() { return 0; }
    virtual const Inheritance *GetInheritance() const { return 0; }
};

template <class T, class B>
class NodeTrait : public NodeInheritance<T, B> {
};

}  // namespace scenegraph
}  // namespace renderingengine
}  // namespace gfl2

#endif
