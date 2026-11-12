# Ultra Sun / Ultra Moon matching decomp: instructions for AI agents

Source that armcc turns into the game's bytes, function by function. Targets: Ultra Sun and
Ultra Moon USA, update v1.2. Checked against Ultra Sun (`orig/us-v1.2`, `code.bin` SHA-256
`421774f2…200f`); Ultra Moon (`orig/um-v1.2`, `8854abc9…084a`) is the same program built twice
(see "Versions" below).

- Setting up (the game, the compiler, Python, the first `refresh.py --derive`): `CONTRIBUTING.md`,
  and `tools/CLAUDE.md` for the tools' side.
- Writing sources, for people and agents alike: `AGENTS.md`. Give it whole to every agent that
  writes sources.
- For people: `README.md`, `CONTRIBUTING.md`.
- License: `LICENSE`, CC0 1.0 (what is written here; it gives no right to the game). The tools:
  MIT, in their own repository.

## Rules

- What feeds the decomp: your own copy of the game (`orig/`), what the tools derive from it, the
  compilers of decomp.me's set, and public tools. Nothing else feeds `config/`, `src/`,
  `include/` or `docs/`. A new source of information is the maintainers' call.
- Nothing of the game in the repository: no bytes, assembly, assets or tables; no compiler.
  Addresses, sizes and names are fine. A decompiler's C of the game (m2c, Hex-Rays, Ghidra)
  stays in `build/` or out of the workspace: a reference, never a draft.
- The repository holds only sources people wrote. Everything a tool writes under `src/` goes
  to `src/<program>/generated/`, ignored by git and remade by `refresh.py --derive` from each
  person's copy of the game. A tool never writes elsewhere in `src/` (`copies.py` only copies a
  person's source to another program, unchanged but for its `//!` addresses).
- Matched means `match.py` says `MATCH`. Never report a match from reading the diff. `HACK`,
  `MATCH?` and `DIFFER` are not matches.
- No tricks and no workarounds, in sources or tools (`AGENTS.md`, "No workarounds";
  `tools/honest.py`): nothing written only to get past a check, no special case for one
  function, no weakening of the judge. A function that will not match honestly stays open, with
  what was tried.
- `config/us-v1.2/honest_allow.txt` and `flagsets.txt` are the maintainers': propose, do not
  edit.
- Only `game` and `gfl2` (and unknown) functions are to be decompiled; `sdk`, `nw`, `middleware`,
  `armlib` are library code (the `library` column of `functions.csv`; a `?` is inferred, by
  position or because only that library calls it).
- Commit or push only when the person you work for asks.
- Docs in English.

## Running agents

Give each agent `AGENTS.md` whole, its functions as `<where>` lines (a packet:
`tools/local/packets.py`), and nothing it does not need. Agents run `match.py` only: tell them
so. Pass a model and an effort on every agent, as this table says (measured on this project):

| Work | Model | Effort | Per agent |
| --- | --- | --- | --- |
| Functions of 17 to 64 bytes | haiku | low | 10 to 12 functions |
| Functions of 65 to 256 bytes | haiku | medium | 10 to 15 functions |
| Functions of 257 to 1024 bytes | opus | medium | 1 to 3 functions |
| The head of a twin family (top of `build/us-v1.2/twins.txt`) | opus | medium | 1 function |
| Class headers: members, real signatures, inline bodies | opus | medium | 1 class and its users |
| Functions over 1024 bytes | opus | medium | 1 function |

- Escalate one step, never more, and only what failed: haiku low -> haiku medium -> opus medium.
  Never start a batch on a stronger model "to be safe". What Opus at medium leaves open stays
  open.
- Low effort for the small ones: the compiler is the judge, so a wrong try costs one compile.
  Haiku against Sonnet was measured twice: Haiku stays.
- A decompiler's C in the packets did not help (two A/B tests): `packets.py` leaves it out
  unless `--decompiler` or `--m2c` is given.
- Tokens: mechanical steps first (generators, twins), cheap models for small functions, Opus
  for headers and what resists.
- Read agents' reports on headers: a wrong member type or a missing parameter they report is
  fixed once in the tool or the header and pays for many functions.
- Check what agents hand back: a source that reached the bytes by a trick is thrown away even
  when `honest.py` misses it (a vtable stored by hand, `this` computed from a constructor's
  result, `operator new` then the constructor).
