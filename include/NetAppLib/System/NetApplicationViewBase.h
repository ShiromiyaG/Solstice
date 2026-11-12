#ifndef NETAPPLIB_SYSTEM_NETAPPLICATIONVIEWBASE_H
#define NETAPPLIB_SYSTEM_NETAPPLICATIONVIEWBASE_H

#include "app/ui/UIView.h"
#include "app/util/G2DUtil.h"

#include "types.h"

namespace NetAppLib { namespace Message { class MessageUtility; } }
namespace NetAppLib { namespace System { class ApplicationWorkBase; } }
namespace app { namespace util { class Heap; } }

namespace NetAppLib {
namespace System {

// a UIView with one layout: the constructor that takes the work fills a G2DUtil::LytResData at
// +0x80 and a G2DUtil::LytwkData at +0x8c and passes both to UIView::Create2D. the destructor
// deletes the 2D and the graphics system (code.bin:0047E1B4). 0xa0 bytes: the derived views put
// their next base there.
class NetApplicationViewBase : public ::app::ui::UIView {
public:
    NetApplicationViewBase(::app::util::Heap*);  // code.bin:0047E00C
    NetApplicationViewBase(::NetAppLib::System::ApplicationWorkBase*, int, unsigned int, unsigned int, ::app::util::G2DUtil::SETUP_DISPLAY_TYPE, ::NetAppLib::Message::MessageUtility*, unsigned int);  // code.bin:0047E050
    virtual ~NetApplicationViewBase();  // slots 5, 6: code.bin:0047E1B4, 0047E17C
    virtual void Create2DOneLayout(::NetAppLib::System::ApplicationWorkBase*, int, unsigned int, unsigned int, ::app::util::G2DUtil::SETUP_DISPLAY_TYPE, ::NetAppLib::Message::MessageUtility*, unsigned int);  // slot 21, code.bin:0047DF2C

    void setupLayout(unsigned int, unsigned int);  // code.bin:0047DED0

    // +0x80..+0x8b: an app::util::G2DUtil::LytResData (12 bytes, passed to Create2D as its
    // LytResData const*): the resource buffer of the work's ResourceManager, then two words
    // (both 0). they stay plain fields while G2DUtil.h has LytResData empty.
    void *field_80;  // +0x80: the layout's resource buffer (LytResData's first word; a guess of the name)
    u32 field_84;  // +0x84: LytResData's second word (a guess)
    u32 field_88;  // +0x88: LytResData's third word (a guess)
    // +0x8c..+0x9f: an app::util::G2DUtil::LytwkData (0x14 bytes, passed to Create2D as its
    // LytwkData const*). same reason as above for the plain fields.
    u32 field_8C;  // +0x8c: LytwkData +0x0 (0 here; a guess: the resource index)
    u32 field_90;  // +0x90: LytwkData +0x4, the constructor's 3rd argument (unsigned int)
    u32 field_94;  // +0x94: LytwkData +0x8, the constructor's 4th argument (unsigned int; the code copies it through s16, it is not a float)
    void *field_98;  // +0x98: LytwkData +0xc, the resource buffer again (a guess: a pointer)
    bool field_9C;  // +0x9c: LytwkData +0x10, set to 1 (a guess: bool)
    u8 field_9D;  // +0x9d: LytwkData +0x11, the SETUP_DISPLAY_TYPE argument (stored as a byte)
    bool field_9E;  // +0x9e: LytwkData +0x12, set to 1 (a guess: bool)
    u8 unk_9F[0x1];  // +0x9f: LytwkData's padding
};

}  // namespace System
}  // namespace NetAppLib

#endif
