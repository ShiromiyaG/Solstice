#include "NetApp/JoinFestaAttractionListSelect/Frame/JoinFestaAttractionListSelectEntryFrame.h"

int f_JoinFestaAttractionListSelect_00000218();
// SingletonAccessor<JoinFestaPacketManager>::GetInstance (module 0x2D0) and
// JoinFestaPacketManager::RemovePersonalListener (module 0x2E0), named by their addresses
void *f_JoinFestaAttractionListSelect_000002D0();
void f_JoinFestaAttractionListSelect_000002E0(void *manager, void *listener);
void f_JoinFestaAttractionListSelect_00000258(void *a1, int a2);

namespace NetApp {
namespace JoinFestaAttractionListSelect {
namespace Frame {

// the three overrides of JoinFestaPersonalListener have the same body; each also makes the
// thunk of the listener's vtable (this - 0x30)

//! JoinFestaAttractionListSelect:0x00001600 JoinFestaPersonalListener_vf0
//! JoinFestaAttractionListSelect:0x000027CC _ZThn48_N6NetApp29JoinFestaAttractionListSelect5Frame39JoinFestaAttractionListSelectEntryFrame29JoinFestaPersonalListener_vf0
void JoinFestaAttractionListSelectEntryFrame::JoinFestaPersonalListener_vf0(u32 a1) {
    int wlan = f_JoinFestaAttractionListSelect_00000218();
    return f_JoinFestaAttractionListSelect_00000258(*(void **)(*(u8 **)((u8 *)this + 0x2c) + 0x14), wlan);
}

//! JoinFestaAttractionListSelect:0x00001648 JoinFestaPersonalListener_vf1
//! JoinFestaAttractionListSelect:0x00002814 _ZThn48_N6NetApp29JoinFestaAttractionListSelect5Frame39JoinFestaAttractionListSelectEntryFrame29JoinFestaPersonalListener_vf1
void JoinFestaAttractionListSelectEntryFrame::JoinFestaPersonalListener_vf1() {
    int wlan = f_JoinFestaAttractionListSelect_00000218();
    return f_JoinFestaAttractionListSelect_00000258(*(void **)(*(u8 **)((u8 *)this + 0x2c) + 0x14), wlan);
}

//! JoinFestaAttractionListSelect:0x00001624 JoinFestaPersonalListener_vf2
//! JoinFestaAttractionListSelect:0x000027F0 _ZThn48_N6NetApp29JoinFestaAttractionListSelect5Frame39JoinFestaAttractionListSelectEntryFrame29JoinFestaPersonalListener_vf2
void JoinFestaAttractionListSelectEntryFrame::JoinFestaPersonalListener_vf2(u32 a1) {
    int wlan = f_JoinFestaAttractionListSelect_00000218();
    return f_JoinFestaAttractionListSelect_00000258(*(void **)(*(u8 **)((u8 *)this + 0x2c) + 0x14), wlan);
}

//! JoinFestaAttractionListSelect:0x00001040 _ZN6NetApp29JoinFestaAttractionListSelect5Frame39JoinFestaAttractionListSelectEntryFrame4vf13
void JoinFestaAttractionListSelectEntryFrame::vf13() {
    // open: DIFFER. the game keeps the zero in r1 for both stores and writes the second
    // field_2C load from this; ours stores a zero from r0 and loads r1 first. Tried: the
    // two stores as written here (the first load scheduled first), a local for field_2C
    // (the game reloads this->field_2C).
    *(u32 *)(*(u8 **)((u8 *)field_2C + 0x14) + 0xec) = 0;
    *(u32 *)(*(u8 **)((u8 *)field_2C + 0x10) + 0xac) = 0;
    f_JoinFestaAttractionListSelect_000002E0(f_JoinFestaAttractionListSelect_000002D0(), (u8 *)this + 0x30);
}

}  // namespace Frame
}  // namespace JoinFestaAttractionListSelect
}  // namespace NetApp
