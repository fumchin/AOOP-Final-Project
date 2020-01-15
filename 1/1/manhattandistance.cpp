#include "manhattandistance.h"
#include <string>
#include <iostream>
#include <sstream>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>
#include <QVariant>
#include <QDebug>
#include <iomanip>
ManhattanDistance::ManhattanDistance()
{
    query.exec("drop schem if exists CITYDATABASE");
    query.exec("create schema if not exists CITYDATABASE");
    query.exec("use CITYDATABASE");
}

string ManhattanDistance::solve(string s){
    query.exec("use CITYDATABASE");
    query.exec("drop table if exists CITYTABLE");
    query.exec("create table if not exists CITYTABLE (ID int,COUNTRY varchar(50),CITY varchar(60),LAT double,LON double,PRIMARY KEY(ID))");

    query.exec("load data infile 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/city_forFinal4.csv' into table citytable fields terminated by ',' enclosed by '\"' lines terminated by '\r\n' ignore 1 rows");

    stringstream ss;
    ss<<s;
    string result="";
    int s1,t;
    string v1,v2;
    ss>>s1>>t>>v1>>v2;
    string command = "";
    command += "select cast(round(a.x1x2+b.y1y2,4) as char(20)) as md from ";
    command += "(select abs(max(t1.lon)-min(t1.lon)) as x1x2 from (select * from citytable where lat < "+v1+" order by lat desc limit "+to_string(s1-1)+","+to_string(t-s1+1)+") as t1) as a,";
    command += "(select abs(max(t1.lat)-min(t1.lat)) as y1y2 from (select * from citytable where lon > "+v2+" order by lon asc limit "+to_string(s1-1)+","+to_string(t-s1+1)+") as t1) as b";
    query.exec(QString::fromStdString(command));
    if(query.next()){
        if(query.value(0).isNull()){
            result+="NULL";
        }
        else{
            result+=query.value(0).toString().toStdString();
        }
    }
    else{
        result+="NULL";
    }
    return result;
}


//sql code
//select cast(round(a.x1x2+b.y1y2,4) as char(20)) as md from
//(select abs(max(t1.lon)-min(t1.lon)) as x1x2 from (select * from citytable where lat < 121.7 order by lat desc limit 3,6) as t1) as a,
//(select abs(max(t1.lat)-min(t1.lat)) as y1y2 from (select * from citytable where lon > 25 order by lon asc limit 3,6) as t1) as b;
