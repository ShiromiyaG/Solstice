#ifndef GFL2_RENDERINGENGINE_SCENEGRAPH_INHERITANCE_H
#define GFL2_RENDERINGENGINE_SCENEGRAPH_INHERITANCE_H

#include "gfl2/util/FnvHash.h"

namespace gfl2 {
namespace renderingengine {
namespace scenegraph {

// a node class's place in the node hierarchy: its parent's, and the hash of its name.
// 8 bytes. the members' names are guesses.
class Inheritance {
public:
    static Inheritance Generate(const Inheritance *pParent, util::FnvHash hash);

    const Inheritance *m_pParent;
    util::FnvHash m_Hash;
};

}  // namespace scenegraph
}  // namespace renderingengine
}  // namespace gfl2

#endif
