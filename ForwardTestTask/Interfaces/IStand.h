#pragma once
#include <string>
#include "IEngine.h"
class IEngine;

class IStand
{
public:
	virtual std::string RunTest(IEngine* Engine) = 0;
	virtual ~IStand() = default;
	virtual void Update(bool& is_run) = 0;
	virtual void set_MaxTime(int maxtm) = 0;
private:
	virtual std::string Get_result() = 0 ;
};
