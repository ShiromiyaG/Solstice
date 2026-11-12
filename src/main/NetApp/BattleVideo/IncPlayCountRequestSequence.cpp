#include "NetApp/BattleVideo/IncPlayCountRequestSequence.h"

//! 0x003DC3BC ~IncPlayCountRequestSequence
namespace NetApp {
namespace BattleVideo {

// open: the game calls the dtor of the base at +0x18 (0x003DB928) before delete;
// NexDataStoreClientListener's header has no virtuals or dtor, so the base dtor is not declared.
IncPlayCountRequestSequence::~IncPlayCountRequestSequence() {
}

}  // namespace BattleVideo
}  // namespace NetApp
