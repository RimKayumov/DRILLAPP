#pragma once

#include <QFile>
#include <QString>
#include <QTimer>
#include <QByteArray>
#include <QDebug>
#include "Converter.h"
#include "ParsysX.h"


class storeModule
{
public:
    storeModule();
    ~storeModule();
    bool open(QString);
    bool isOpen();
    void close();
    void Emplace(QString &str, char a, QString b);
    void generate();
    int iq = 100;   // ���������!! �����!
private:
    const int quantity = 54;  //������ ��� ����� ��� ���������� �� �����
    Converter converter;
    QString dep_path;
    QString lst_path;
    QFile *fileDep, *fileLst;
    QByteArray *ba_dep, *ba_lst;
    enum {
        DEP,
        LST
    };

    ParsysX parsys;
    std::map <int, double> values;

    void pathModify(QString& path, int value);
public:
    double getParameter(int);
};
