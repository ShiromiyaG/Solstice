#ifndef NETAPP_GTS_STATECONFIRM_GTSSTATECONFIRMFRAME_H
#define NETAPP_GTS_STATECONFIRM_GTSSTATECONFIRMFRAME_H

#include "NetApp/GTS/GTSFrameBase.h"
#include "NetApp/GTS/RequestSequence/GTSStartStateConfirmResponseListener.h"
#include "NetApp/GTS/RequestSequence/GTSDownloadTradePokemonResponseListener.h"
#include "NetApp/GTS/RequestSequence/GTSRestorePokemonResponseListener.h"
#include "NetAppLib/Util/NetAppTimeout.h"

#include "types.h"

namespace NetApp { namespace GTS { namespace ApplicationSystem { class GTSWork; class GTSViewObjects; } } }

namespace NetApp {
namespace GTS {
namespace StateConfirm {

class GTSStateConfirmFrame : public ::NetApp::GTS::GTSFrameBase, public ::NetApp::GTS::RequestSequence::GTSStartStateConfirmResponseListener, public ::NetApp::GTS::RequestSequence::GTSDownloadTradePokemonResponseListener, public ::NetApp::GTS::RequestSequence::GTSRestorePokemonResponseListener {
    // NetApp::GTS::RequestSequence::GTSStartStateConfirmResponseListener at +0x34
    // NetApp::GTS::RequestSequence::GTSDownloadTradePokemonResponseListener at +0x38
    // NetApp::GTS::RequestSequence::GTSRestorePokemonResponseListener at +0x3c
public:
    virtual ~GTSStateConfirmFrame();  // slot 0 GTS:00003CEC (D1), slot 1 GTS:00003CB0 (D0)
    virtual bool vf10();  // overrides  // slot 10, GTS:00003BC8; returns 1 (bool is a guess)
    virtual void vf12();  // overrides  // slot 12, GTS:0000393C
    virtual void vf13();  // overrides  // slot 13, GTS:00012B40
    virtual void vf14(u32 a1, u32 a2, u32 a3);  // overrides  // slot 14, GTS:00003950; the parameters are a guess from its code (types too)
    virtual void vf17();  // slot 17, GTS:00003A44
    // slots 18 to 25 are this class's overrides of its listener bases (Itanium ABI: an overrider of a
    // secondary base gets a primary slot): 18-22 GTSStartStateConfirmResponseListener vf0-vf4
    // (thunks GTS:0001ACD0, 0001ACC0, 0001AC60, 0001AC90, 0001AC50), 23-24
    // GTSDownloadTradePokemonResponseListener vf0-vf1 (GTS:0001B0BC, 0001B0B0), 25
    // GTSRestorePokemonResponseListener vf0 (GTS:0001B1D8). They need the listeners' real names
    // (each listener's vf0 is another function) to be declared as overrides here.
    virtual void vf18();  // slot 18, GTS:00003BB8
    virtual void vf19();  // slot 19, GTS:00003BA8
    virtual void vf20();  // slot 20, GTS:00003B48
    virtual void vf21();  // slot 21, GTS:00003B78
    virtual void vf22();  // slot 22, GTS:00003B20
    virtual void vf23();  // slot 23, GTS:00003B3C
    virtual void vf24();  // slot 24, GTS:00003B30
    virtual void vf25();  // slot 25, GTS:00003B14

    // data members, from how the class's functions use this (tools/fields.py)
    ::NetApp::GTS::ApplicationSystem::GTSWork *field_40;  // +0x40, a guess: the GTS work (passed to the request sequences)
    ::NetApp::GTS::ApplicationSystem::GTSViewObjects *field_44;  // +0x44, a guess: the GTS views (its +0x34 is the message window)
    u8 unk_48[0x4];  // +0x48: an object whose address is the message window's listener (field_148); its class is not known
    s32 field_4C;  // +0x4c, a guess: set to -1 by vf14, tested against 0 by vf17
    s32 field_50;  // +0x50, a guess: compared with 2 and 4 by vf17
    u8 unk_54[0x4];  // +0x54: nothing seen to use it
    ::NetAppLib::Util::NetAppTimeout field_58;  // +0x58, a guess: an object, from 2 functions
    u8 unk_84[0x4];  // +0x84: nothing seen to use it
    u8 field_88;  // +0x88, a guess: a sequence state (0 to 4), from 5 functions
};

}  // namespace StateConfirm
}  // namespace GTS
}  // namespace NetApp

#endif
