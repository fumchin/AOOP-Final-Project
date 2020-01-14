#include "judgewindow.h"
#include "ui_judgewindow.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <iostream>
#include <string>
#include <QGridLayout>
#include <QDebug>
#include <building.h>
#include <math.h>
#include <QString>
using namespace std;

JudgeWindow::JudgeWindow(QWidget *parent) :QWidget(parent),ui(new Ui::JudgeWindow)
{
    ui->setupUi(this);
    //read initial data
    query.exec("drop database FINAL");
    query.exec("create database if not exists FINAL");
    query.exec("use FINAL");
    query.exec("drop table if exists TestData");
    query.exec("create table if not exists TestData (ID char(8),Floor int,Question text,Answer text,PRIMARY KEY(ID))");
    query.exec("drop table if exists InitialCondition");
    query.exec("create table if not exists InitialCondition (ID char(8),Nowfloor int,Destination int,Number int,PRIMARY KEY(ID))");
    query.exec("load data infile 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/testdata_1225.csv' into table TestData fields terminated by ',' enclosed by '\"' lines terminated by '\r\n' ignore 1 rows");
    query.exec("load data infile 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/simple_initial_condition.csv' into table InitialCondition fields terminated by ',' enclosed by '\"' lines terminated by '\r\n' ignore 1 rows");
    //query.exec("load data infile 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/initial_condition.csv' into table InitialCondition fields terminated by ',' enclosed by '\"' lines terminated by '\r\n' ignore 1 rows");
    query.exec("select * from InitialCondition");
    //set up initial array for disply result
    for(int i=0;i<27;i++){
        for(int j=0;j<4;j++){
            if(j==0){
                query.next();
                arr[i][j] = query.value(3).toInt();
                showline[i][j].setText(QString::number(arr[i][j]));
            }
            else if(j==1){
                arr[i][j] = 0;
                showline[i][j].setText(QString::number(0));
            }
            else if(j==2){
                arr[i][j] = 0;
            }
            else if(j==3){
                arr[i][j] = 0;
            }
            ui->gridLayout_2->addWidget(&showline[i][j],i,j);
        }
    }
    //=========================================想giveup哪一題===================================================
//    for(int i=0;i<27;i++){
//        for(int j=0;j<1;j++){

//            if(i==21||i==22||i==23||i==26||i==25||i==24||i==4||i==2||i==20 ){ //check for giveup
//                boxlist[i][j].setCheckState(Qt::Checked);
//            }
//            else boxlist[i][j].setCheckState(Qt::Unchecked);

//            ui->gridLayout_checkbox->addWidget(&boxlist[i][j],i,j);
//            floorLabel[i][j].setText(QString::number(i+1));
//            ui->gridLayout_label->addWidget(&floorLabel[i][j],i,j);
//        }
//    }
    //========================================================================================================
    //========================================可在此測試某一題(除了該題外全部guveup)===========================
    for(int i=0;i<27;i++){
        for(int j=0;j<1;j++){
            if(i==2){
                boxlist[i][j].setCheckState(Qt::Unchecked);
            }
            else boxlist[i][j].setCheckState(Qt::Checked);

            ui->gridLayout_checkbox->addWidget(&boxlist[i][j],i,j);
            floorLabel[i][j].setText(QString::number(i+1));
            ui->gridLayout_label->addWidget(&floorLabel[i][j],i,j);
        }
    }
    //===========================================================================================================

    //floor datatimes(每筆testdata測試10次)、floornextdata(每題執行到哪裡)
    for(int i=0;i<27;i++){
        floordatatimes[i] = 10;
        floornextdata[i] = 0;
        pass[i] = 0;
     }
    //set name label
    ui->name1->setText("陳舫慶");
    ui->id1->setText("0611069");
    ui->name2->setText("曾力揚");
    ui->id2->setText("0611097");
//    ui->name1->setText("嗨嗨嗨");
//    ui->id1->setText("1234568");
//    ui->name2->setText("嘿嘿嘿");
//    ui->id2->setText("1234567");
    for(int i=0;i<27;i++){
        for(int j=0;j<4;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    score = 0;
}

//取每層樓人的條件
void JudgeWindow::getInitialCondition(People *people[]){
    query.exec("use FINAL");
    //query.exec("select n.* from (select * from peoplelist limit "+QString::number(n-1)+",1) as s,peoplelist as n where left(n.id,5)=left(s.id,5)");
    query.exec("select * from InitialCondition");
    for(int i=0;i<27;i++){
        people[i] = new People;
        people[i]->setPeople(query);
    }
}

//取題目
string JudgeWindow::getData(int floor, int b,int& datatimes){
    //一筆測資跑幾遍 回傳給datatimes
    datatimes = floordatatimes[floor];
    //disable checkbox
    for(int i=0;i<27;i++){
        boxlist[i][0].setDisabled(true);
    }

    //看該floor的測資跑到第幾筆了
    int num = floornextdata[floor-1];
    cout<<floor<<": "<<num<<endl;
    floornextdata[floor-1]++;     //in order
    string result="";

    //give up 則output giveup
    if(boxlist[floor-1][0].isChecked()){
        result = "GIVEUP";
        answer="";
    }
    //要執行的取data(按照floornextdata的順序)
    else{
        query.exec("use FINAL");
        //query.exec("select count(Question) from testdata where floor="+QString::number(floor+1));
        //query.next();
        //cerr<<query.value(0).toInt()<<endl;
        //    int num = rand()%(query.value(0).toInt());
        query.exec("select Question,Answer from testdata where floor = "+QString::number(floor)+" and ID like '%0"+QString::number(num)+"'");
        query.next();
        result=query.value(0).toString().toStdString();
        answer=query.value(1).toString().toStdString();
    }
    //進電梯，該樓層waiting-1
    if(b==1){
        arr[floor-1][0]--;
    }
    //出電梯，該樓層arrive+1
    else if(b == 0){
        arr[floor-1][1]++;
    }
    //開始計時
    timer.start();
    return result;
}

bool JudgeWindow::submitData(int floor,string ans){
    //timer end，計算花費的時間並更新
    costtime = timer.nsecsElapsed();
    costtime /= floordatatimes[floor-1];
    arr[floor-1][2]+=costtime;

    //比較答案，計算分數，並更新judgewindoe介面(display)
    if(answer.compare(ans)==0){
        score = 10000000000+pow(2,floornextdata[floor-1]-1);
        cout<<"score(floor"<<floor<<": "<<score<<endl;
        arr[floor-1][3]+=score;
        pass[floor-1]++;
        display(floor);
        return true;
    }
    else{
        //錯了嗚嗚
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

//update judgewindow
void JudgeWindow::display(int nowfloor){
    for(int i=0;i<27;i++){
        for(int j=0;j<4;j++){
            if(j==0){   //waiting
                showline[i][j].setText(QString::number(arr[i][j]));
            }
            else if(j==1){   //arriving
                showline[i][j].setText(QString::number(arr[i][j]));
            }
            else if(j==2 && i==nowfloor-1){
                showline[i][j].setText(QString::number(arr[i][j]));

            }
            if(j==3 && i==nowfloor-1){
                showline[i][j].setText(QString::number(arr[i][j]));
            }
        }
    }
}

//export
void JudgeWindow::on_export_to_database_clicked()
{
    QSqlDatabase::removeDatabase("QMYSQL");
    database2 = QSqlDatabase::addDatabase("QMYSQL");
    database2.setHostName("140.113.146.120");
    database2.setUserName("aoopstudent");
    database2.setPassword("tsaimother");
    database2.setPort(3306);
    bool ok = database2.open();
    if(ok){
        qDebug()<<"Connected!!";
    }
    else{
        qDebug()<<"fail to connect";
    }

    QSqlQuery query(database2);
    QString name1=ui->name1->text(),name2=ui->name2->text(),id1=ui->id1->text(),id2=ui->id2->text();
    QString totalStep = QString::number(distance);
    //query.exec("select * from totalpath");
    query.exec("insert into aoopstudentuse.totalpath (stud_id1,stud_name1,stud_id2,stud_name2,pathlen) values ('"+id1+"','"+name1+"','"+id2+"','"+name2+"',"+totalStep+")");
    for(int i=0;i<27;i++){
        query.exec("insert into aoopstudentuse.floorscore(stud_id1,stud_name1,stud_id2,stud_name2,floor,timespent,pass,totalques,totalscore) values ('"+id1+"','"+name1+"','"+id2+"','"+name2+"',"+QString::number(i+1)+","+QString::number(arr[i][2])+","+QString::number(pass[i])+","+QString::number(floornextdata[i])+","+QString::number(arr[i][3])+")");
    }
}
