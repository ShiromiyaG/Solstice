#ifndef APP_UI_UIVIEW_H
#define APP_UI_UIVIEW_H

#include "app/ui/UIResponder.h"
#include "app/util/G2DUtil.h"
#include "gfl2/gfx/CtrDisplayNo.h"
#include "gfl2/lyt/DisplayType.h"
#include "gfl2/lyt/MemoryArea.h"
#include "print/NumberCodeType.h"
#include "print/NumberDispType.h"

#include "types.h"

namespace app { namespace util { class G2DUtil; } }
namespace app { namespace util { class Heap; } }
namespace gfl2 { namespace heap { class NwAllocator; } }
namespace gfl2 { namespace lyt { class LytMultiResID; } }
namespace gfl2 { namespace lyt { class LytSys; } }
namespace gfl2 { namespace lyt { class LytWk; } }
namespace gfl2 { namespace str { class MsgData; } }
namespace gfl2 { namespace str { class StrBuf; } }
namespace gfl2 { namespace ui { class TouchPanel; } }
namespace nw { namespace lyt { class Pane; } }
namespace nw { namespace lyt { class TextBox; } }
namespace print { class WordSet; }

namespace app {
namespace ui {

// 0x80 bytes: the views that add app::ui::UIInputListener as a second base have it at +0x80.
class UIView : public ::app::ui::UIResponder {
public:
    virtual ~UIView();  // slots 5 (code.bin:002EF138) and 6 (code.bin:002EF124)
    // slots 9 to 12 and 18 are empty (bx lr) and every module has its own copies: inline.
    // AddSubView calls slot 9 on the parent and slot 10 on the child; the destructor calls
    // slot 11 on the parent and slot 12 on the child; none passes anything.
    virtual void OnAddChild() {}  // slot 9, code.bin:002EE504
    virtual void UIView_vf10() {}  // slot 10, code.bin:002EE78C
    virtual void OnRemoveChild() {}  // slot 11, code.bin:002EE708
    virtual void UIView_vf12() {}  // slot 12, code.bin:002EE834
    virtual void Update();  // slot 13, code.bin:002EEB10
    virtual void Draw(::gfl2::gfx::CtrDisplayNo) = 0;  // slot 14, __cxa_pure_virtual in UIView's vtable
    virtual void SetVisible(bool);  // slot 15, code.bin:002EE508; writes field_6C
    // returns field_6C (ldrsb, like UIResponder::IsInputEnabled): bool is likely; s8 stays
    // while the derived headers redeclare it so
    virtual s8 IsVisible() const;  // slot 16, code.bin:004AAE10
    virtual bool IsDrawing() const;  // slot 17, code.bin:004AADF4; field_60's IsDrawing, false without it
    virtual void UIView_vf18() {}  // slot 18, code.bin:002EE830
    virtual void Initalize2D(::app::util::Heap*, ::gfl2::lyt::LytSys*, unsigned int, ::app::util::G2DUtil::LytResData const*, unsigned int, ::app::util::G2DUtil::LytwkData const*, unsigned int, int, int);  // slot 19, code.bin:002EE524
    virtual bool DoInputAction();  // slot 20, code.bin:002EE648; the return type is a guess from its code (0 or 1)

