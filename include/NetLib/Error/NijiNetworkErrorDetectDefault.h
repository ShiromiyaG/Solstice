#ifndef NETLIB_ERROR_NIJINETWORKERRORDETECTDEFAULT_H
#define NETLIB_ERROR_NIJINETWORKERRORDETECTDEFAULT_H

#include "gflnet2/wifi/WifiDisconnectListener.h"
#include "gflnet2/p2p/NetGameErrorListener.h"
#include "gflnet2/nex/NexErrorListener.h"
#include "gflnet2/dev/IrAdapterErrorListener.h"
#include "NetLib/P2P/P2pConnectionErrorListener.h"
#include "ExtSavedata/NijiExtSaveSystemListener.h"
#include "NetLib/Error/NijiNetworkError.h"

#include "types.h"

namespace NetLib {
namespace Error {

class NijiNetworkErrorManager;

class NijiNetworkErrorDetectDefault : public ::gflnet2::wifi::WifiDisconnectListener, public ::gflnet2::p2p::NetGameErrorListener, public ::gflnet2::nex::NexErrorListener, public ::gflnet2::dev::IrAdapterErrorListener, public ::NetLib::P2P::P2pConnectionErrorListener, public ::ExtSavedata::NijiExtSaveSystemListener {
    // gflnet2::p2p::NetGameErrorListener at +0x4
    // gflnet2::nex::NexErrorListener at +0x8
    // gflnet2::dev::IrAdapterErrorListener at +0xc
    // NetLib::P2P::P2pConnectionErrorListener at +0x10
    // ExtSavedata::NijiExtSaveSystemListener at +0x14
public:
    // the overrides of the secondary bases' slots (their thunks at -4..-20) have no names yet:
    // the bases' headers name them vf0, vf1, vf2 alike, so they cannot be declared here
    virtual void vf0_NijiNetworkErrorDetectDefault(u32 a1);  // slot 0, code.bin:003F2F20; a1 is passed on to the error (stored at its +0x8): type a guess
    virtual ~NijiNetworkErrorDetectDefault();
    virtual void vf3_NijiNetworkErrorDetectDefault();  // slot 3, code.bin:003F2F60
    virtual void vf4_NijiNetworkErrorDetectDefault();  // slot 4, code.bin:003F2F84
    virtual void vf5_NijiNetworkErrorDetectDefault(u32 a1);  // slot 5, code.bin:003F289C; a1 is passed on to the error's code: type a guess
    virtual void vf6();  // slot 6, code.bin:003F307C
    virtual void vf7();  // slot 7, code.bin:003F2FEC
    virtual void vf8();  // slot 8, code.bin:003F3010
    virtual void vf9();  // slot 9, code.bin:003F2FC8
    virtual void vf10();  // slot 10, code.bin:003F3034
    virtual void vf11(unsigned int errorCode);  // slot 11, code.bin:003F2FA8; passed to NijiNetworkError::SetResultErrorCode(unsigned int)
    virtual void vf12();  // slot 12, code.bin:003F30C4
    virtual void vf13();  // slot 13, code.bin:003F30E8
    virtual void vf14();  // slot 14, code.bin:003F30A0
    virtual void vf15();  // slot 15, code.bin:003F3058
    virtual void vf16();  // slot 16, code.bin:003F2F40

    // data members: the names are guesses, the types are what every slot does with them.
    // In the game they are at +0x18 and +0x24; they land at +0x14 and +0x20 until
    // gflnet2/wifi/WifiDisconnectListener.h declares its virtual function(s) (the game's
    // secondary vtables at -4..-20 show it is the dynamic primary base at +0).
    NijiNetworkError m_error;  // +0x18, the error that each slot fills and reports
    NijiNetworkErrorManager *m_manager;  // +0x24, the manager it is reported to
};

}  // namespace Error
}  // namespace NetLib

#endif
