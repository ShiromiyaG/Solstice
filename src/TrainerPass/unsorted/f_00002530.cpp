#include "types.h"
#include "App/TrainerPass/PlayData.h"

//! TrainerPass:0x00002530 f_TrainerPass_00002530
extern "C" void f_TrainerPass_00002530(u8 *a1, u8 *a2, int a3, int a4) {
    *(u8 **)(a1 + 0x1c) = a2;
    *(int *)(a1 + 0x20) = a3;
    *(int *)(a1 + 0x24) = a4;
    if (*a2 == 0) {
        App::TrainerPass::PlayData *pd = *(App::TrainerPass::PlayData **)(a1 + 0x28);
        *(u16 *)(a1 + 0x38) = pd->GetStampPage();
    }
}
