// pml::personal calls, named by their mangled names in the packet. The enum bodies are guesses: only the names matter to the symbols.

namespace pml {
namespace personal {
enum ParamID { ParamID_Guess = 0 };
void LoadPersonalData(unsigned short monsNo, unsigned char form);
int GetPersonalParam(ParamID id);
}
}

enum MonsNo { MonsNo_Guess = 0 };

//! Battle:0x0007E0E8 f_Battle_0007E0E8
int f_Battle_0007E0E8(unsigned short a1, unsigned char a2, int a3) {
    pml::personal::LoadPersonalData((MonsNo)a1, a2);
    return pml::personal::GetPersonalParam((pml::personal::ParamID)a3);
}