- After any batch: `progress.py`, `twins.py --apply` (their twins for free), `progress.py`
  again, `honest.py`, `status.py` (or `refresh.py`, which runs them). Pick what to write from
  the top of `build/us-v1.2/twins.txt`: one source there gives a whole family.

## Commands (always `python -I`, from this folder)

```sh
python -I tools/match.py show 0x003D6790 40          # the game's code (Battle:0x4F508 for a module; Thumb too)
python -I tools/match.py check <source> <where> [--sym NAME]
python -I tools/match.py sweep <source> <where>      # every compiler x flag set
MATCH_VERSION=um-v1.2 python -I tools/match.py check ...   # against Ultra Moon (also progress.py)
python -I tools/refresh.py [--derive|--table]        # the chain: after sources / after a tool or config change / after the table
python -I tools/progress.py [--all] [folder]         # every //! function (cached); report.json
python -I tools/status.py                            # docs/status.svg, docs/history.csv
python -I tools/honest.py                            # sources that use a trick
python -I tools/tiny.py [--max 64] [--module NAME]   # generated small functions (src/<program>/generated)
python -I tools/structors.py [--module NAME] [--dry]  # destructors and default constructors from the headers (generated/dtors_*.cpp)
python -I tools/twins.py [--apply]                   # families of twins (build/us-v1.2/twins.txt)
python -I tools/copies.py [--apply]                  # a matched member function at its copies in other programs
python -I tools/units.py                             # unit files from the static initializers
python -I tools/functable.py [--census]              # config/us-v1.2/functions.csv (needs the Ghidra server)
python -I tools/tailstarts.py [--apply]              # starts hidden by a tail call made a NOP
python -I tools/unreached.py [--apply]               # starts hidden after code the function before never reaches
python -I tools/bounds.py [--check]                  # bounds.csv: the scope of unnamed functions
python -I tools/rtti.py                              # classes.csv, vtables.csv from the game's RTTI
python -I tools/ctors.py                             # ctors.csv: who writes each vtable
python -I tools/classify.py                          # class, slot, method, library into functions.csv
python -I tools/fields.py                            # fields.csv: data members, from how functions use this
python -I tools/enums.py                             # enums.csv: enums passed by value, size from the callers
python -I tools/callers.py                           # calls.csv: return types from what callers do with r0 / s0
python -I tools/slotargs.py <where>...               # the arguments a function reads
python -I tools/headers.py [--check]                 # include/<ns>/<Class>.h
python -I tools/objexport.py [paths] [--report]      # objects and objdiff.json for objdiff (toolchain/objdiff/); a viewer, not the judge
python -I tools/local/packets.py --name <batch> [--ready] [--decompiler]   # packets for agents (build/us-v1.2/packets/<batch>/)
python -I tools/local/permute.py --list <file>       # random source changes kept when closer; read before taking
python -I tools/local/m2cref.py <where>...           # m2c's C, a reference (GPL, run as an outside program; [paths] m2c)
python -I tools/local/ccsweep.py [--cc CC] [--flags] # tiny.py's candidates under every compiler
python -I tools/typecontext.py --out DIR @list.txt   # the classes' C context for a decompiler (DIR/<program>.json)
py -3.12 tools/local/ida.py c [--types DIR] <where>...  # Hex-Rays' C (reference only), with our types; `starts code.bin` for IDA's starts
python -I tools/local/ghidra_server.py serve|stop|decompile <offset>   # Ghidra kept open (a Python with pyghidra for serve)
python -I tools/local/ghidra_server.py typed DIR/<program>.json <offset>...  # Ghidra's C with our types (undone after)
python -I tools/local/idastarts.py                   # starts IDA has and the table lacks (in build/)
```

`<where>`: `0x003D6790` (code.bin) or `Battle:0x4F508` (module, file offset). After
`functable.py` rewrites the table: `rtti.py`, `ctors.py`, `classify.py`, `fields.py`,
`headers.py` (or `refresh.py --table`). Ghidra, IDA and m2c are optional (`tools/CLAUDE.md`);
their paths are your machine's, in `project.local.toml` (out of git).

## What is where

