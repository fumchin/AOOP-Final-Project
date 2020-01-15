#include "symmetricpairs.h"
#include <string>
#include <iostream>
#include <sstream>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>
#include <QVariant>
#include <QDebug>
#include <iomanip>

SymmetricPairs::SymmetricPairs()
{
    query.exec("drop schem if exists CITYDATABASE");
    query.exec("create schema if not exists CITYDATABASE");
    query.exec("use CITYDATABASE");
}

string SymmetricPairs::solve(string s){
    query.exec("use CITYDATABASE");
    query.exec("drop table if exists CITYTABLE");
    query.exec("create table if not exists CITYTABLE (ID int,COUNTRY varchar(50),CITY varchar(60),LAT double,LON double,PRIMARY KEY(ID))");

    query.exec("load data infile 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/city_forFinal4.csv' into table citytable fields terminated by ',' enclosed by '\"' lines terminated by '\r\n' ignore 1 rows");

    stringstream ss;
    ss<<s;
    string result="";
    string command = "";
    int m,n,k;
    string evod;
    ss>>evod>>m>>n>>k;
    evod = (evod == "ev"? "0":"1");
    query.exec("SET SQL_SAFE_UPDATES=0");
    query.exec("update citytable set lat = (@temp := lat),lat=lon,lon=@temp where right(id,1)%2 = "+QString::fromStdString(evod));
    query.exec("update citytable set lat = lon where right(id,1) = "+QString::number(m));

    command += "select cast(round(t.x,"+to_string(n)+") as char(20)),cast(round(t.y,"+to_string(n)+") as char(20)) from";
    command += "(select";
    command += " distinct round(t1.lat,"+to_string(n)+")  as x,round(t1.lon,"+to_string(n)+") as y";
    command += " from";
    command += " citytable t1 ,citytable t2";
    command += " where";
    command += " round(t1.lat,"+to_string(n)+") = round(t2.lon,"+to_string(n)+") and round(t1.lon,"+to_string(n)+") = round(t2.lat,"+to_string(n)+") and t1.id != t2.id order by x asc,y asc) as t";
    command += " where t.x <= t.y limit "+to_string(k-1)+",1";
    //command += " limit "+to_string(k-1)+",1";
    //command += "";
    //command += "";

    query.exec(QString::fromStdString(command));
    if(query.next()){
        if(query.value(0).isNull() || query.value(1).isNull()){
            result += "NULL NULL";
        }
        else{

            result += query.value(0).toString().toStdString()+" "+query.value(1).toString().toStdString();
        }
    }
    else{
        result += "NULL NULL";
    }
    cout<<result<<endl;
    return result;
}
