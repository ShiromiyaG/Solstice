# Rules for agents that write matching sources

You are given functions of Ultra Sun (addresses) and must write C++ that the game's compiler
turns into the same bytes. The compiler is the judge, not you. These rules are for people too.

Setting up comes first (`CONTRIBUTING.md`, `tools/CLAUDE.md`): without the person's own copy of
the game in `orig/` and the compiler in `toolchain/`, nothing can be checked; say so and stop.

## What you may use

- Run `tools/match.py` (`show`, `check`) and nothing else: the other tools rewrite files every
  agent shares (headers, generated sources, the table).
- Read your packet, `include/`, `src/`, and `config/us-v1.2/` (`functions.csv`, `symbols.txt`).
  Nothing from outside the workspace. Without a packet, the same comes from `match.py show`,
  the function's row in `functions.csv` (its class, slot and name) and its class's header.
- Run `match.py check` in the foreground and read its `RESULT` (a check takes seconds).

## The loop

1. Read the function: `python -I tools/match.py show <where> <words>`. The packet already says
   how it is declared (`declared:`, with the header), its `//!` line, and what it calls with
   names and declarations: start from those rather than searching. A decompiler's C, when a
   packet has it, says what the function does; it is never a draft to edit into a match.
2. Write it in `src/main/<namespace>/<File>.cpp` (the executable) or
   `src/<Module>/<namespace>/<File>.cpp` (a module), with a line above each function:
   `//! <where> <symbol or part of it>`. Never write in a `generated/` folder: it is the
   tools', and is not kept.
