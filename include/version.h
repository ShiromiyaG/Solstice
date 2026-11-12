#ifndef VERSION_H
#define VERSION_H

// The version a source is built for. The tools pass GAME_VERSION on the command line
// (tools/config.py, version_define): the game's own number for each version, the one its save
// data and its Pokémon carry. The names are ours; the original's are not known.
//
// Ultra Sun and Ultra Moon are one program built twice; config/um-v1.2/map.csv lists the
// functions whose code differs (tools/versions.py). Only those tell the versions apart, with
// `#if GAME_VERSION == VERSION_ULTRA_SUN` or the value of GAME_VERSION itself.

#define VERSION_ULTRA_SUN 32
#define VERSION_ULTRA_MOON 33

#ifndef GAME_VERSION
#error "GAME_VERSION is not set: the tools pass it (tools/config.py, version_define)"
#endif

#endif
