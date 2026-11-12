#include "types.h"
namespace NetAppLib { namespace Message {
class MessageUtility {
public:
    void* GetData(u32 id);
    void LoadFromMemory(u32 id, const void* p);
};
} }
struct Gim { u8 pad[0x10]; const void* field_10; u8 pad2[0x14]; NetAppLib::Message::MessageUtility msg; };
//! FieldGimmickBattleFes:0x000010CC getmsg
void* getmsg(Gim* g) {
    if (!g->msg.GetData(0x2e)) g->msg.LoadFromMemory(0x2e, g->field_10);
    return g->msg.GetData(0x2e);
}
