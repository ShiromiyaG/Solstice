# Contributing

## Setup

0. **The repository**, with the tools (a submodule in `tools/`):

   ```sh
   git clone --recursive https://github.com/Tsukimi-Labs/Solstice.git
   # or, in a clone made without it: git submodule update --init
   ```

1. **The game.** Your own copy of Ultra Sun (USA) with update v1.2, decrypted
   and extracted, in `orig/us-v1.2/` (sources are checked against it; Ultra
   Moon, the same way in `orig/um-v1.2/`, is needed for `tools/versions.py`
   and to check against it, `MATCH_VERSION=um-v1.2`):

   ```
   orig/us-v1.2/exheader.bin
   orig/us-v1.2/exefs/code.bin     SHA-256 421774f2e5e2076b4b09a6f761b2826a99f01900c23655f8588fcd25ce16200f
   orig/us-v1.2/romfs/*.cro        the 132 modules, and static.crs
   ```

   These are the update's program files (`code.bin` and `exheader.bin` from
   the update, `romfs/` from the game with the update applied).

2. **The compiler.** ARMCC 4.1 build 1049. It is one of the builds of
   [decompme/compilers](https://github.com/decompme/compilers): unpack
   `armcc.zip` of its `compilers` release into `toolchain/armcc/`, so that
   `toolchain/armcc/4.1/b1049/bin/armcc.exe` exists. That is the default;
   `MATCH_CC` or `--cc` names another build, for experiments only.

   Flags, in `project.toml`: `--cpu=MPCore --arm --fpmode=fast
   --apcs=/interwork -O3 -Otime --split_sections --data_reorder
   --signed_chars --wchar16 --multibyte_chars
   --no_allow_fpreg_for_nonfpdata`. `char` is signed.

   How they were found: by test, with `tools/match.py sweep`, which compiles
   one source under every build and flag set and compares with the game.
   - The version: sources that match with 4.1 (static initializers of 704
     and 1,564 bytes, thousands of small functions) do not with 4.0 or 5.04.
     The 4.1 builds tried agree with each other on those; b1049 is the one
     used.
   - `-O3 -Otime`: `-O2` and `-Ospace` give code of another size.
   - `--split_sections`: the game's functions lie in the order of their
     mangled names, which is how the linker orders one section per function.
   - No exceptions, no RTTI data in the code: a matched initializer grows by
     8 words with `--exceptions`.
   - `--no_allow_fpreg_for_nonfpdata` rests on one function that does not
     match yet: the least certain of them.

3. **Python 3.10+** with `capstone` (`pip install capstone`). Run every tool
   with `python -I`, from the repository's root. Windows for now: the tools run
   `armcc.exe` directly.

4. **What the tools derive.** `python -I tools/refresh.py --derive` writes, from
   your copy of the game, the sources that are not kept in git
   (`src/<program>/generated/`) and checks everything; the first run takes
   minutes. `python -I tools/progress.py` should then give the count in
   `docs/history.csv`.

If you work with an AI agent: `tools/CLAUDE.md` says how to set all this up,
`CLAUDE.md` how to work in this repository, and `AGENTS.md` how to write sources
(give it whole to every agent that writes them); the rules here apply to what it
writes.

Nothing under `orig/`, `toolchain/` or `build/` is ever committed.

## The loop

```sh
python -I tools/match.py show 0x003D6790                       # read the function (imports and pool named)
python -I tools/match.py check src/main/GameSys/Display.cpp 0x003D6790 --sym RenderDisplay
python -I tools/progress.py src/main/GameSys                   # all functions of a folder
python -I tools/honest.py                                      # tricks in the sources
python -I tools/status.py                                      # redraw docs/status.svg
```

An address is `0x003D6790` in `code.bin`, or `Battle:0x4F508` in a module
(the offset in its file). `config/us-v1.2/functions.csv` has every function's
start, end and, where known, name. `classes.csv` has the classes the game
names in its type information, with their bases, and `vtables.csv` each
class's virtual functions by slot: look a function up there before naming it.
In `functions.csv`, `class`, `slot` and `method` say which virtual of which
class a function is, and `library` whose code it is: only `game` and `gfl2`
are decompiled here; `sdk`, `nw`, `middleware` and `armlib` are libraries.

`check` answers:

| Result | Meaning |
| --- | --- |
| `MATCH` | every byte equal, every call and address checked, the size is the game's. Counts |
| `HACK` | the bytes are equal but the source uses a trick. Does not count |
| `MATCH?` | equal, but a call or address could not be checked (a symbol with no address) |
| `DIFFER` | prints the words that differ, the game's first |

`MATCH_VERSION=um-v1.2` before a command compares with Ultra Moon: the address is
still Ultra Sun's, found in Ultra Moon through `config/um-v1.2/map.csv`
(`tools/versions.py`), and so is every call and address the check follows.
`tools/refresh.py` checks every source against both.

## Writing a source

- One line above each function says where it is and how to find it in the
  object: `//! 0x003D6790 RenderDisplay`.
- Something without a name yet carries its address: `sub_003D6790` (a
  function of `code.bin`), `f_Battle_00000FE0` (of a module),
  `data_006A5998`. The check compares that address with the game's. A name we
  give goes in `config/us-v1.2/symbols.txt` (`name = 0x003D6790`).
- Write from what the function does, with real types in `include/`. Code
  transcribed from the instructions or pasted from a decompiler does not
  converge on larger functions.
- **File and function names do not change the bytes.** Name and place things
  as the original most likely had them (the game's exported names in
  `functions.csv` give classes and namespaces); there is nothing to match in
  a file's name. What a file *contains* does matter: functions of one file
  see each other's inline bodies, so put together what was together.
- Every class the game names has a header, `include/<namespace>/<Class>.h`,
  with its bases and its virtual functions in vtable order (`vfN` where the
  name is not known, `void name()` for every signature). When you give one
  real signatures or members, remove its first line (`// generated by
  tools/headers.py`) so the tool stops rewriting it, and keep the slot order.
- Many functions are twins: the same code with other constants or addresses
  (`python -I tools/twins.py` lists the families in `build/us-v1.2/twins.txt`,
  largest first). Write one, run `tools/progress.py`, then
  `python -I tools/twins.py --apply`: the rest of the family is written from
  yours and kept where it matches.
- Sources are by program: `src/main/` for the executable, `src/<Module>/` for a module, then
  by namespace (`src/main/gfl2/Fade/FadeManager.cpp`). `units/unit_<address>.cpp` is a
  translation unit of the game already found (by its static initializer): a function that
  belongs to that unit goes in its file, which can then be renamed after what it holds.
- `generated/` is the tools', made on your machine and never committed. A function there
  that you give a real source moves to your file; the tools skip what is written elsewhere.
  To add to a unit file of `generated/units/`, move it to `units/` first and remove its
  `written by` line: then it is yours.
- C++ as the game: `this` in r0, constructors and destructors return `this`.
  A function that returns a class by value (a vector) gets the place for the
  result in r0 and `this` in r1.
- A function that is not the same code in the two versions (`differs` in
  `config/um-v1.2/map.csv`) is written once, with `#if GAME_VERSION ==
  VERSION_ULTRA_SUN` or the value `GAME_VERSION` (`include/version.h`; the
  tools pass it to the compiler). It must match both. No other `#if` belongs
  in a source (`tools/honest.py` counts one as a trick).
- Enums: a type the game passes by value that is not a class is an enum
  (`tools/enums.py`, `config/us-v1.2/enums.csv`). Its size is what its callers
  narrow it to before a call; its header has two placeholder values that give
  it that size, since the real values are not known. Name the real values in
  your own header when you know them, keeping the size.
- A return type in a generated header is `void` unless something showed it:
  `config/us-v1.2/returns.csv` (people), the function's own code, or its
  callers (`tools/callers.py`: dereferenced, passed as `this` of a class,
  tested, read from `s0`...). The last two say they are guesses; correct one
  in `returns.csv` with what proved it.
- Thumb code (`mode` thumb in `functions.csv`; library code, mostly) is
  compared half word by half word; the source needs a Thumb flag set.
- The linker inlined calls: where the game has `mov r0, r0` (or one plain
  instruction) in place of a call, the source makes the call, to a function
  that only returns (an assert, `__cxa_guard_release` of a static local, an
  empty destructor) or is that one instruction. A tail call to the function
  right after is a `mov r0, r0` too. `match.py` checks the callee at its
  address, so name it.

## Honest matches

A source can reach the bytes with constructs the original never had. Such a
match teaches nothing and hides that a header or a flag is still wrong, so it
is not accepted. `tools/honest.py` looks for:

| | |
| --- | --- |
| `weak` | `__attribute__((weak))`, `__weak`, `#pragma weak` (stops a tail call) |
| `barrier` | `__schedule_barrier()` |
| `vtable` | a vtable's address stored by hand (`data_...` at a vtable, `_ZTV...`): declare the class with its virtual functions |
| `asm` | inline or embedded assembly, asm labels, `__svc` |
| `volatile` | forces loads and stores |
| `mask` | `& 0xffffffff` and the like |
| `dummy` | locals never used or only set |
| `same-arms` | the same code in both arms of an `if` |
| `goto`, `do-while-0` | forced block order |
| `pragma`, `noinline` | code generation changed for part of a file |
| `flags` | a compiler or flags of its own for one function |

- Flags belong to a library, not to a function. A flag set enters
  `config/us-v1.2/flagsets.txt` when a whole library matches better with it.
- A real exception (a hardware register that is volatile, a system call)
  is a line of `config/us-v1.2/honest_allow.txt`, decided by the maintainer.
- A function that will not match honestly stays `DIFFER`, with a comment of
  what was tried. That is a fine contribution.

## What not to bring

- Bytes, assembly, data tables, text or assets of the game.
- Anything you did not write yourself from your own copy of the game and public
  knowledge.
- A decompiler's output as source.
- The compiler.

## Pull requests

- `python -I tools/progress.py` and `python -I tools/honest.py` pass on what
  you touch; say the count before and after.
- Do not change `tools/`, `config/` or existing header fields in the same
  request as sources; propose those apart, with the reason.
