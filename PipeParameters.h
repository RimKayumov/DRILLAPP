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
    const double diameterOutside_; // Наружный диаметр
    const double thickness_; // Толщина стенки

    const int meters_;

    double diameterInner_; // Внутренний диаметр
    double metalVolume_; // Объем металла
    double internalVolume_; // Объем внутреннего пространства
    double pipeVolume_; // Объем трубы

};

