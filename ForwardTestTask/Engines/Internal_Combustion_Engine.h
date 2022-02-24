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

    int Index = 0;//������� ������ �������

    double find_M(double v); //������� �������� ������
    
    double inaccuracy = 0.000000001;// ����������� �������� ����������
    double Overheating_t; // ����������� ���������
    double Engine_t; // ����������� ���������
    std::vector<int> dependM;  //  ����������� ��������� ������� �� �������� ��������
    std::vector<int> rotationV; // C������� �������� ��� �����������
    double V = 0;//������� �������� �������� ���������
    double Hm;// ����������� ����������� �������� ������� �� ��������� ������
    double Hv;// ����������� ����������� �������� ������� �� �������� �������� ���������
    double C; // ����������� ����������� �������� ���������� �� ����������� ��������� � ���������� �����
    double Air_t; // ����������� �������
    double I; //  ������ ������� 
   
    IStand* observer = nullptr;

    void Notify();
    void Detach();
};


