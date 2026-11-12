#include "App/BattleRoyalResult/BattleRoyalResultProc.h"

// the type of field_28 is not known (a pointer in the header): a guess, an interface whose slot 4 returns a value.
// slots 0 and 1 are the destructor, 2 and 3 are two other functions, 4 is the one called.
class BattleRoyalResultIface_guess {
public:
    virtual ~BattleRoyalResultIface_guess();
    virtual void f0();
    virtual void f1();
    virtual int f2() = 0;
};

//! BattleRoyalResult:0x000003C8 UpdateFunc
::gfl2::proc::Result App::BattleRoyalResult::BattleRoyalResultProc::UpdateFunc(::gfl2::proc::Manager *) {
    return ((BattleRoyalResultIface_guess *)field_28)->f2() != 0 ? ::gfl2::proc::RES_FINISH : ::gfl2::proc::RES_CONTINUE;
}
