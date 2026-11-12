#include "types.h"
#include "App/FinderStudio/Static/ViewBase.h"
#include "App/ui/UIResponder.h"

//! 0x002CC988 _Show
void App::FinderStudio::Static::ViewBase::_Show()
{
    SetVisible(true);
    SetInputEnabled(true);
    field_A1 = 1;
}
