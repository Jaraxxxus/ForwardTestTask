#pragma once
#include "IStand.h"
class IStand;


class IEngine
{
public:


	bool is_run;
	virtual void StartSimulation() =0;
	virtual ~IEngine() = default;
	virtual void Attach(IStand* t) =0;
protected:
	IEngine() = default;
private:
	virtual void Detach() = 0;
	virtual void Notify() = 0;

};