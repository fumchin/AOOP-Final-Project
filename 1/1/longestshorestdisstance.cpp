#include "longestshorestdisstance.h"
#include <string>
#include <iostream>
#include <sstream>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>
#include <QVariant>
#include <QDebug>
#include <iomanip>
using namespace std;
LongestShorestDisstance::LongestShorestDisstance()
{
    query.exec("drop schem if exists CITYDATABASE");
    query.exec("create schema if not exists CITYDATABASE");
    query.exec("use CITYDATABASE");
}

string LongestShorestDisstance::solve(string s){
    query.exec("use CITYDATABASE");
    query.exec("drop table if exists CITYTABLE");
    query.exec("create table if not exists CITYTABLE (ID int,COUNTRY varchar(50),CITY varchar(60),LAT double,LON double,PRIMARY KEY(ID))");

    query.exec("load data infile 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/city_forFinal4.csv' into table citytable fields terminated by ',' enclosed by '\"' lines terminated by '\r\n' ignore 1 rows");

    stringstream ss;
    ss<<s;
    string result="";
    int n,a,b;
    string alra;
    ss>>n>>a>>b>>alra;
    alra = (alra == "al"? "asc":"desc");
    string command = "";
    command+="select cast(round(max(sqrt(pow(t2.lat-t3.lat, 2)+pow(t2.lon-t3.lon, 2))),4) as char(20)), cast(round(min(sqrt(pow(t2.lat-t3.lat, 2)+pow(t2.lon-t3.lon, 2))),4) as char(20)) from ";
    command+="(select distinct lat, lon from (select id, city, round(lat, "+to_string(n)+") as lat, round(lon, "+to_string(n)+") as lon from citytable) as t1 order by city "+alra+" limit "+to_string(a-1)+", "+to_string(b-a+1)+") as t2 ";
    command+="inner join ";
    command+="(select distinct lat, lon from (select id, city, round(lat, "+to_string(n)+") as lat, round(lon, "+to_string(n)+") as lon from citytable) as t1 order by city "+alra+" limit "+to_string(a-1)+", "+to_string(b-a+1)+") as t3 ";
    command+="on t2.lat!=t3.lat or t2.lon!=t3.lon";

    //query.exec("update citytable set LAT=round(LAT,"+QString::number(n)+"), LON=round(LON,"+QString::number(n)+");delete n1 from citytable n1,citytable n2 where round(n1.LAT,"+QString::number(n)+") = round(n2.LAT,"+QString::number(n)+") and round(n1.LON,"+QString::number(n)+") = round(n2.LON,"+QString::number(n)+") and n1.ID > n2.ID");
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
    //cout<<result<<endl;
    return result;
}