3. Check: `python -I tools/match.py check <file> <where> --sym <symbol>`.
4. `RESULT: MATCH` is the only success. On `DIFFER`, read the words (the game's first), change
   the source, check again.
5. Stop after 8 checks without progress. Leave the best source, with a comment of what differs
   and what you tried, and report it as open.

Report one line per function: `<where> <status> <file>`. Nothing else, except what you found
wrong in a header (see "Headers").

### The `//!` line

- It names the function right below it, not something that function calls.
- It holds, on that one line, the `<where>` with its module (`Battle:0x...`; a bare address is
  code.bin) and the symbol you passed to `--sym`: the mangled name or a part of it (`vf2`,
  `EndFunc`, `BaseProcessD1Ev` for a destructor: D1 the complete one, D0 the deleting one), never
  a demangled `Class::name` or `~Class`. The packet gives the line to use. Without it the
  function counts as an error.
- A module's function without a name is `f_<Module>_<offset>`, a code.bin one `sub_<address>`.

## Writing

- From what the function does, with the classes in `include/`. Do not transcribe the
  instructions and do not paste a decompiler's output: C shaped like the machine code does not
  converge.
- Names: a callee or a global without a name is `sub_003D6790`, `data_006A5998`,
  `f_Battle_00000FE0` (the address is checked against the game's). Use real names where
  `functions.csv` or `symbols.txt` has them.
- What usually moves the bytes: the order of declarations (stack slots), a temporary against a
  named local, the type's width and sign, `if`/`else` order, a helper inlined or called, a member
  function against a free one, arguments evaluated in a different order.
- A function in a secondary base's vtable (its packet says "a thunk"): write the override the
  class's header declares (`// overrides <Base>'s slot n`), as an ordinary member function, and
  check it with the `--sym` the packet gives (`_ZThn<n>_N...`). The compiler makes the thunk;
  never compute `this` by hand.
- The members a function uses are often its bases': the packet lists those at the offsets it
  loads and stores, with the class that declares each. Use them; a member really missing is
  reported, not added to a generated header.
- C++ as the game: no RTTI, no exceptions, `this` in r0, constructors and destructors return
  `this`. Floats are passed in s0... (VFP registers).
- Objects are built and destroyed as C++ does it, never by hand. A class with virtual functions
  is declared with them; the compiler stores its vtable (`match.py` checks `_ZTV<class>` against
  the game's, so the class must have its real name). A member or base built by a constructor is
  a member or base with a constructor. An object is made with `new (heap) T(args)`.
- `mov r0, r0` in the game's code is a call the linker removed: to a function that only returns
  (an assert, a static local's guard release, an empty destructor, a getter that returns
  `this`), or a tail call to the function right after. Write the call, to its callee by name
  (`sub_<address>` of a function that is only `bx lr`, or of the next function); `match.py`
  accepts it there and nowhere else. A call to a one-instruction function can also be that
  instruction.
- `nop` (`E320F000`) just before a branch is the compiler's own: the right source gives it by
  itself. Never write `__nop()` for it.
- A function returns `void` unless its own code sets r0 for the caller or a caller uses the
  result. Do not give it a return type because r0 happens to still hold `this`.

### Headers

- A field read through a pointer needs a struct in `include/`; add the field at its offset rather
  than casting. Many headers have members `field_<offset>` and gaps `unk_<offset>[n]` generated
  from how the class's functions use `this`: offset and width are checked, name and type are
  guesses. Use them as they are.
- If a function proves a better type (a pointer to a class, a `bool`, an array where a gap is),
  say so in your report instead of changing the header: generated headers are rewritten. A
  member whose generated type is wrong (`u32` or `void *` where the code uses a pointer to a
  class) may be cast to the type the code shows, with a comment that the cast stands for the
  member's real type; the header is fixed later from your report. A virtual called through a
  vtable read by hand is the same: say in a comment which class and slot it stands for.
- Headers declare the member functions the game names, with their parameters. A return type is
  `void` unless the code showed it (then the line says it is a guess); if a function you need
  returns something else, say which and what in your report.
- A virtual function's parameters that no name gives are in the header as `u32 a1, ...` and
  `f32 f0, ...` (from what its versions read): the number is right, the types are a guess; keep
  the count, and report a better type if the code shows one.
- You may add to a header. Do not change its existing fields or inline bodies.

## Versions

Ultra Sun and Ultra Moon are one program built twice. A `//!` address is always Ultra Sun's;
`MATCH_VERSION=um-v1.2 python -I tools/match.py check ...` compares the same source with Ultra
Moon. Almost every function is the same code in both. A packet says when one is not, and shows
Ultra Moon's code: then the source must match both, and the difference is written with
`GAME_VERSION` and the names of `include/version.h`:

```cpp
#include "version.h"
#if GAME_VERSION == VERSION_ULTRA_SUN
    return IsFileOpen(101);
#else
    return IsFileOpen(102);
#endif
```

or `GAME_VERSION` as a value (`return GAME_VERSION;`). This is the one `#if` that is not a
workaround: the game itself was built twice from one source. It is only for what differs between
the versions' code, never to make one version match. Report such a function as `MATCH` only when
both checks say `MATCH`.

## No workarounds

The goal is the source the game was built from, not any text that happens to pass. A
workaround is anything written to get past the check instead of to be right. None is accepted:

- No code whose only reason is the compiler's output: a cast, a temporary, a reordering or an
  extra statement that the logic does not need and you cannot explain as something a
  programmer would have written.
- No special case for one function: no `#if` (except `GAME_VERSION`), no macro, no helper, no
  header variant that exists to make a single function match.
- No copy of a class or a declaration bent for one caller. If a header is wrong, it is wrong for
  everyone: report it.
- No touching the judge: do not edit `tools/`, `config/`, `honest_allow.txt` or `flagsets.txt`,
  do not pass other flags or another compiler, do not change a `//!` line to point somewhere
  easier, do not delete or skip a function that fails.
- No reporting what did not happen. `MATCH` is what `match.py` printed for the file as you left
  it, on the last run. A near match is `DIFFER`.
- No guessing dressed as knowledge: a name, a type or a field you made up is marked as a guess in
  a comment.

When the honest source does not match, stop and say what differs. That result is useful: it
points at a wrong header, a wrong flag or the wrong compiler. A forced match hides it and has to
be found and undone later.

## Forbidden

A source that reaches the bytes by one of these is `HACK` and is thrown away (`tools/honest.py`
catches them; something not on the list is still a workaround if it fits the section above):

- `__attribute__((weak))`, `__weak`, `#pragma weak`
- `__schedule_barrier`
- inline or embedded assembly, asm labels, `__svc`
- `volatile`
- locals that are never used or only set
- `& 0xffffffff` and other no-op operations
- the same code in both arms of an `if`
- `goto`, `do { } while (0)`
- `#pragma` that changes code generation, `__declspec(noinline)`
- `cc=` or `flags=` on the `//!` line, unless told the library's flag set
- a vtable's address stored by hand (`*(u32 *)this = (u32)data_...`, `_ZTV...`): declare the
  class with its virtual functions
- `this` computed from a constructor's result (`(u8 *)ctor_result - 0x18`), `operator new`
  followed by a call to the constructor

Also forbidden: editing `config/`, `tools/`, or another function's source. No game bytes, tables
or assembly in a file.

If a function seems to need a trick, say which and stop: many functions needing the same one
means a flag or a header is wrong, and that is fixed once, not per function.
