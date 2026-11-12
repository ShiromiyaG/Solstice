#include "App/Event/ShopBuyEvent.h"

//! 0x002DA788 ~ShopBuyEvent
namespace App {
namespace Event {

// open: the game destroys a member of type app::util::Heap at this+0x50 before
// GameEvent's dtor; ShopBuyEvent.h has no member there (unk_40 covers it).
ShopBuyEvent::~ShopBuyEvent() {
}

}  // namespace Event
}  // namespace App
