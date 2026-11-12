// the fade manager's singleton (first matched function: proves the pipeline)
//! 0x00360D68 GetInstance

struct FadeManager;
extern "C" FadeManager *data_006A5A0C;

struct FadeManagerAccessor {
    static FadeManager *GetInstance();
};

FadeManager *FadeManagerAccessor::GetInstance()
{
    return data_006A5A0C;
}
