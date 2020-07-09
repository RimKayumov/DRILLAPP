#pragma once

#include <QVector>
#include <QString>
#include <QStringList>
#include "enumParameter.h"

class logicModule
{
public:
    logicModule();
    void firstFunk(QStringList meraQStringList);
public:
    // публичные методы
    double tubes(); // возвращает количество трубок
    double sumOftubes();
    //double WellDepth(); // читается со сборщика
    //double verhniy(); // читается со сборщика
    void setKNBK(const QString&);
    void setKvadrat(const QString&);
    void setNiz(const QString&);
    void setSpinBox_Drill_val(const QString&);
    void setZaboy(const QString&);
    void setVerh(const QString&);
    void setPodnyato(const QString&);
    void setSpusheno(const QString&);

    QString parameter(ParamEnum);
    void calculations();

private:
    // приватные поля
    QVector<double> MERA; // просто трубки
    QVector<double> incrementalMERA; // нарастающая мера
    double m_knbk;
    double m_kvadrat;
    double m_niz;
    double m_SpinBox_Drill_val = 0.0;
    double m_zaboy;
    double m_verh;
    double m_prognosis;
    double m_variation;
    double m_nadZaboem;
    double m_svech;
    double m_podnyato = 0.0;
    double m_spusheno = 0.0;
    double m_metrovSPO;
};
