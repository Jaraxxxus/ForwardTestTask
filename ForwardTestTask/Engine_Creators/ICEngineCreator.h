
#include "../Interfaces/IEngineCreator.h"
#include"../Engines/Internal_Combustion_Engine.h"
#include "../EConfig.h"


class ICEngineCreator :public IEngineCreator
{
public:
    IEngine* CreateEngine(EConfig& conf) override
    {

        return new Internal_Combustion_Engine(conf);

    }
    ~ICEngineCreator() {};
};

