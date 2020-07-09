#include "logicmodule.h"

logicModule::logicModule()
{

}

void logicModule::firstFunk(QStringList meraQStringList)
{
    MERA.clear();
    for (const QString& item : meraQStringList){
        if (item != nullptr)
        MERA.push_back(item.toDouble());
    }

    if (!incrementalMERA.empty()) incrementalMERA.clear();
    auto it = MERA.begin();
    for(;it!=MERA.end();++it)
        incrementalMERA.push_back(std::accumulate(MERA.begin(), it, 0.00));
    incrementalMERA.push_back(std::accumulate(MERA.begin(), MERA.end(), 0.00));
}

double logicModule::tubes() // возвращает количество труб
{
    return (double)MERA.size();
}

double logicModule::sumOftubes()
{
    return std::accumulate(MERA.begin(), MERA.end(), 0.00);
}

void logicModule::setKNBK(const QString &value)
{
    m_knbk = value.toDouble();
    calculations();
}

void logicModule::setKvadrat(const QString &value)
{
    m_kvadrat = value.toDouble();
    calculations();
}

void logicModule::setNiz(const QString &value)
{
    m_niz = value.toDouble();
    calculations();
}

void logicModule::setSpinBox_Drill_val(const QString &SpinBox_Drill_val)
{
    m_SpinBox_Drill_val = SpinBox_Drill_val.toDouble();
    calculations();
}

void logicModule::setZaboy(const QString &value)
{
    m_zaboy = value.toDouble();
   // calculations(); // ждем значения по Верху
}

void logicModule::setVerh(const QString &value)
{
    m_verh = value.toDouble();
    calculations(); // теперь вычисляем
}

void logicModule::setPodnyato(const QString &value)
{
    m_podnyato = value.toDouble();
    calculations();
}

void logicModule::setSpusheno(const QString &value)
{
    m_spusheno = value.toDouble();
    calculations();
}

QString logicModule::parameter(ParamEnum _pe)
{
    switch (_pe) {
    case ParamEnum::zaboy: {return QString::number(m_zaboy);}
    case ParamEnum::prognosis: {return QString::number(m_prognosis);}
    case ParamEnum::variation: {return QString::number(m_variation);}
    case ParamEnum::nadZaboem: {return QString::number(m_nadZaboem);}
    case ParamEnum::svech: {return QString::number(m_svech);}
    case ParamEnum::metrovSPO: {return QString::number(m_metrovSPO);}
    default: return "Oops";
    }
}

void logicModule::calculations()
{
    { // вычисляем прогноз по забою
        if (m_SpinBox_Drill_val == 0)
            m_prognosis = 0;
        else if (!incrementalMERA.empty()){
            m_prognosis  = incrementalMERA.at(m_SpinBox_Drill_val*2);
            m_prognosis += (m_knbk + m_kvadrat);
            //return IncrementalPipesMeters.size();
        }
    }
    { // отклонение
        m_variation = m_zaboy - m_prognosis;
    }
    { // над забоем
        m_nadZaboem = m_verh - m_niz + m_variation;
    }
    { // свеч ост.
        m_svech = m_SpinBox_Drill_val - m_podnyato + m_spusheno;
    }
    { // метров при СПО
        double tmpl = m_SpinBox_Drill_val - m_podnyato + m_spusheno;
        if (tmpl == 0)
            m_metrovSPO = 0;
        else if (!incrementalMERA.empty()){
            m_metrovSPO  = incrementalMERA.at(tmpl*2) + m_knbk + m_kvadrat;
        }
    }
}

