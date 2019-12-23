#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
//#include "building.h"
#include "data.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),ui(new Ui::MainWindow)
{
    connect(&building,SIGNAL(updateGUI()),this, SLOT(slot_update_data()));
    ui->setupUi(this);

}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::slot_update_data()
{

    data = building.getdata();

    cout << "now floor: " << data.nowfloor << endl;
    if (data.nowfloor != 0)
    {
        //update information
        on_pushButton_clicked();
    }
    else
    {
        //cout << "enter else" << endl;
        ui->finishLabel->setVisible(true);
        building.timerStop();
    }
}

void MainWindow::on_pushButton_clicked()
{

    building.run(data.nowfloor);//選擇的樓層
    data = building.getdata();

    ui->Testdata_1->setText(QString::fromStdString(data.testdata1));
    ui->Submitdata_1->setText(QString::fromStdString(data.submit1));
    ui->Correct_1->setText(QString::fromStdString(to_string(data.correct1)));
    ui->Spend_time_1->setText(QString::fromStdString(to_string(data.spendtime1)));
    ui->PeopleNum->setText(QString::fromStdString(to_string(building.people[ui->OptionComboBox->currentIndex()]->Number)));
    ui->Destination->setText(QString::fromStdString(to_string(building.people[ui->OptionComboBox->currentIndex()]->Destination)));

    //elevatoe info
    ui->NowElevator->display(data.nowfloor);
    ui->Distance->display(data.distance);
}


void MainWindow::on_startSimBtn_clicked()
{
    ui->finishLabel->setVisible(false);
    building.startSimulation();
}
