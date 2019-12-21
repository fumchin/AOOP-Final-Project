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
#include "largefactorial.h"
#include "people.h"
#include "easycity2.h"
#include "longestshorestdisstance.h"
#include "judgewindow.h"
#include <time.h>
#include <QString>
using namespace std;
Building::Building()
{

    //JudgeWindow judge;
    judge.show();
    judge.setSeed(0);
    int n=judge.getConditionNum(); //get People data according variable n
    //create people
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

//   //query.exec("select n.* from (select * from peoplelist limit "+QString::number(n-1)+",1) as s,peoplelist as n where left(n.id,5)=left(s.id,5)");
    query.exec("select * from InitialCondition");
    for(int i=0;i<27;i++){
        people[i] = new People;
        //cout<<query.value(0).toInt()<<endl;
        people[i]->setPeople(query);
    }
    //floor
    floor[0] = new Floor(new LongestPair());
    floor[1] = new Floor(new Prime());
    floor[3] = new Floor(new Shygame());
    floor[4] = new Floor(new Fib());
    floor[6] = new Floor();
    floor[7] = new Floor(new FindFactorial());
    floor[8] = new Floor();
    floor[9] = new Floor(new Add1());
    floor[15] = new Floor(new LargeFactorial());
    floor[24] = new Floor(new EasyCity2());
    floor[25] = new Floor(new LongestShorestDisstance());


}
void Building::run(int question)
{
    //0.txt
    string s = judge.getData(question,0);
    data.testdata1 = s;

    string s2 = floor[question]->p->solve(s);


    data.submit1 = s2;
    bool correct = judge.submitData(s2);
    data.correct1 = correct;
    data.spendtime1 = judge.getSpendTime();

}