- `src/` by program: `src/main` (code.bin) and `src/<Module>`. In each: `units/unit_<address>.cpp`
  (a translation unit a person filled, found by its static initializer, `//! <where> __sti__`),
  `generated/` (the tools': `tiny_NNN.cpp`, `dtors_NNN.cpp`, `twins_NNN.cpp`, `units/`; not in
  git; a function leaves it when it gets a real source elsewhere, and a unit file of
  `generated/units/` moves to `units/` before anyone adds to it), folders by namespace for
  written sources.
- `include/`: the headers. One that starts with `// generated by tools/headers.py` is rewritten by
  the tool; remove that line to edit it, and the tool then follows it (slots, parameters, size).
- `config/us-v1.2/`: `functions.csv` (start, end, mode, name, class, slot, method, library),
  `symbols.txt`, `classes.csv` and `vtables.csv` (from the RTTI), `ctors.csv`, `fields.csv`,
  `enums.csv`, `calls.csv`, `returns.csv`, `members.csv` (members a person gives, with the
  evidence; they win over `fields.csv`), `bounds.csv`, `extra_starts.txt` (starts Ghidra
  misses), `flagsets.txt`, `honest_allow.txt`. `config/um-v1.2/map.csv`: Ultra Moon's map.
- `tools/`: the tools' own repository (matching-decomp-tools, MIT). They hold nothing of this
  game: this project's versions, compiler, flags, libraries and local paths are in
  `project.toml`. A change to a tool is a change in that repository; `tools/local/` holds the
  helpers for agents and people.
- `orig/` (your copy of the game), `toolchain/` (decomp.me's armcc builds, objdiff), `build/`
  (what the tools write), `probes/` (experiments): ignored.

## What is known of the code

- Compiler: **ARMCC 4.1 b1049** of decomp.me's set (`toolchain/armcc/4.1/b1049`), flags in
  `project.toml`; how they were found: `CONTRIBUTING.md`. Its C++ library is its own `include/`
  (Rogue Wave), so `<map>` etc. work. Only decomp.me's set is used.
- Versions: `tools/versions.py um-v1.2` writes `config/um-v1.2/map.csv` (same / moved / differs
  for every function; 335 differ). `MATCH_VERSION=um-v1.2` compares with Ultra Moon, the
  addresses staying Ultra Sun's; `refresh.py` checks both. A function that differs is written
  once with `GAME_VERSION` (`include/version.h`), the only `#if` `honest.py` allows.
- The linker inlined branches: a bl to a function that only returns is `mov r0, r0`, a bl to a
  one-instruction function is that instruction, a tail call to the next function is
  `mov r0, r0`. `match.py` models it (`inlined()`); the source makes the call. The other nop,
  `E320F000` before a branch, is armcc's own (`--cpu=MPCore -O3 -Otime`): the right source gives
  it by itself.
- Calling convention: floats and float structs go in VFP registers (s0...); a class returned by
  value that is not plain data goes through r0 (`this` in r1).
- C++ ABI (Itanium): D1 is the complete destructor, D0 the deleting one, C1/C2 aliases. An
  override of a secondary base's virtual gets a new slot in the primary vtable and a thunk in
  the base's (`sub r0, r0, #n` and the body again; `_ZThn<n>_N...`); `headers.py` declares it,
  and one source matches both.
- `code.bin` from ~0x14C000 to 0x54A874 is in the order of the mangled names (the linker sorts
  `i.<name>` sections; a tail call sits before its target): an unnamed function's name lies
  between its named neighbours' (`bounds.py`). Library objects sit in between, so a scope is not
  proof of whose code it is.
- Generated headers: members from `fields.py` (`field_<offset>`, `unk_<offset>[n]`; offset and
  width checked with `offsetof`, names and types guesses) and `members.csv`; virtual slots no
  name gives get their parameters from their versions' code (`slotargs.py`, marked as guesses;
  a slot returning a class by value is left out); return types from `returns.csv`, then the
  function's own code, then its callers (`calls.csv`), all but the first marked as guesses. A
  nested class is inside its outer class's header. `build/us-v1.2/no_members.txt` says why a
  class has no members.
- Enums (`enums.csv`): placeholder values that give the size the callers show.

## Working on the tools

`tools/CLAUDE.md`. In short: never patch a tool with a shell heredoc that holds a backslash; every
tool stops on an argument it does not know; after a change, `refresh.py --derive`, and
`progress.py` must give the same count of matched functions, none lost, unless the change is
meant to move it.
