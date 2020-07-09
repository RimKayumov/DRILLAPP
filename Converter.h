#pragma once
#include <QString>


class Converter
{
public:
    Converter();
    static int toInt(const QString &data, bool bigEndian);
    static quint32 toUint(const QByteArray &data, bool bigEndian);
    static float toFloat(const QString &data, bool bigEndian);
    static QString toHex(float value, bool bigEndian);
};

