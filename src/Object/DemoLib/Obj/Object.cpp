#include "DemoLib/Obj/Object.h"

namespace DemoLib {
namespace Obj {

//! Object:0x0000D360 vf25
void Object::vf25(f32 f)
{
    field_1C.y = f;
    vf38(true);
}

// open: the game copies the Vector3 one word at a time through r3 (ldr/str, ldr/str, ldr/str);
// Vector3's implicit operator= gives ldrd/strd + ldr/str. Tried: the implicit copy, member by
// member (vldr/vstr), and in a probe a base struct, an array, a union, a user copy constructor,
// a memcpy operator= (all ldrd). Only a copy through u32 gives the game's words, so the game's
// Vector3 likely has an operator= (or a type) that include/gfl2/math/Vector3.h does not have yet.
//! Object:0x0000D390 vf4
void Object::vf4(const gfl2::math::Vector3 &v)
{
    field_4 = v;
    vf38(true);
}

//! Object:0x0000D4BC vf44
void Object::vf44(void *a1, u8 a2, u32 a3, u8 a4, u8 a5)
{
    field_7C = a1;
    field_80 = a2;
    field_84 = a3;
    field_79 = a4;
    field_7A = a5;
}

// open: the game copies the Vector3 one word at a time through r3 (ldr/str, ldr/str, ldr/str);
// Vector3's implicit operator= gives ldrd/strd + ldr/str. Tried: the implicit copy, member by
// member (vldr/vstr), and in a probe a base struct, an array, a union, a user copy constructor,
// a memcpy operator= (all ldrd). Only a copy through u32 gives the game's words, so the game's
// Vector3 likely has an operator= (or a type) that include/gfl2/math/Vector3.h does not have yet.
//! Object:0x0000D4E8 vf19
void Object::vf19(const gfl2::math::Vector3 &v)
{
    field_40 = v;
    vf38(true);
}

//! Object:0x0000D510 vf18
void Object::vf18(f32 f)
{
    field_40.x = f;
    field_40.y = f;
    field_40.z = f;
    vf38(true);
}

// open: the game copies the Vector3 one word at a time through r3 (ldr/str, ldr/str, ldr/str);
// Vector3's implicit operator= gives ldrd/strd + ldr/str. Tried: the implicit copy, member by
// member (vldr/vstr), and in a probe a base struct, an array, a union, a user copy constructor,
// a memcpy operator= (all ldrd). Only a copy through u32 gives the game's words, so the game's
// Vector3 likely has an operator= (or a type) that include/gfl2/math/Vector3.h does not have yet.
//! Object:0x0000D610 vf27
void Object::vf27(const gfl2::math::Vector3 &v)
{
    field_28 = v;
    vf38(true);
}

//! Object:0x0000D638 vf28
void Object::vf28(f32 f)
{
    field_28.y = f;
    vf38(true);
}

// open: the game copies the Vector3 one word at a time through r3 (ldr/str, ldr/str, ldr/str);
// Vector3's implicit operator= gives ldrd/strd + ldr/str. Tried: the implicit copy, member by
// member (vldr/vstr), and in a probe a base struct, an array, a union, a user copy constructor,
// a memcpy operator= (all ldrd). Only a copy through u32 gives the game's words, so the game's
// Vector3 likely has an operator= (or a type) that include/gfl2/math/Vector3.h does not have yet.
//! Object:0x0000DC94 vf12
void Object::vf12(const gfl2::math::Vector3 &v)
{
    field_34 = v;
    vf38(true);
}

//! Object:0x0000DCBC vf11
void Object::vf11(f32 f)
{
    field_34.x = f;
    field_34.y = f;
    field_34.z = f;
    vf38(true);
}

// open: the game loads v.x first (vldmia r1!), then z, y, x of field_34, then v.y, v.z, and
// stores z alone and x, y with vstmia. Tried: member by member *=, Set(x * v.x, ...), and in a
// probe a Vector3 operator*= and a Mul(dst, a, b) helper. Likely a Vector3 operator the
// header lacks.
//! Object:0x0000DCF0 vf15
void Object::vf15(const gfl2::math::Vector3 &v)
{
    field_34.Set(field_34.x * v.x, field_34.y * v.y, field_34.z * v.z);
}

// open: the game computes this + 0x34 twice (r1 the destination, first; r0 the source) and
// stores z alone, then x, y. Tried: *= per member, Set(x * f, ...), = Vector3(...), and in a
// probe operator*=(f32) and Mul(dst, src, f). Likely a Vector3 operator (dst and src both
// field_34) the header lacks.
//! Object:0x0000DD20 vf14
void Object::vf14(f32 f)
{
    field_34.Set(field_34.x * f, field_34.y * f, field_34.z * f);
}

// open: 2 words differ, r0 and r1 swapped (the game loads through r0 and stores through r1,
// both this + 0x34). Tried: *= per member, = Vector3(...) (goes through integer registers),
// and in a probe Mul(dst, src, Vector3(x, y, z)); same swap.
//! Object:0x0000DD44 vf16
void Object::vf16(f32 x, f32 y, f32 z)
{
    field_34.Set(field_34.x * x, field_34.y * y, field_34.z * z);
}

// open: the game copies the Vector3 one word at a time through r3 (ldr/str, ldr/str, ldr/str);
// Vector3's implicit operator= gives ldrd/strd + ldr/str. Tried: the implicit copy, member by
// member (vldr/vstr), and in a probe a base struct, an array, a union, a user copy constructor,
// a memcpy operator= (all ldrd). Only a copy through u32 gives the game's words, so the game's
// Vector3 likely has an operator= (or a type) that include/gfl2/math/Vector3.h does not have yet.
//! Object:0x0000DD6C vf7
void Object::vf7(const gfl2::math::Vector3 &v)
{
    field_10 = v;
    vf38(true);
}

// open: the game copies the Vector3 one word at a time through r3 (ldr/str, ldr/str, ldr/str);
// Vector3's implicit operator= gives ldrd/strd + ldr/str. Tried: the implicit copy, member by
// member (vldr/vstr), and in a probe a base struct, an array, a union, a user copy constructor,
// a memcpy operator= (all ldrd). Only a copy through u32 gives the game's words, so the game's
// Vector3 likely has an operator= (or a type) that include/gfl2/math/Vector3.h does not have yet.
//! Object:0x0000DDAC vf24
void Object::vf24(const gfl2::math::Vector3 &v)
{
    field_1C = v;
    vf38(true);
}

}  // namespace Obj
}  // namespace DemoLib
