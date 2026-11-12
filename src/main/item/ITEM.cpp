#include "types.h"

namespace item {

//! 0x00376EDC ITEM_CheckPokeAdd
int ITEM_CheckPokeAdd(int a1) {
    return !(a1 == 499 || a1 == 500);
}

}  // namespace item
