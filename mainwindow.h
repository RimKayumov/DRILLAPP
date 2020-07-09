#pragma once

#include <QMainWindow>
#include <QClipboard>
#include <QSettings>
#include <QString>
#include <QLineEdit>
#include <QTextCodec>
#include <QFileDialog>
#include <QTimer>
#include <QMessageBox>

#include "logicmodule.h"
#include "storeModule.h"
#include "enumParameter.h"
#include "PipeParameters.h"
#include "WorkTimer.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QClipboard *bufer;
    logicModule logicModul;
    QTextCodec *codec = QTextCodec::codecForName("Windows-1251");
    QString pathToSBORCHIK;
    QTimer timer;
    storeModule store;
    int timeInterval = 10;

private:
    void ReadSettings();
    void WriteSettings();
    void ShowValues();
    QString CommaToDot(const QString&);

private slots:
    void slotReadFromTextEdit_Mera();
    void slotReadZaboyANDVerh();
    void on_line_KNBK_textChanged(const QString&);
    void on_line_Kvadrat_textChanged(const QString&);
    void on_line_Niz_textChanged(const QString&);
    void on_line_Zaboy_textChanged(const QString&);
    void on_line_Verh_textChanged(const QString&);
    void on_doubleSpinBox_Drill_valueChanged(const QString&);
    void on_doubleSpinBox_Vira_valueChanged(const QString &arg1);
    void on_doubleSpinBox_Maina_valueChanged(const QString &arg1);
    void on_checkBox_Window_toggled(bool checked);
    void on_pushButton_Path_clicked();
    void on_pushButton_Start_clicked();
    void on_lineEdit_Path_editingFinished();
    void on_lineSec_textChanged(const QString &arg1);
    void on_diameterOutside_textChanged(const QString &arg1);
    void on_thickness_textChanged(const QString &arg1);
    void on_spinBoxToppingUp_valueChanged(int arg1);
    void on_pushButtonCalc_clicked();
};
