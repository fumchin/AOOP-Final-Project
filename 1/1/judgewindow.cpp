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

JudgeWindow::JudgeWindow(QWidget *parent) :QWidget(parent),ui(new Ui::JudgeWindow)
{
    ui->setupUi(this);

    query.exec("drop database FINAL");
    query.exec("create database if not exists FINAL");
    query.exec("use FINAL");
    query.exec("drop table if exists TestData");
    query.exec("create table if not exists TestData (ID char(8),Floor int,Question text,Answer text,PRIMARY KEY(ID))");
    query.exec("drop table if exists InitialCondition");
    query.exec("create table if not exists InitialCondition (ID char(8),Nowfloor int,Destination int,Number int,PRIMARY KEY(ID))");
    query.exec("load data infile 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/testdata_v3.csv' into table TestData fields terminated by ',' enclosed by '\"' lines terminated by '\r\n' ignore 1 rows");
    query.exec("load data infile 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/simple_initial_condition.csv' into table InitialCondition fields terminated by ',' enclosed by '\"' lines terminated by '\r\n' ignore 1 rows");
    query.exec("select * from InitialCondition");
    for(int i=0;i<27;i++){
        for(int j=0;j<4;j++){
            if(j==0){
                query.next();
                arr[i][j] = query.value(3).toInt();
                showline[i][j].setText(QString::number(arr[i][j]));
            }
            else if(j==1){
                showline[i][j].setText(QString::number(0));
            }
            else if(j==3){
                arr[i][j] = 1;
            }
            else if(j==2){
                arr[i][j] = 0;
            }
            ui->gridLayout_2->addWidget(&showline[i][j],i,j);
        }
    }
    for(int i=0;i<27;i++){
        for(int j=0;j<4;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
}

string JudgeWindow::getData(int floor, int b){    

    string result="";
//    query.exec("use FINAL");
//    query.exec("select count(Question) from testdata where floor="+QString::number(floor+1));
//    query.next();
//    cerr<<query.value(0).toInt()<<endl;
//    int num = rand()%(query.value(0).toInt());

//    query.exec("select Question,Answer from testdata where floor = "+QString::number(floor+1)+" and ID like '%"+QString::number(num)+"'");
//    query.next();
//    result=query.value(0).toString().toStdString();
//    answer=query.value(1).toString().toStdString();
    cout<<result<<endl;
    cout<<answer<<endl;

    if(b==1){
        arr[floor-1][0]--;
    }
    else if(b == 0){
        arr[floor-1][1]++;
    }


    timer.start();
    return result;
}

bool JudgeWindow::submitData(string ans){
    //timer end
    costtime = timer.nsecsElapsed();
//    if(answer.compare(ans)==0){
//        return true;
//    }
//    else{
//        return false;
//    }
    return true;
}

int JudgeWindow::getConditionNum(){
    return rand()%300+1;
}

void JudgeWindow::getInitialCondition(People *people[]){
    query.exec("use FINAL");
    //query.exec("select n.* from (select * from peoplelist limit "+QString::number(n-1)+",1) as s,peoplelist as n where left(n.id,5)=left(s.id,5)");
    query.exec("select * from InitialCondition");
    for(int i=0;i<27;i++){
        people[i] = new People;
        people[i]->setPeople(query);

    }

}


JudgeWindow::~JudgeWindow()
{
    delete ui;
}

void JudgeWindow::display(int nowfloor){
    for(int i=0;i<27;i++){
        for(int j=0;j<4;j++){
            if(j==0){   //waiting
                //arr[i][j] = people[i]->getPeopleNum();
                showline[i][j].setText(QString::number(arr[i][j]));
            }
            if(j==1){   //arriving
                showline[i][j].setText(QString::number(arr[i][j]));
            }
            if(j==2 && i==nowfloor-1){
                arr[i][j]+=costtime;
                showline[i][j].setText(QString::number(arr[i][j]));
            }
            if(j==3 && i==nowfloor-1){
                arr[i][j] = (arr[i][j] & submitData(answer));
                showline[i][j].setText(QString::number(arr[i][j]));
            }
        }
    }
}

//int* JudgeWindow::getArr(){
//    return  this->arr;
//}

//string getData(int floor,int b);//input 0-26
//bool submitData(string ans);
//void setSeed(int seed){srand(seed);}
//qint64 getSpendTime(){return costtime;}
//int getConditionNum();//return 1-300
//int getDistance(){return distance;}
//void scheduleEnd();
//QLineEdit showline[27][4];
