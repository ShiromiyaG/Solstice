#include "types.h"
#include "App/FinderStudio/Static/ViewUtil.h"
#include "App/ui/UIView.h"
#include "gfl2/lyt/LytSys.h"
#include "gfl2/lyt/LytRes.h"

//! 0x004B74C0 GetTextureInfo
::app::tool::LytTexReplaceSystem *App::FinderStudio::Static::ViewUtil::GetTextureInfo(unsigned int a2) {
    ::gfl2::lyt::LytRes *res = ((app::ui::UIView *)*(void **)this)->GetLayoutSystem()->GetResource((::gfl2::lyt::LytMultiResID const *)((u8 *)this + 8));
    return res->GetTexture(a2, 0);
}
