#include "NetApp/QRReader/Frame_QRSimpleRead.h"
#include "types.h"

namespace NetApp {
namespace QRReader {

//! QRReader:0x000054C0 vf13
void Frame_QRSimpleRead::vf13() {
    *(u32 *)((u8 *)field_1C3C + 0xb4) = 0;
}

}  // namespace QRReader
}  // namespace NetApp
