#include "Internal_Combustion_Engine.h"
#include "../EConfig.h"


void Internal_Combustion_Engine::Attach(IStand* stand) 
{
    observer = stand;
    return;
}


 Internal_Combustion_Engine::Internal_Combustion_Engine(EConfig& config)
{
    Engine_t = config.Air_t;
    Air_t = config.Air_t;
    Hm = config.Hm;
    Hv = config.Hv;
    C = config.C;
    dependM = config.M;
    rotationV = config.V;
    I = config.I;
    Overheating_t = config.Overheating_t;
}




 void Internal_Combustion_Engine::StartSimulation() 
 {
     is_run = true;

     double V = 0;
     int i = 0;
     double Engine_t2 = Engine_t;
     double M = dependM[Index];
     while (is_run)
     {
         double a = M / I;
         V += a;

         if (Index + 2 < dependM.size())
         {
             Index += V < rotationV[Index + 1] ? 0 : 1;
         }
         M = find_M(V);
         double vh = M * Hm + pow(V, 2) * Hv;//Скорость нагрева двигателя
         double vc = C * (Air_t - Engine_t);  //Скорость охлаждения
         Engine_t += vh + vc;
         if (Overheating_t - Engine_t < inaccuracy)
             is_run = false;
         Notify();

     }


 }

 
 

 double Internal_Combustion_Engine::find_M(double v) //текущий крутящий момент 
 {
     int _ind = (Index + 1 == rotationV.size()) ? Index : Index + 1;// что бы не было выхода за границы вектора при Index == vector.size()-1
     double M = (v - rotationV[Index]) / (rotationV[_ind] - rotationV[Index]) * (dependM[_ind] - dependM[Index]) + dependM[Index];
     return M;
 }



 void Internal_Combustion_Engine::Detach()
 {
     observer = nullptr;
 }

 void Internal_Combustion_Engine::Notify()
 {
     observer->Update(is_run);
 }