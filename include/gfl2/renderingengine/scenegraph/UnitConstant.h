#ifndef GFL2_RENDERINGENGINE_SCENEGRAPH_UNITCONSTANT_H
#define GFL2_RENDERINGENGINE_SCENEGRAPH_UNITCONSTANT_H

// a constant that the static initializer of over a thousand files of the game sets first:
// 40 degrees in radians, computed by an inline function. which header it comes from is a
// guess, kept here until the real one is known. the names are ours.

#include "types.h"

inline f32 ConvDegToRad(f32 deg) { return deg * 3.14159265f / 180.0f; }

static const f32 s_Angle40 = ConvDegToRad(40.0f);

#endif
