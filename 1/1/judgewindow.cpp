#include "judgewindow.h"
#include "ui_judgewindow.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <iostream>
#include <string>
#include <QGridLayout>
#include <QDebug>
#include <building.h>
using namespace std;

JudgeWindow::JudgeWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::JudgeWindow)
{
    ui->setupUi(this);


//    building.run(ui->OptionComboBox->currentIndex());//選擇的樓層
//    windata = building.getdata();
    query.exec("drop database FINAL");
    query.exec("create database if not exists FINAL");
    query.exec("use FINAL");
    query.exec("drop table if exists TestData");
    query.exec("create table if not exists TestData (ID char(8),Floor int,Question text,Answer text,PRIMARY KEY(ID))");
    query.exec("drop table if exists InitialCondition");
    query.exec("create table if not exists InitialCondition (ID char(8),Nowfloor int,Destination int,Number int,PRIMARY KEY(ID))");
    query.exec("load data infile 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/testdata.csv' into table TestData fields terminated by ',' enclosed by '\"' lines terminated by '\r\n' ignore 1 rows");
    query.exec("load data infile 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/simple_initial_condition.csv' into table InitialCondition fields terminated by ',' enclosed by '\"' lines terminated by '\r\n' ignore 1 rows");
    query.exec("select * from InitialCondition");
    for(int i=0;i<27;i++){
        for(int j=0;j<4;j++){
            if(j==0){
                query.next();
                showline[i][j].setText(query.value(3).toString());
            }
            ui->gridLayout_2->addWidget(&showline[i][j],i,j);
        }
    }

}

string JudgeWindow::getData(int floor, int b){    

    string result="";
    query.exec("use FINAL");
    query.exec("select count(Question) from testdata where floor="+QString::number(floor+1));
    query.next();
    cerr<<query.value(0).toInt()<<endl;
    int num = rand()%(query.value(0).toInt());

    query.exec("select Question,Answer from testdata where floor = "+QString::number(floor+1)+" and ID like '%"+QString::number(num)+"'");
    query.next();
    result=query.value(0).toString().toStdString();
    answer=query.value(1).toString().toStdString();
    cout<< "question: " << result<<endl;
    cout<< "answer: " << answer<<endl;
    timer.start();
    return result;
}

bool JudgeWindow::submitData(string ans){
    //timer end
    costtime = timer.nsecsElapsed();

    if(answer.compare(ans)==0){
        return true;
    }
    else{
        return false;
    }
}

int JudgeWindow::getConditionNum(){
    return rand()%300+1;
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
