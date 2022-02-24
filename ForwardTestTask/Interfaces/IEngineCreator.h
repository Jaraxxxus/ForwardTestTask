#pragma once
#include <fstream>
#include "IEngine.h"
#include "../EConfig.h"

class IEngineCreator {

    public:
        virtual ~IEngineCreator() {};
        virtual IEngine* CreateEngine(EConfig &conf) = 0;
   
};

