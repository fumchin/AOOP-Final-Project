#include "people.h"
#include <iostream>
#include <QSqlQuery>
#include <QApplication>
#include <QSqlDatabase>
#include <string>
#include <QString>
using namespace std;

People::People()
{
    //QSqlQuery query;
    query.exec("drop schema if exists Course6");
    query.exec("create schema if not exists Course6");
    query.exec("use Course6");
    query.exec("drop table if exists peoplelist");
    query.exec("create table if not exists peoplelist (id char(8),Nowfloor int,Destination int,Number int,PRIMARY KEY(id))");
    query.exec("load data infile 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/data.csv' into table peoplelist fields terminated by ',' lines terminated by '\n' ignore 1 rows");

}

void People::setPeople(){
    query.next();
    id = query.value(0).toString();
    Nowfloor = query.value(1).toInt();
    Destination = query.value(2).toInt();
    Number = query.value(3).toInt();
}
