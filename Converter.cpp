#include "Converter.h"

Converter::Converter(){}

int Converter::toInt(const QString &data, bool bigEndian)
{
    const QByteArray ba = QByteArray::fromHex(data.toLatin1());
    quint32 word = toUint(ba, bigEndian);
    const int *f = reinterpret_cast<const int *>(&word);

    return *f;

}


quint32 Converter::toUint(const QByteArray &data, bool bigEndian)
{
    if (data.size() != 4)
        return 0;

    quint32 word = 0;

    if (bigEndian) {
        word = quint32((quint8(data.at(0)) << 24) |
                       (quint8(data.at(1)) << 16) |
                       (quint8(data.at(2)) <<  8) |
                       (quint8(data.at(3)) <<  0));
    } else {
        word = quint32((quint8(data.at(0)) <<  0) |
                       (quint8(data.at(1)) <<  8) |
                       (quint8(data.at(2)) << 16) |
                       (quint8(data.at(3)) << 24));

    }
    return word;
}

float Converter::toFloat(const QString &data, bool bigEndian)
{
    const QByteArray ba = QByteArray::fromHex(data.toLatin1());
    quint32 word = toUint(ba, bigEndian);

    const float *f = reinterpret_cast<const float *>(&word);

    return *f;
}

QString Converter::toHex(float value, bool bigEndian)
{
    const quint32 *i = reinterpret_cast<const quint32 *>(&value);

    return toHex(*i, bigEndian);
}
