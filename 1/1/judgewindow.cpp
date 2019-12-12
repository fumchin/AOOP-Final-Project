#include "judgewindow.h"
#include "ui_judgewindow.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <iostream>
#include <string>
#include <QGridLayout>
using namespace std;

JudgeWindow::JudgeWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::JudgeWindow)
{
    for(int i=0;i<27;i++){
        for(int j=0;j<4;j++){
            ui->gridLayout_2->addWidget(&showline[i][j],i,j);
        }
    }
    ui->setupUi(this);
    query.exec("drop database if exists FINAL");
    query.exec("create database if not exists FINAL");
    query.exec("use FINAL");
    query.exec("drop table if exists TestData");
    query.exec("create table if not exists TestData (ID char(8),Floor int,Question text,Answer text,PRIMARY KEY(ID))");
    query.exec("drop table if exists InitialCondition");
    query.exec("create table if not exists InitialCondition (ID char(8),Nowfloor int,Destination int,Number int,PRIMARY KEY(ID))");
    query.exec("load data infile 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/testdata.csv' into table TestData fields terminated by ',' enclosed by '\"' lines terminated by '\r\n' ignore 1 rows");
    query.exec("load data infile 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/initial_condition.csv' into table TestData fields terminated by ',' enclosed by '\"' lines terminated by '\r\n' ignore 1 rows");

}

string JudgeWindow::getData(int floor, int b){
    string result="";
    query.exec("select count(Question) from testdata where floor="+QString::number(floor));
    query.next();
    int num = rand()%(query.value(0).toInt());
    query.exec("select Question,Answer from testdata where floor = "+QString::number(floor)+" and ID like '%"+QString::number(num)+"'");
    query.next();
    result+=query.value(0).toString().toStdString();
    answer+=query.value(1).toString().toStdString();
    cout<<result<<endl;
    timer.start();
    return result;
}

bool JudgeWindow::submitData(string ans){
    //timer end
    costtime = timer.nsecsElapsed();
    //ans is result from add1
    if(this->answer.compare(ans)==0){
        return true;
    }
    else{
        return false;
    }
}


JudgeWindow::~JudgeWindow()
{
    delete ui;
}
//string getData(int floor,int b);//input 0-26
//bool submitData(string ans);
//void setSeed(int seed){srand(seed);}
//qint64 getSpendTime(){return costtime;}
//int getConditionNum();//return 1-300
//int getDistance(){return distance;}
//void scheduleEnd();
//QLineEdit showline[27][4];
