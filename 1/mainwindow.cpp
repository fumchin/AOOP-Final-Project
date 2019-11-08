#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtMath>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //connect(ui->input,SIGNAL(clicked()),this,SLOT(showDiameter()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ComputeBtn_clicked()
{
    QString tempStr;
    QString valueStr = ui->input->text();
    int valueInt = valueStr.toInt();
    QString outStr = "";

    int mask;

    for (int i=0; i<11; i++)
    {
        mask = 7<<i*3;
        outStr = QString::number((mask & valueInt) >> i*3) + outStr;

    }

    ui->octalLabel->setText(outStr);
}

void MainWindow::showResult()
{

}
