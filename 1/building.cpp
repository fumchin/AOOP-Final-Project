#include <QApplication>
#include <QSqlDatabase>
#include <QSqlQuery>
#include "building.h"
#include "add1.h"
#include "longestpair.h"
#include <string>
#include <QTimer>
#include <QtDebug>
#include "shygame.h"
#include "fib.h"
#include "findfactorial.h"
#include "people.h"
#include <time.h>
#include <QString>

using namespace std;
Building::Building()
{
    //floor
    floor[0] = new Floor(new Add1());
    floor[1] = new Floor(new Prime());
    floor[2] = new Floor(new LongestPair());
    floor[3] = new Floor(new Shygame());
    floor[4] = new Floor(new Fib());
    floor[5] = new Floor(new FindFactorial());
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
    //0.txt
    string s = judge.getData(question);
    data.testdata1 = s;

    string s2 = floor[question]->p->solve(s);

//    cout << s2;
    data.submit1 = s2;
    bool correct = judge.submitData(s2);
    data.correct1 = correct;
    data.score = judge.getScore();
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
