#include "types.h"

namespace gfl2 {
namespace renderingengine {
namespace scenegraph {
namespace instance {
class DrawableNode;
}
}
}
}

namespace System {
class ModelRenderPath {
public:
    void AddNode(gfl2::renderingengine::scenegraph::instance::DrawableNode *node);
};
}

namespace poke_3d {
namespace renderer {
class EdgeMapSceneRenderPath {
public:
    void AddEdgeRenderingTarget(gfl2::renderingengine::scenegraph::instance::DrawableNode *node);
};
}
}

//! FinderStudioViewer:0x0000FC40 f_FinderStudioViewer_0000FC40
extern "C" void f_FinderStudioViewer_0000FC40(u8 *a1, u8 *a2)
{
    ((System::ModelRenderPath *)*(u8 **)(a1 + 0x1c))->AddNode(*(gfl2::renderingengine::scenegraph::instance::DrawableNode **)(a2 + 4));
    u8 *target = *(u8 **)(a1 - 0x80 + 0xa0);
    if (target) {
        ((poke_3d::renderer::EdgeMapSceneRenderPath *)target)->AddEdgeRenderingTarget(*(gfl2::renderingengine::scenegraph::instance::DrawableNode **)(a2 + 4));
    }
}
