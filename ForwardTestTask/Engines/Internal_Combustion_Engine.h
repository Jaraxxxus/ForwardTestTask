#pragma once
#include "../Interfaces/IEngine.h"
#include <math.h>
#include "../EConfig.h"


class Internal_Combustion_Engine : public IEngine
{
public:
     bool is_run = false;

    Internal_Combustion_Engine() = default;
    Internal_Combustion_Engine(EConfig & config);

    void Attach(IStand* stand) override;

    void StartSimulation() override;

private:

    int Index = 0;//Текущий индекс массива

    double find_M(double v); //Текущий крутящий момент
    
    double inaccuracy = 0.000000001;// Погрешность разности температур
    double Overheating_t; // Температура перегрева
    double Engine_t; // Температура двигателя
    std::vector<int> dependM;  //  зависимость крутящего момента от скорости вращения
    std::vector<int> rotationV; // Cкорость вращения для зависимости
    double V = 0;//Текущая скорость вращения коленвала
    double Hm;// Коэффициент зависимости скорости нагрева от крутящего момент
    double Hv;// Коэффициент зависимости скорости нагрева от скорости вращения коленвала
    double C; // Коэффициент зависимости скорости охлаждения от температуры двигателя и окружающей среды
    double Air_t; // температура воздуха
    double I; //  Момент инерции 
   
    IStand* observer = nullptr;

    void Notify();
    void Detach();
};


