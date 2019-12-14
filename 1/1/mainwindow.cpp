#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include "building.h"
#include "data.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connectDB()
{

}

void MainWindow::on_pushButton_clicked()
{

    Data windata;
    //Q1
    building.run(ui->OptionComboBox->currentIndex());//選擇的樓層
    windata = building.getdata();

    ui->Testdata_1->setText(QString::fromStdString(windata.testdata1));
    ui->Submitdata_1->setText(QString::fromStdString(windata.submit1));
    ui->Correct_1->setText(QString::fromStdString(to_string(windata.correct1)));
    ui->Spend_time_1->setText(QString::fromStdString(to_string(windata.spendtime1)));


}

void MainWindow::on_People_Infomation_clicked()
{
    ui->PeopleNum->setText(QString::fromStdString(to_string(building.people[ui->OptionComboBox->currentIndex()]->Number)));
    ui->Destination->setText(QString::fromStdString(to_string(building.people[ui->OptionComboBox->currentIndex()]->Destination)));
}
