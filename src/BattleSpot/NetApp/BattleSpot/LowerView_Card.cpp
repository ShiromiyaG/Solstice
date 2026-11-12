#include "types.h"
#include "NetApp/BattleSpot/LowerView_Card.h"
#include "NetAppLib/UI/NetAppCursorView.h"
#include "NetAppLib/UI/NetAppPokeparaUtility.h"

// the poke para utility is the object at +0x2d4, which the header has as unk_2D4 (its type is not
// known there yet). the cast stands in for a member of that type: a guess until the header has
// the field (the header is generated; not edited here). the last call is a tail call (b).
//! BattleSpot:0x00001D34 Update
void NetApp::BattleSpot::LowerView_Card::Update()
{
    NetAppLib::UI::NetAppCursorView::Update();
    ((::NetAppLib::UI::NetAppPokeparaUtility *)((u8 *)this + 0x2d4))->OnUpdate();
}
