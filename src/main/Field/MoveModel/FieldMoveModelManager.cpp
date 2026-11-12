#include "Field/MoveModel/FieldMoveModelManager.h"

namespace Field {
namespace MoveModel {

//! 0x003B5B58 GetFieldSubobjectIndexFromFreeSpace
u32 FieldMoveModelManager::GetFieldSubobjectIndexFromFreeSpace()
{
    for (u32 i = 1; i < 10; i++) {
        u8 *obj = *(u8 **)((u8 *)this + i * 4 + 0x98);
        if (*(u32 *)(obj + 0x88) == 0) {
            return i;
        }
    }
    return 10;
}

}  // namespace MoveModel
}  // namespace Field
