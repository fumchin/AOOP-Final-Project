#include "longestshorestdisstance.h"
#include <string>
#include <iostream>
#include <sstream>
#include <QSqlDatabase>
#include <QSqlQuery>
using namespace std;
LongestShorestDisstance::LongestShorestDisstance()
{

}

string LongestShorestDisstance::solve(string s){
    QSqlQuery query;
    query.exec("drop schem if exists CITYDATABASE");
    query.exec("create schema if not exists CITYDATABASE");
    query.exec("use CITYDATABASE");
    query.exec("drop table if exists CITYTABLE");
    query.exec("create table if not exists CITYTABLE (ID int,COUNTRY varchar(50),CITY varchar(60),LAT double,LON double,PRIMARY KEY(ID))");
    query.exec("load data infile 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/city.csv' into table citytable fields terminated by ',' lines terminated by '\r\n' ignore 1 rows");
    return s;
}
