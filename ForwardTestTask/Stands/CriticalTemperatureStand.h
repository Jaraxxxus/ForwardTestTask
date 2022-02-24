#pragma once
#include "../Interfaces/IStand.h"

class IEngine;



class CriticalTemperatureStand : public IStand
{
public:

    void set_MaxTime(int maxtm) override;
    std::string RunTest(IEngine* Engine) override;
    void Update(bool& is_run) override;
private:
    int Time_run = 0;
    bool overrun = false;
    int MaxTime = 500000;
    std::string Get_result() override;
};

