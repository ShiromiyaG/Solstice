#ifndef DEMOLIB_OBJ_OBJECT_H
#define DEMOLIB_OBJ_OBJECT_H

#include "types.h"
#include "gfl2/math/Vector3.h"

namespace DemoLib {
namespace Obj {

class Object {
public:
    virtual void vf0();  // slot 0, Object:000096CC
    virtual void vf1();  // slot 1, Object:0000DDEC
    virtual void vf2(u32 a1);  // slot 2, Object:0000D65C; the parameters are a guess from its code (types too)
    virtual void vf3();  // slot 3, Object:0000E6CC
    virtual void vf4(const gfl2::math::Vector3 &v);  // slot 4, Object:0000D390; the parameters are from its code (Vector3 by reference proven by the 3-word copy / vldmia; names and exact int widths are guesses)
    virtual void vf5(f32 f0, f32 f1, f32 f2);  // slot 5, Object:0000D3B8; the parameters are a guess from its code (types too)
    virtual void vf6();  // slot 6, Object:0000E6FC
    virtual void vf7(const gfl2::math::Vector3 &v);  // slot 7, Object:0000DD6C; the parameters are from its code (Vector3 by reference proven by the 3-word copy / vldmia; names and exact int widths are guesses)
    virtual void vf8(f32 f0, f32 f1, f32 f2);  // slot 8, Object:0000DD94; the parameters are a guess from its code (types too)
    virtual void vf9(u32 a1);  // slot 9, Object:0000D52C; the parameters are a guess from its code (types too)
    virtual void vf10();  // slot 10, Object:0000E6DC
    virtual void vf11(f32 f);  // slot 11, Object:0000DCBC; the parameters are from its code (Vector3 by reference proven by the 3-word copy / vldmia; names and exact int widths are guesses)
    virtual void vf12(const gfl2::math::Vector3 &v);  // slot 12, Object:0000DC94; the parameters are from its code (Vector3 by reference proven by the 3-word copy / vldmia; names and exact int widths are guesses)
    virtual void vf13(f32 f0, f32 f1, f32 f2);  // slot 13, Object:0000DCD8; the parameters are a guess from its code (types too)
    virtual void vf14(f32 f);  // slot 14, Object:0000DD20; the parameters are from its code (Vector3 by reference proven by the 3-word copy / vldmia; names and exact int widths are guesses)
    virtual void vf15(const gfl2::math::Vector3 &v);  // slot 15, Object:0000DCF0; the parameters are from its code (Vector3 by reference proven by the 3-word copy / vldmia; names and exact int widths are guesses)
    virtual void vf16(f32 x, f32 y, f32 z);  // slot 16, Object:0000DD44; the parameters are from its code (Vector3 by reference proven by the 3-word copy / vldmia; names and exact int widths are guesses)
    virtual void vf17();  // slot 17, Object:0000D4E0
    virtual void vf18(f32 f);  // slot 18, Object:0000D510; the parameters are from its code (Vector3 by reference proven by the 3-word copy / vldmia; names and exact int widths are guesses)
    virtual void vf19(const gfl2::math::Vector3 &v);  // slot 19, Object:0000D4E8; the parameters are from its code (Vector3 by reference proven by the 3-word copy / vldmia; names and exact int widths are guesses)
    virtual void vf20(u32 a1);  // slot 20, Object:0000D3D4; the parameters are a guess from its code (types too)
    virtual void vf21();  // slot 21, Object:0000E704
    virtual void vf22();  // slot 22, Object:0000E6BC
    virtual void vf23(f32 f0, f32 f1, f32 f2);  // slot 23, Object:0000DDD4; the parameters are a guess from its code (types too)
    virtual void vf24(const gfl2::math::Vector3 &v);  // slot 24, Object:0000DDAC; the parameters are from its code (Vector3 by reference proven by the 3-word copy / vldmia; names and exact int widths are guesses)
    virtual void vf25(f32 f);  // slot 25, Object:0000D360; the parameters are from its code (Vector3 by reference proven by the 3-word copy / vldmia; names and exact int widths are guesses)
    virtual void vf26();  // slot 26, Object:0000D588
    virtual void vf27(const gfl2::math::Vector3 &v);  // slot 27, Object:0000D610; the parameters are from its code (Vector3 by reference proven by the 3-word copy / vldmia; names and exact int widths are guesses)
    virtual void vf28(f32 f);  // slot 28, Object:0000D638; the parameters are from its code (Vector3 by reference proven by the 3-word copy / vldmia; names and exact int widths are guesses)
    virtual void vf29(u32 a1);  // slot 29, Object:0000D460; the parameters are a guess from its code (types too)
    virtual void vf30(u32 a1);  // slot 30, Object:0000D64C; the parameters are a guess from its code (types too)
    virtual u8 vf31();  // slot 31, Object:0000E6D4; the return type is a guess from its code
    virtual void vf32();  // slot 32, Object:0000DC90
    virtual s8 vf33();  // slot 33, Object:0000E6C4; the return type is a guess from its code
    virtual void vf34(u32 a1);  // slot 34, Object:0000D374; the parameters are a guess from its code (types too)
    virtual s8 vf35();  // slot 35, Object:0000E6F4; the return type is a guess from its code
    virtual void vf36(u32 a1);  // slot 36, Object:0000DD64; the parameters are a guess from its code (types too)
    virtual s8 vf37();  // slot 37, Object:0000E6EC; the return type is a guess from its code
    virtual void vf38(bool flag);  // slot 38, Object:0000D388; the parameters are from its code (Vector3 by reference proven by the 3-word copy / vldmia; names and exact int widths are guesses)
    virtual void vf39();  // slot 39, Object:0000DC84
    virtual s8 vf40();  // slot 40, Object:0000E6E4; the return type is a guess from its code
    virtual void vf41();  // slot 41, Object:0000D2F0
    virtual void vf42();  // slot 42, Object:0000D2EC
    virtual void vf43(u32 a1, u32 a2, u32 a3);  // slot 43, Object:0000D590; the parameters are a guess from its code (types too)
    virtual void vf44(void *a1, u8 a2, u32 a3, u8 a4, u8 a5);  // slot 44, Object:0000D4BC; the parameters are from its code (Vector3 by reference proven by the 3-word copy / vldmia; names and exact int widths are guesses)
    virtual void vf45();  // slot 45, Object:0000D654
    virtual bool vf46(u32 a1);  // slot 46, Object:0000D454; the parameters are a guess from its code (types too); the return type is a guess from its code
    virtual void vf47(u32 a1);  // slot 47, Object:0000D45C; the parameters are a guess from its code (types too)
    virtual void vf48();  // slot 48, Object:0000D658
    virtual void vf49(u32 a1, u32 a2);  // slot 49, Object:0000D3D0; the parameters are a guess from its code (types too)
    virtual void vf50(u32 a1);  // slot 50, Object:0000D37C; the parameters are a guess from its code (types too)
    virtual void vf51(u32 a1);  // slot 51, Object:0000D380; the parameters are a guess from its code (types too)

