#pragma once

#include <QString>

class PipeParametrs
{
public:
    PipeParametrs(double&,double&, int&);

    QString GetDiameterInner();
    QString GetMetalVolume();
    QString GetInternalVolume();
    QString GetPipeVolume();

private:
    void FieldsFilling();
    double GetRadiusMm(double);

    double FluidVolume;
    const double pi = 3.141593;
    const double diameterOutside_; // �������� �������
    const double thickness_; // ������� ������

    const int meters_;

    double diameterInner_; // ���������� �������
    double metalVolume_; // ����� �������
    double internalVolume_; // ����� ����������� ������������
    double pipeVolume_; // ����� �����

};

