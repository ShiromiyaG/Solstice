#ifndef GAMESYS_GAMEEVENT_H
#define GAMESYS_GAMEEVENT_H

#include "types.h"

namespace GameSys { class GameManager; }
namespace gfl2 { namespace heap { class CtrHeapBase; } }
namespace nn { namespace ro { class Module; } }

namespace GameSys {

// what slot 4 returns. the event's step (code.bin:00408590) ends the event on 1 and hands any
// other value back to GameEventManager (code.bin:00404350), which runs the next event at once
// on 0x21. the names of the type and of its values are guesses
enum GameEventResult {
    GAMEEVENT_RES_CONTINUE = 0,
    GAMEEVENT_RES_FINISH = 1,
    GAMEEVENT_RES_CONTINUE_DIRECT = 0x21
};

class GameEvent {
public:
    GameEvent(::gfl2::heap::CtrHeapBase *pHeap);  // code.bin:00408654
    virtual ~GameEvent();  // code.bin:00408684: not inline (the events' destructors call it)
    // the step (code.bin:00408590) calls slots 2 to 5 with the GameManager it is given. their names
    // are not known: what each does is from the step
    virtual bool vf2(::GameSys::GameManager *pGameManager) = 0;  // slot 2: may the event start (the step waits until true)
    virtual void vf3(::GameSys::GameManager *pGameManager) = 0;  // slot 3: once, when it starts
    virtual GameEventResult vf4(::GameSys::GameManager *pGameManager) = 0;  // slot 4: every frame until it returns 1
    virtual void vf5(::GameSys::GameManager *pGameManager) = 0;  // slot 5: once, at the end
    virtual bool vf6();  // slot 6, code.bin:0040864C; the return type is a guess from its code (it returns true)

    // data members (offsets checked)
    ::GameSys::GameEvent *field_4;  // +0x4: the event below it (GameEventManager::CallEvent pushes, ChangeEvent hands it over)
    u32 field_8;  // +0x8, a guess: from 49 functions
    ::gfl2::heap::CtrHeapBase *field_C;  // +0xc: the heap the constructor is given
    u32 field_10;  // +0x10: the step's state: 0 not started, 1 running, 2 ended (code.bin:00408590)
    ::nn::ro::Module *field_14;  // +0x14: a module GameEventManager disposes of after deleting the event (code.bin:00404350)
};

}  // namespace GameSys

#endif
