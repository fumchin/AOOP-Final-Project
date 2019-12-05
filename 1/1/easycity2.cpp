#include "easycity2.h"
#include <iostream>
#include <string>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <sstream>
using namespace std;


EasyCity2::EasyCity2()
{

}

string EasyCity2::solve(string s){
    QSqlQuery query;
    query.exec("drop schem if exists CITYDATABASE");
    query.exec("create schema if not exists CITYDATABASE");
    query.exec("use CITYDATABASE");
    query.exec("drop table if exists CITYTABLE");
    query.exec("create table if not exists CITYTABLE (ID int,COUNTRY varchar(50),CITY varchar(60),LAT int,LON int,PRIMARY KEY(ID))");
    query.exec("load data infile 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/city.csv' into table citytable fields terminated by ',' enclosed by '""' lines terminated by '\n' ignore 1 rows");

    //query.exec("select * from peoplelist where id like "+n);
    stringstream ss;
    ss<<s;
    string result="";
    int nth;
    string larsma,chs,che,la,ha,lo,ho,m;
    ss>>nth>>larsma>>chs>>che>>la>>ha>>lo>>ho>>m;
    return result;
}
