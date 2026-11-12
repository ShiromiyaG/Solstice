#include "types.h"
#include "NetLib/Error/NijiNetworkErrorDetectDefault.h"
#include "NetLib/Error/NijiNetworkError.h"
#include "NetLib/Error/NijiNetworkErrorManager.h"

// The functions below that use m_error and m_manager differ from the game only by their offsets
// (+0x14/+0x20 here, +0x18/+0x24 in the game): gflnet2/wifi/WifiDisconnectListener.h declares no
// virtual function, so the compiler puts NetGameErrorListener at +0 as the primary base instead of
// at +0x4. The game's secondary vtables (-4 to -20) show WifiDisconnectListener is dynamic. Once
// that header has its virtual(s), these sources should give the game's bytes as they are.

// NijiNetworkError's functions without a name (each sets the error's kind at +0x5 and its code)
void sub_003F19E0(NetLib::Error::NijiNetworkError *error);
void sub_003F1D3C(NetLib::Error::NijiNetworkError *error, u32 a1);
void sub_003F20DC(NetLib::Error::NijiNetworkError *error, u32 a1);

// the fields at +0x18 (the error object) and +0x24 (the manager) are not in the header yet
//! 0x003F2FC8 vf9
void NetLib::Error::NijiNetworkErrorDetectDefault::vf9() {
    ((NetLib::Error::NijiNetworkError *)((u8 *)this + 0x18))->SetResult((NetLib::Error::NijiNetworkError::ENUM_ERROR_TYPE)1);
    ((NetLib::Error::NijiNetworkErrorManager *)*(void **)((u8 *)this + 0x24))->SetNetworkError(*(NetLib::Error::NijiNetworkError *)((u8 *)this + 0x18));
}

//! 0x003F289C vf5
void NetLib::Error::NijiNetworkErrorDetectDefault::vf5_NijiNetworkErrorDetectDefault(u32 a1) {
    sub_003F1D3C(&m_error, a1);
    m_manager->SetNetworkError(m_error);
}

//! 0x003F2F20 vf0
void NetLib::Error::NijiNetworkErrorDetectDefault::vf0_NijiNetworkErrorDetectDefault(u32 a1) {
    sub_003F20DC(&m_error, a1);
    m_manager->SetNetworkError(m_error);
}

//! 0x003F2F40 vf16
void NetLib::Error::NijiNetworkErrorDetectDefault::vf16() {
    sub_003F19E0(&m_error);
    m_manager->SetNetworkError(m_error);
}

//! 0x003F2F60 vf3
void NetLib::Error::NijiNetworkErrorDetectDefault::vf3_NijiNetworkErrorDetectDefault() {
    m_error.SetResult((NetLib::Error::NijiNetworkError::ENUM_ERROR_TYPE)4);
    m_manager->SetNetworkError(m_error);
}

//! 0x003F2F84 vf4
void NetLib::Error::NijiNetworkErrorDetectDefault::vf4_NijiNetworkErrorDetectDefault() {
    m_error.SetResult((NetLib::Error::NijiNetworkError::ENUM_ERROR_TYPE)2);
    m_manager->SetNetworkError(m_error);
}

//! 0x003F2FA8 vf11
void NetLib::Error::NijiNetworkErrorDetectDefault::vf11(unsigned int errorCode) {
    m_error.SetResultErrorCode(errorCode);
    m_manager->SetNetworkError(m_error);
}

//! 0x003F2FEC vf7
void NetLib::Error::NijiNetworkErrorDetectDefault::vf7() {
    m_error.SetResult((NetLib::Error::NijiNetworkError::ENUM_ERROR_TYPE)6);
    m_manager->SetNetworkError(m_error);
}

//! 0x003F3010 vf8
void NetLib::Error::NijiNetworkErrorDetectDefault::vf8() {
    m_error.SetResult((NetLib::Error::NijiNetworkError::ENUM_ERROR_TYPE)7);
    m_manager->SetNetworkError(m_error);
}

//! 0x003F3058 vf15
void NetLib::Error::NijiNetworkErrorDetectDefault::vf15() {
    m_error.SetResult((NetLib::Error::NijiNetworkError::ENUM_ERROR_TYPE)3);
    m_manager->SetNetworkError(m_error);
}

//! 0x003F307C vf6
void NetLib::Error::NijiNetworkErrorDetectDefault::vf6() {
    m_error.SetResult((NetLib::Error::NijiNetworkError::ENUM_ERROR_TYPE)5);
    m_manager->SetNetworkError(m_error);
}

//! 0x003F30A0 vf14
void NetLib::Error::NijiNetworkErrorDetectDefault::vf14() {
    m_error.SetResult((NetLib::Error::NijiNetworkError::ENUM_ERROR_TYPE)2);
    m_manager->SetNetworkError(m_error);
}

//! 0x003F30C4 vf12
void NetLib::Error::NijiNetworkErrorDetectDefault::vf12() {
    m_error.SetResult((NetLib::Error::NijiNetworkError::ENUM_ERROR_TYPE)4);
    m_manager->SetNetworkError(m_error);
}

// 0x004CBD18 (IrAdapterErrorListener at +0xc, its slot 2: SetResult(1), as vf9, vf10 and vf13) and
// 0x004CCFA4 (P2pConnectionErrorListener at +0x10, its slot 1: SetResultErrorCode(r1), as vf11) are
// the thunks of the overrides of those bases' slots, with the body inlined. They come out of the
// compiler only when this class declares the override under the base's name; the bases' headers
// name their slots vf0, vf1, vf2 alike (a `vf2` here would override four bases at once), so they
// stay open until those slots have their real names.
