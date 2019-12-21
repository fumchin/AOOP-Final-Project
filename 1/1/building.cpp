#include <string>
#include <QTimer>
#include "building.h"
#include "longestpair.h"
#include "minesweeper.h"
#include "getsignature.h"
#include "shygame.h"
#include "fib.h"
#include "findfactorial.h"
#include "shortestdistance.h"
#include "add1.h"
#include "prime.h"
#include "easycity2.h"
#include "longestshorestdisstance.h"
#include "largefactorial.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtDebug>
using namespace std;
Building::Building()
{
    floor[0] = new Floor(new LongestPair());
    floor[1] = new Floor(new Minesweeper());
    floor[2] = new Floor(new GetSignature());
    floor[3] = new Floor(new Shygame());
    floor[4] = new Floor(new Fib());
    floor[7] = new Floor(new FindFactorial());
    floor[8] = new Floor(new ShortestDistance());
    floor[9] = new Floor(new Add1());
    floor[14] = new Floor(new LargeFactorial());
    floor[24] = new Floor(new EasyCity2());
    floor[25] = new Floor(new LongestShorestDisstance());

    //connect database
    QSqlDatabase database;
    database = QSqlDatabase::addDatabase("QMYSQL");
    database.setHostName("localhost");
    database.setUserName("root");
    database.setPassword("nctuece");
    database.setPort(3306);
    bool ok = database.open();
    if(ok){
        qDebug()<<"Connected!!";
    }
    else{
        qDebug()<<"fail to connect";
    }
    //create schema
    QSqlQuery query;
    query.exec("create schema if not exists Course6");
    query.exec("use Course6");
    query.exec("create table if not exists peoplelist (id char(8),Nowfloor int,Destination int,Number int,PRIMARY KEY(id))");
    query.exec("load data infile 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/data.csv' into table peoplelist fields terminated by ',' lines terminated by '\n' ignore 1 rows");

    //create people
    srand((unsigned)time(nullptr));
    QString n = QString::number(rand()%30 + 1);
    n = "'%0"+n+"-%'";
    //cout<<n.toStdString()<<endl;
    query.exec("select * from peoplelist where id like "+n);
    for(int i=0;i<10;i++){
        query.next();
        people[i] = new People;
        people[i]->setPeople(query);
    }

    //course7_1
    timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));

}
void Building::run(int question)
{
    string s = judge.getData(question);
    data.testdata1 = s;
    string s2 = floor[question]->p->solve(s);

    data.submit1 = s2;
    bool correct = judge.submitData(s2);
    data.correct1 = correct;
    data.spendtime1 = judge.getSpendTime();
}

void Building::startSimulation()
{

    timer->start(1000);
}

void Building::update()
{
    data.nowfloor = scheduler.getNowFloor();
    if (data.nowfloor != 0)
        this->run(data.nowfloor);
    else
        timer->stop();
    emit this->updateGUI();
}


