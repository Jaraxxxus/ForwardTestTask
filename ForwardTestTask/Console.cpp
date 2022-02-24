#include <iostream>
#include <fstream>
#include "Interfaces/IEngine.h"
#include "Engine_Creators/ICEngineCreator.h"
#include "Stands/CriticalTemperatureStand.h"
#include "Functions.h"
#include "EConfig.h"



int main() {
	double temp = 0;
	std::string inpstr;
	bool flag = false;
	EConfig config;
	std::cout << "set the air temperature in Celsius degree" << std::endl;
	while (!flag)
	{
		std::cin >> inpstr;
		flag = check_input(inpstr);
		if (!flag)std::cout << "please enter valid data" << std::endl;
		if (flag) temp = atof(inpstr.c_str());
		if (temp < -273.15)
		{
			std::cout << "this is absolute zero temperature, try again" << std::endl;
			flag = false;
		}
		
	}
	
	config.Air_t = temp;
	


	CriticalTemperatureStand st;
	ICEngineCreator cr;
	IEngine* eng = cr.CreateEngine(config);
	std::cout<<st.RunTest(eng)<<std::endl;
	

}