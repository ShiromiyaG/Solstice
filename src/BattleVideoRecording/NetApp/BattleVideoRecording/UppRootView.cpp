#include "NetApp/BattleVideoRecording/UppRootView.h"

namespace NetApp {
namespace BattleVideoRecording {

//! BattleVideoRecording:0x0000111C UppRootViewD1Ev
UppRootView::~UppRootView()
{
    ReleaseButtonManager();
    Delete2D();
}

}  // namespace BattleVideoRecording
}  // namespace NetApp
