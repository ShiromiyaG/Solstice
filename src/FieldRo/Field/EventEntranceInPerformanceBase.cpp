#include "Field/EventEntranceInPerformanceBase.h"

namespace Field {

// the packet names EventEntranceInPerformanceMAT, but the code stores this class's vtable
// and calls GameSys::GameEvent's D2: it is the base's deleting destructor
//! FieldRo:0x00031C7C _ZN5Field29EventEntranceInPerformanceMAT30EventEntranceInPerformanceBase
EventEntranceInPerformanceBase::~EventEntranceInPerformanceBase() {
}

}  // namespace Field
