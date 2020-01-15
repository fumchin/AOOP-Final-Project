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
    query.exec("drop schem if exists CITYDATABASE");
    query.exec("create schema if not exists CITYDATABASE");
    query.exec("use CITYDATABASE");
}

string EasyCity2::solve(string s){

    query.exec("use CITYDATABASE");
    query.exec("drop table if exists CITYTABLE");
    query.exec("create table if not exists CITYTABLE (ID int,COUNTRY varchar(50),CITY varchar(60),LAT double,LON double,PRIMARY KEY(ID))");
    query.exec("load data infile 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/city_forFinal4.csv' into table citytable fields terminated by ',' enclosed by '\"' lines terminated by '\r\n' ignore 1 rows");

    stringstream ss;
    ss<<s;
    string result="";
    int nth,m;
    double la,ha,lo,ho;
    string larsma,chs,che;
    ss>>nth>>larsma>>chs>>che>>la>>ha>>lo>>ho>>m;
    larsma = (larsma == "lar"? "desc":"asc");

    //order by how much city in a country (course7_2_7)

    query.exec("select left(COUNTRY,3) as sn,count(*) as nc from citytable group by COUNTRY order by nc "+QString::fromStdString(larsma)+" limit "+QString::number(nth-1)+",1");
    if(query.next()){
        if(query.value(0).isNull() || query.value(1).isNull()){
            result+="NULL NULL ";
        }
        else{
            result +=query.value(0).toString().toStdString()+" "+query.value(1).toString().toStdString()+" ";
        }
    }
    else{
        result+="NULL NULL ";
    }
    query.exec("SET SQL_SAFE_UPDATES=0");
    //update table and delete something(course7_2_8)
    query.exec("delete from citytable where (right(CITY,1) regexp '["+QString::fromStdString(che)+"]' or left(CITY,1) regexp '[^"+QString::fromStdString(chs)+"]') or (LAT >= "+QString::number(la)+" and LAT <= "+QString::number(ha)+" and LON >= "+QString::number(lo)+" and LON <= "+QString::number(ho)+")");
    query.exec("update citytable set lat = (@temp := lat),lat=lon,lon=@temp where right(id,1)= "+QString::number(m));
    //course7_2_10
    query.exec("select cast(round(sqrt(pow(max(LAT)-min(LAT),2)+pow(max(LON)-min(LON),2)),4) as char(20)) as ed from citytable");
    if(query.next()){
        if(query.value(0).isNull()){
            result+= "NULL";
        }
        else{
             result+=query.value(0).toString().toStdString();
        }

    }
    else{
        result += "NULL";
    }


    return result;
}
