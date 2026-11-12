#include "App/MantainSurf/MantainSurfProc.h"

void f_MantainSurf_00002F80(void *a1);

namespace App {
namespace MantainSurf {

//! MantainSurf:0x00000E58 PreDrawFunc
void MantainSurfProc::PreDrawFunc(::gfl2::proc::Manager *) {
    if (field_4C) {
        f_MantainSurf_00002F80(field_40);
    }
}

}  // namespace MantainSurf
}  // namespace App