    // member functions the game names. static or not is not in a name, nor is the return type
    // (void until config/<version>/returns.csv has it)
    void AddSubView(::app::ui::UIView*);  // code.bin:002EE490
    void Create2D(::app::util::Heap*, ::gfl2::lyt::LytSys*, unsigned int, ::app::util::G2DUtil::LytResData const*, unsigned int, ::app::util::G2DUtil::LytwkData const*, unsigned int, ::gfl2::str::MsgData*, ::print::WordSet*, int, int, int);  // code.bin:002EEBFC
    void Create2D(::app::util::Heap*, ::gfl2::lyt::LytSys*, unsigned int, ::app::util::G2DUtil::LytResData const*, unsigned int, ::app::util::G2DUtil::LytwkData const*, unsigned int, unsigned int, int, int, int);  // code.bin:002EEC74
    void Create2D(::app::util::Heap*, ::gfl2::lyt::LytSys*, unsigned int, ::app::util::G2DUtil::LAYOUT_WORK*, unsigned int, ::gfl2::lyt::LytMultiResID*, ::gfl2::str::MsgData*, ::print::WordSet*);  // code.bin:002EEE20
    void CreateGraphicsSystem(::app::util::Heap*, bool);  // code.bin:002EE8C0; sets field_70 when the bool is true
    void Delete2D();  // code.bin:002EEEB8
    void DeleteGraphicsSystem();  // code.bin:002EE8E4; clears field_70
    void DrawTree(::gfl2::gfx::CtrDisplayNo);  // code.bin:002EEF90
    ::app::util::G2DUtil *GetG2DUtil() const;  // code.bin:004AAD2C; returns field_60
    ::gfl2::lyt::LytSys *GetLayoutSystem() const;  // code.bin:004AAD48; field_60->GetLayoutSystem() (a tail call), 0 without it
    ::gfl2::lyt::LytWk *GetLayoutWork(unsigned int) const;  // code.bin:004AAD34; field_60->GetLayoutWork(id) (a tail call), 0 without it
    void GetLytSetup(::gfl2::lyt::DisplayType);  // code.bin:003187FC
    ::app::ui::UIView *GetSuperView();  // code.bin:002EE640; returns field_40
    void GetToucHoldPane(::gfl2::ui::TouchPanel const*, unsigned int, ::nw::lyt::Pane*) const;  // code.bin:004AAD5C
    bool IsExistSubView(::app::ui::UIView*);  // code.bin:002EE740; the return type is a guess from its callers: only tested, and the name asks
    void RemoveAllSubView();  // code.bin:002EE790
    void RemoveFromSuperView();  // code.bin:002EE83C
    void SetInputEnabledAllView(bool);  // code.bin:002EEAC0
    void SetLayoutTransferArea(::gfl2::lyt::MemoryArea);  // code.bin:002EE9B8; writes field_74
    void SetModal(bool);  // code.bin:002EF07C; writes field_6D
    void SetTextboxPaneMessage(::nw::lyt::TextBox*, ::gfl2::str::StrBuf const*);  // code.bin:003D27E4
    void SetTextboxPaneMessage(::nw::lyt::TextBox*, int);  // code.bin:002EE9E4
    void SetTextboxPaneMessage(unsigned int, unsigned int, int);  // code.bin:002EEA4C
    void SetTextboxPaneNumber(::nw::lyt::TextBox*, unsigned int, unsigned int, unsigned int, unsigned int, ::print::NumberDispType, ::print::NumberCodeType);  // code.bin:002EE8F8
    void SetTextboxPaneString(::nw::lyt::TextBox*, ::gfl2::str::StrBuf*);  // code.bin:002EE990
    void SetTextboxPaneString(unsigned int, unsigned int, wchar_t const*);  // code.bin:00318E70
    UIView(::app::util::Heap*, ::gfl2::heap::NwAllocator*, ::gfl2::heap::NwAllocator*);  // code.bin:002EF084
    void UpdateG2DUtil();  // code.bin:002EE70C
    void UpdateTree();  // code.bin:002EE510

    // data members (from the constructor 002EF084, the destructor, AddSubView, Update,
    // Initalize2D and Delete2D; names are guesses)
    // +0x34..+0x3F: this view as an element of its parent's sub-view list: the view, then the
    // list node (next, prev; nw::ut's layout, a guess). AddSubView inserts +0x38 into the
    // parent's list at +0x44; the readers find the view at node - 4.
    ::app::ui::UIView *field_34;  // +0x34: this (set by the constructor)
    void *field_38;  // +0x38: the node's next
    void *field_3C;  // +0x3c: the node's prev
    ::app::ui::UIView *field_40;  // +0x40: the parent (GetSuperView)
    // +0x44..+0x4F: the sub-view list (as UIResponder's at +0x4): the count, the end node
    u32 field_44;  // +0x44: the count of sub-views
    void *field_48;  // +0x48: the end node's next
    void *field_4C;  // +0x4c: the end node's prev
    ::gfl2::heap::NwAllocator *field_50;  // +0x50: the constructor's second argument
    ::gfl2::heap::NwAllocator *field_54;  // +0x54: the constructor's third argument
    u8 unk_58[0x8];  // +0x58: the constructor leaves it alone
    ::app::util::G2DUtil *field_60;  // +0x60: made by Initalize2D (0x44 bytes), deleted by Delete2D
    u32 field_64;  // +0x64: 0 at first; nothing seen to read it
    bool field_68;  // +0x68: false at first
    bool field_69;  // +0x69: Initalize2D, Delete2D: a part of the 2D set up was made (a guess)
    bool field_6A;  // +0x6a: as field_69
    bool field_6B;  // +0x6b: as field_69
    bool field_6C;  // +0x6c: visible (SetVisible, IsVisible); true at first
    bool field_6D;  // +0x6d: modal (SetModal); DoInputAction stops at it
    bool field_6E;  // +0x6e: true at first; Update passes it down the tree (a guess: input enabled in the tree)
    bool field_6F;  // +0x6f: true at first; Update updates the G2DUtil only when it is set
    bool field_70;  // +0x70: CreateGraphicsSystem, DeleteGraphicsSystem
    ::gfl2::lyt::MemoryArea field_74;  // +0x74: SetLayoutTransferArea; 0x10000 at first
    void *field_78;  // +0x78: an array of objects with a destructor, freed by __aeabi_vec_delete in Delete2D (the element type is not known)
    ::print::WordSet *field_7C;  // +0x7c: deleted by Delete2D
};

}  // namespace ui
}  // namespace app

#endif
