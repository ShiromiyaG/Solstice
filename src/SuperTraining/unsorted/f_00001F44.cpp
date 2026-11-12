// no class known; both fields are UIResponder pointers (the classes the callee names); the callee's name is the mangled one.

namespace app {
namespace ui {
class UIResponder {
public:
    void SetInputEnabled(bool enabled);
};
}
}

//! SuperTraining:0x00001F44 f_SuperTraining_00001F44
void f_SuperTraining_00001F44(int a1) {
    ((app::ui::UIResponder *)*(int *)(a1 + 4))->SetInputEnabled(false);
    ((app::ui::UIResponder *)*(int *)(a1 + 8))->SetInputEnabled(false);
}
