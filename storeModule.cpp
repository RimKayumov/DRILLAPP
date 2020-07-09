#include "storeModule.h"
#include <cmath>
#include <QDebug>

storeModule::storeModule()
{
    fileDep = new QFile;
    fileLst = new QFile;
}

storeModule::~storeModule()
{
    if(fileDep->isOpen()) fileDep->close();
    if(fileLst->isOpen()) fileLst->close();
}

bool storeModule::open(QString path)
{
    dep_path = path;
    lst_path = path;

    pathModify(dep_path, DEP);
    pathModify(lst_path, LST);

    fileDep->setFileName(dep_path);
    fileLst->setFileName(lst_path);

    return (fileDep->open(QIODevice::ReadOnly) && fileLst->open(QIODevice::ReadOnly));
}

bool storeModule::isOpen()
{
    return (fileDep->isOpen() && fileLst->isOpen());
}

void storeModule::close()
{
    fileDep->close();
    fileLst->close();
}

void storeModule::Emplace(QString &str, char a, QString b)
{
    str = str.replace(a, b); // редактирует адрес пути
}

void storeModule::generate()
{
    if (!fileDep->isOpen() && !fileLst->isOpen()){
        fileDep->open(QIODevice::ReadOnly);
        fileLst->open(QIODevice::ReadOnly);
    }
    qDebug() << "files opened!";
//************************************************************************
    fileLst->seek(fileLst->size()-21);
    QByteArray *lst_array = new QByteArray(fileLst->read(4));
    auto seekFromLst = converter.toUint(*lst_array, 0);
    delete lst_array;
//************************************************************************


   //***************
   values.clear();

   fileDep->seek(seekFromLst + 10);

   int valueSize = 0;
   int numPar = 0;
    qDebug() << "cycle started!";
   while (numPar < quantity){ // ограничим цикл до n-го параметра

       fileDep->read(1); // пропускаем 1 символ, который несет информацию о номере справочника. но нам он не нужен

       QByteArray *ba = new QByteArray(fileDep->read(1));

       const unsigned char NumPar = *ba->data();
       delete ba;
       qDebug() << 666;
       qDebug() << 777;
       numPar = (int)NumPar;
       qDebug() << 888;

       valueSize = parsys.sizeOf(numPar);
       qDebug() << valueSize;

       QByteArray *baf = new QByteArray(fileDep->read(valueSize));
       float tmp_f = converter.toFloat(baf->toHex().data(), 0);
        qDebug() << numPar;
       values[numPar] = (ceil(tmp_f  * 100) / 100);

       delete baf;
       qDebug() << numPar;
   }
   qDebug() << "cycle stopped!";
   close();
}

void storeModule::pathModify(QString& path, int value)
{
    if (value == DEP){
        path.resize(path.size()-3);
        path += "dep";
    }
    else if (value == LST){
        path.resize(path.size()-3);
        path += "lst";
    }
}

double storeModule::getParameter(int P)
{
    return values[P];

}
