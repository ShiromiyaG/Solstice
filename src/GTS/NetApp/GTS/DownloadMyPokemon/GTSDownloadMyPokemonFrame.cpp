#include "NetApp/GTS/DownloadMyPokemon/GTSDownloadMyPokemonFrame.h"
#include "NetApp/GTS/ApplicationSystem/GTSViewObjects.h"

// callees without a name; the parameter types are guesses from what is passed
void f_GTS_000126A0(::NetApp::GTS::DownloadMyPokemon::GTSDownloadMyPokemonFrame *frame, void *view);
void f_GTS_000128C8(void *view, u32 a1, u32 a2);

namespace NetApp {
namespace GTS {
namespace DownloadMyPokemon {

// field_48 stands for a pointer to GTSViewObjects; its field_34 is the view (a guess)

//! GTS:0x0000F1BC _ZN6NetApp3GTS17DownloadMyPokemon25GTSDownloadMyPokemonFrame43GTSDownloadStateConfirmResponseListener_vf1
void GTSDownloadMyPokemonFrame::GTSDownloadStateConfirmResponseListener_vf1() {
    field_4C = 0;
    f_GTS_000126A0(this, ((::NetApp::GTS::ApplicationSystem::GTSViewObjects *)field_48)->field_34);
    f_GTS_000128C8(((::NetApp::GTS::ApplicationSystem::GTSViewObjects *)field_48)->field_34, 4, 0);
}

//! GTS:0x00012898 _ZN6NetApp3GTS17DownloadMyPokemon25GTSDownloadMyPokemonFrame43GTSDownloadStateConfirmResponseListener_vf0
void GTSDownloadMyPokemonFrame::GTSDownloadStateConfirmResponseListener_vf0() {
    f_GTS_000126A0(this, ((::NetApp::GTS::ApplicationSystem::GTSViewObjects *)field_48)->field_34);
    f_GTS_000128C8(((::NetApp::GTS::ApplicationSystem::GTSViewObjects *)field_48)->field_34, 2, 0);
}

}  // namespace DownloadMyPokemon
}  // namespace GTS
}  // namespace NetApp
