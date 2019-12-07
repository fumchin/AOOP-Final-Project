#include "easycity2.h"
#include <iostream>
#include <string>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <sstream>
#include <QString>
#include <QVariant>
#include <QDebug>
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

    stringstream ss;
    ss<<s;
    string result="";
    int nth,m;
    double la,ha,lo,ho;
    string larsma,chs,che;
    ss>>nth>>larsma>>chs>>che>>la>>ha>>lo>>ho>>m;
    larsma = (larsma == "lar"? "desc":"asc");

    //order by how much city in a country (course7_2_7)
    if(query.exec("select substring(COUNTRY,2,3),count(*) as compare from citytable group by COUNTRY order by compare "+QString::fromStdString(larsma)+" limit 1 offset "+QString::number(nth-1))){
        query.next();
        cout<<query.value(0).toString().toStdString()<<endl;
        cout<<query.value(1).toString().toStdString()<<endl;
        result +=query.value(0).toString().toStdString()+" "+query.value(1).toString().toStdString()+" ";
    }
    cout<<chs<<"\t"<<che<<endl;
    query.exec("SET SQL_SAFE_UPDATES=0");
    //update table and delete something(course7_2_8)
    query.exec("delete from citytable where CITY regexp '^.[^"+QString::fromStdString(chs)+"]' or CITY like '["+QString::fromStdString(che)+"].$' or (LAT >= "+QString::number(la)+" and LAT <= "+QString::number(ha)+" and LON >= "+QString::number(lo)+" and LON <= "+QString::number(ho)+")");
    //course7_2_9
    query.exec("SET SQL_SAFE_UPDATES=0");
    cout<<ho<<endl<<m<<endl;
    query.exec("update citytable set LAT=LAT+LON,LON=LAT-LON,LAT=LAT-LON where id like '%"+QString::number(m)+"'");
    //course7_2_10
    if(query.exec("select round(sqrt(pow(max(LAT)-min(LAT),2)+pow(max(LON)-min(LON),2)),4) from citytable")){
        query.next();
        cout<<query.value(0).toString().toStdString()<<endl;
        result +=query.value(0).toString().toStdString();
    }


    return result;
}
