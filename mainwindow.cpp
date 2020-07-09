#include "mainwindow.h"
#include "ui_mainwindow.h"

//#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->StartDay->setDate(QDate::currentDate());
    ReadSettings(); // читаем реестр
    connect(ui->textEdit_Mera, SIGNAL(textChanged()), this, SLOT(slotReadFromTextEdit_Mera()));
    connect(&timer, SIGNAL(timeout()), this, SLOT(slotReadZaboyANDVerh()));
}

MainWindow::~MainWindow()
{
    WriteSettings(); // пишем в реестр
    delete ui;
}

void MainWindow::slotReadFromTextEdit_Mera() // слот на чтение меры при изменении textEdit_Mera
{
    QString meraString = ui->textEdit_Mera->toPlainText();

    meraString.replace(',', '.');
    meraString.replace('\n', ' ');

    QStringList meraQStringList = meraString.split(' ');

    logicModul.firstFunk(meraQStringList); // передаем модулю логики meraQStringList
    ui->doubleSpinBox_Drill->setMaximum(logicModul.tubes()/2); // устанавливаем максимум на спин бокс

    // выводим сообщение в статусбар о количестве труб и свечей:
    auto str1 = codec->toUnicode("В установленной мере всего труб: ");
    auto str2 = codec->toUnicode(" (свеч: ");
    auto str3 = codec->toUnicode(")-> ");
    auto str4 = codec->toUnicode("м ");
    QString msg = str1 + QString::number(logicModul.tubes()) + str2 +
            QString::number(logicModul.tubes()/2) + str3 + QString::number(logicModul.sumOftubes()) + str4;
    ui->statusbar->showMessage(msg);
}

void MainWindow::slotReadZaboyANDVerh()
{
    store.generate(); // обязательно нужно сначала сгенерировать контейнер значений, чтобы с него считать нужный параметр

    ui->line_Zaboy->setText(QString::number(store.getParameter(53))); // забой
    logicModul.setZaboy(ui->line_Zaboy->text());
    ui->line_Verh->setText(QString::number(store.getParameter(12))); // положение крюка
    logicModul.setVerh(ui->line_Verh->text());
}

void MainWindow::ReadSettings()
{
    QSettings settings("Meraba", "temp");

   // ui->line_Niz->setInputMask("0.00");

    ui->line_Zaboy->setText(settings.value("depth").toString());
    ui->line_Niz->setText(settings.value("lower").toString());

    ui->doubleSpinBox_Drill->setValue(settings.value("SpinBox").toDouble());
    logicModul.setSpinBox_Drill_val(QString::number(ui->doubleSpinBox_Drill->value()));

    ui->line_KNBK->setText(settings.value("knbk").toString());
    ui->line_Kvadrat->setText(settings.value("extra").toString());

    ui->doubleSpinBox_Vira->setValue(settings.value("vired").toDouble());
    logicModul.setPodnyato(QString::number(ui->doubleSpinBox_Vira->value()));

    ui->doubleSpinBox_Maina->setValue(settings.value("mined").toDouble());
    logicModul.setSpusheno(QString::number(ui->doubleSpinBox_Maina->value()));

    ui->textEdit_Mera->setText(settings.value("pipes_meters").toString());

    ui->lineEdit_Path->setText(settings.value("path").toString());
    pathToSBORCHIK = ui->lineEdit_Path->text();

    ui->lineSec->setText(settings.value("timeInterval").toString());

    ui->diameterOutside->setText(settings.value("diameterOutside").toString());
    ui->thickness->setText(settings.value("thickness").toString());

    slotReadFromTextEdit_Mera();
}

void MainWindow::WriteSettings()
{
    QSettings settings("Meraba", "temp");

    settings.setValue("depth", ui->line_Zaboy->text());
    settings.setValue("lower", ui->line_Niz->text());
    settings.setValue("SpinBox", ui->doubleSpinBox_Drill->value());
    settings.setValue("knbk", ui->line_KNBK->text());
    settings.setValue("extra", ui->line_Kvadrat->text());
    settings.setValue("vired", ui->doubleSpinBox_Vira->value());
    settings.setValue("mined", ui->doubleSpinBox_Maina->value());
    settings.setValue("pipes_meters", ui->textEdit_Mera->toPlainText());
    settings.setValue("path", ui->lineEdit_Path->text());
    settings.setValue("timeInterval", ui->lineSec->text());
    settings.setValue("diameterOutside", ui->diameterOutside->text());
    settings.setValue("thickness", ui->thickness->text());
}

void MainWindow::ShowValues()
{
    ui->line_Zaboy->setText(logicModul.parameter(ParamEnum::zaboy)); //??????????????
    ui->line_Prognosis->setText(logicModul.parameter(ParamEnum::prognosis));
    ui->line_Variation->setText(logicModul.parameter(ParamEnum::variation));
    ui->line_NadZaboem->setText(logicModul.parameter(ParamEnum::nadZaboem));
    ui->line_Svech->setText(logicModul.parameter(ParamEnum::svech));
    ui->line_Metrov->setText(logicModul.parameter(ParamEnum::metrovSPO));
}