    // data members, from how the class's functions use this (tools/fields.py)
    gfl2::math::Vector3 field_4;  // +0x4, a Vector3: set whole by vf slots (copied from a Vector3 &, or Set from three floats); the name is a guess
    gfl2::math::Vector3 field_10;  // +0x10, a Vector3: set whole by vf slots (copied from a Vector3 &, or Set from three floats); the name is a guess
    gfl2::math::Vector3 field_1C;  // +0x1c, a Vector3: set whole by vf slots (copied from a Vector3 &, or Set from three floats); the name is a guess
    gfl2::math::Vector3 field_28;  // +0x28, a Vector3: set whole by vf slots (copied from a Vector3 &, or Set from three floats); the name is a guess
    gfl2::math::Vector3 field_34;  // +0x34, a Vector3: set whole by vf slots (copied from a Vector3 &, or Set from three floats); the name is a guess
    gfl2::math::Vector3 field_40;  // +0x40, a Vector3: set whole by vf slots (copied from a Vector3 &, or Set from three floats); the name is a guess
    u8 field_4C;  // +0x4c, a guess: from 3 functions
    bool field_4D;  // +0x4d, a bool: vf38 stores its argument, and every setter calls vf38(true); the name is a guess
    s8 field_4E;  // +0x4e, a guess: from 2 functions
    s8 field_4F;  // +0x4f, a guess: from 10 functions
    s8 field_50;  // +0x50, a guess: from 3 functions
    u8 unk_51[0x3];  // +0x51: nothing seen to use it
    void *field_54;  // +0x54, a guess: a pointer, from 5 functions
    u8 field_58;  // +0x58, a guess: from 1 function
    u8 unk_59[0x1f];  // +0x59: nothing seen to use it
    u8 field_78;  // +0x78, a guess: from 2 functions
    u8 field_79;  // +0x79, a guess: from 3 functions
    u8 field_7A;  // +0x7a, a guess: from 3 functions
    u8 unk_7B[0x1];  // +0x7b: nothing seen to use it
    void *field_7C;  // +0x7c, a guess: a pointer, from 4 functions
    u8 field_80;  // +0x80, a guess: from 2 functions
    u8 unk_81[0x3];  // +0x81: nothing seen to use it
    u32 field_84;  // +0x84, a guess: from 2 functions
    u8 unk_88[0xc];  // +0x88: nothing seen to use it; the class is at least 0x94 long (a class has its next base there)
};

}  // namespace Obj
}  // namespace DemoLib

#endif
