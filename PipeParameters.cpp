#include "PipeParameters.h"


PipeParametrs::PipeParametrs(double&diameterOutside, double&thickness, int&meters) :
                                    diameterOutside_(diameterOutside),
                                    thickness_(thickness),
                                    meters_(meters)
{
    FieldsFilling();
}

QString PipeParametrs::GetDiameterInner()
{
    return QString::number(diameterInner_);

}

QString PipeParametrs::GetMetalVolume()
{
    return QString::number(metalVolume_*meters_);
}

QString PipeParametrs::GetInternalVolume()
{
    return QString::number(internalVolume_*meters_);
}

QString PipeParametrs::GetPipeVolume()
{
    return QString::number(pipeVolume_*meters_);
}

void PipeParametrs::FieldsFilling()
{
    diameterInner_ = diameterOutside_ - (thickness_*2); // Внутренний диаметр
    pipeVolume_ = pi*GetRadiusMm(diameterOutside_)*GetRadiusMm(diameterOutside_); // Объем трубы
    internalVolume_ = pi*GetRadiusMm(diameterInner_)*GetRadiusMm(diameterInner_); // Объем внутреннего пространства
    metalVolume_ = pipeVolume_ - internalVolume_; // Объем металла
}

double PipeParametrs::GetRadiusMm(double D)
{
    return (D/2)/1000;
}