void MainWindow::on_line_KNBK_textChanged(const QString& value)
{
    ui->line_KNBK->setText(CommaToDot(value));
    logicModul.setKNBK(value);
    ShowValues();
}

void MainWindow::on_line_Kvadrat_textChanged(const QString& value)
{
    ui->line_Kvadrat->setText(CommaToDot(value));
    logicModul.setKvadrat(value);
    ShowValues();
}

void MainWindow::on_line_Niz_textChanged(const QString &value)
{
    ui->line_Niz->setText(CommaToDot(value));
    logicModul.setNiz(value);
    ShowValues();
}

void MainWindow::on_line_Zaboy_textChanged(const QString& value)
{
    ui->line_Zaboy->setText(CommaToDot(value));
    logicModul.setZaboy(value);// прежде забой определяем со сборщика
    ShowValues();
}

void MainWindow::on_line_Verh_textChanged(const QString& value)
{
    ui->line_Verh->setText(CommaToDot(value));
    logicModul.setVerh(value);// прежде определяем со сборщика
    ShowValues();
}

void MainWindow::on_doubleSpinBox_Drill_valueChanged(const QString& value)
{
    logicModul.setSpinBox_Drill_val(CommaToDot(value));
    ShowValues();
}

void MainWindow::on_doubleSpinBox_Vira_valueChanged(const QString &value)
{
    ui->doubleSpinBox_Vira->setMaximum(ui->doubleSpinBox_Drill->value());
    logicModul.setPodnyato(CommaToDot(value));
    ShowValues();
}

void MainWindow::on_doubleSpinBox_Maina_valueChanged(const QString &value)
{
    ui->doubleSpinBox_Maina->setMaximum(ui->doubleSpinBox_Drill->maximum() - ui->doubleSpinBox_Drill->value() + ui->doubleSpinBox_Vira->value());
    logicModul.setSpusheno(CommaToDot(value));
    ShowValues();
}

QString MainWindow::CommaToDot(const QString &T)
{
    QString R = T;
    return R.replace(",", ".");
}

void MainWindow::on_checkBox_Window_toggled(bool checked)
{
    setWindowFlag(Qt::WindowStaysOnTopHint, checked);
    show();
}

void MainWindow::on_pushButton_Path_clicked()
{
    pathToSBORCHIK = QFileDialog::getOpenFileName(this, "Open file", "", "Store(*dep)");
   // store.Emplace(pathToSBORCHIK, '/', "\/\/");
    ui->lineEdit_Path->setText(pathToSBORCHIK);

}

void MainWindow::on_pushButton_Start_clicked()
{
    ui->pushButton_Start->setEnabled(0);
    if (store.open(pathToSBORCHIK)) QMessageBox::information(this, codec->toUnicode("Удача!"), codec->toUnicode("Файл удачно открыт!"));
    else QMessageBox::information(this, codec->toUnicode("Неудача!"), codec->toUnicode("Что-то пошло не так!"));

    if (timeInterval > 0){
       // ui->lineEdit_Path->setText(pathToSBORCHIK);
        timer.setInterval(timeInterval*1000);
        timer.start();
    }
}

void MainWindow::on_lineEdit_Path_editingFinished()
{
    pathToSBORCHIK = ui->lineEdit_Path->text();
}

void MainWindow::on_lineSec_textChanged(const QString &time)
{
    timeInterval = time.toInt();
}

void MainWindow::on_diameterOutside_textChanged(const QString &value)
{
        ui->diameterOutside->setText(
                    CommaToDot(value)
                    );
}

void MainWindow::on_thickness_textChanged(const QString &value)
{
        ui->thickness->setText(
                    CommaToDot(value)
                    );
}

void MainWindow::on_spinBoxToppingUp_valueChanged(int meters)
{
    double DO = ui->diameterOutside->text().toDouble();
    double TH = ui->thickness->text().toDouble();
    PipeParametrs pp(DO, TH, meters);

    ui->diameterInner->setText(pp.GetDiameterInner());
    ui->pipeVolume->setText(pp.GetPipeVolume());
    ui->metalVolume->setText(pp.GetMetalVolume());
    ui->internalVolume->setText(pp.GetInternalVolume());
}

void MainWindow::on_pushButtonCalc_clicked()
{
    ui->textEdit->clear();
    WorkTimer WT;
    WT.Day = ui->StartDay->date();
    WT.DaysQuantity = ui->DaysQuantity->text().toInt();
    WT.TourQuantity = ui->TourQuantity->text().toInt();
    QDate iDay;
    bool b;
    int s = 1;
    for (int i = 0; i < WT.TourQuantity*2; ++i)
    {
        b = !b;
        iDay = WT.Day.addDays(WT.DaysQuantity);
        WT.Day = iDay;
        if (b){
          ui->textEdit->append(codec->toUnicode("Домой: ") + iDay.toString("dd MMM yyyy"));}
        else{
          ui->textEdit->append(codec->toUnicode("На работу: ") + iDay.toString("dd MMM yyyy"));
          ui->textEdit->append("======================"+QString::number(s)); ++s;}
    }
}
