#ifndef NETLIB_NIJINETWORKSYSTEM_H
#define NETLIB_NIJINETWORKSYSTEM_H

// NetLib::NijiNetworkSystem: no type information in the game, known by its exported names
// (static.crs). only what is used so far.
namespace NetLib {

class NijiNetworkSystem {
public:
    // code.bin:003E58A0: static (it reads no argument; a tail call to 0x0040AEAC). bool is a
    // guess: its callers test the result
    static bool IsWLANSwitchEnable();
};

}  // namespace NetLib

#endif
