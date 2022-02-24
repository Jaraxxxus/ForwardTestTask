#include "CriticalTemperatureStand.h"


void CriticalTemperatureStand::set_MaxTime(int maxtm)
{
	MaxTime = maxtm;
}

std::string CriticalTemperatureStand::RunTest(IEngine* Engine)
{
	Engine->Attach(this);
	Engine->StartSimulation();
	return Get_result();
}

void CriticalTemperatureStand::Update(bool& is_run)
{
    if (is_run)
        ++Time_run;
    if (Time_run == MaxTime)
    {
        is_run = false;
        overrun = true;
    }

}

std::string CriticalTemperatureStand::Get_result()
{
    std::string resultstr = "";
    if (overrun)
        resultstr += "maximum time (" + std::to_string(MaxTime) + " sec) reached, test passed";
    else
        resultstr += "overheating time = " + std::to_string(Time_run) + " sec";
    Time_run = 0;
    return resultstr;
}
