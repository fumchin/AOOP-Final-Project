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
    query.exec("update citytable set LAT=round(LAT,"+QString::number(n)+"), LON=round(LON,"+QString::number(n)+");delete n1 from citytable n1,citytable n2 where round(n1.LAT,"+QString::number(n)+") = round(n2.LAT,"+QString::number(n)+") and round(n1.LON,"+QString::number(n)+") = round(n2.LON,"+QString::number(n)+") and n1.ID > n2.ID");
    query.exec("select max(result.distance) as ld,min(result.distance) as sd from (select round(sqrt(pow((a.LAT-b.LAT),2)+pow((a.LON-b.LON),2)),4) as distance from (select * from citytable order by CITY "+QString::fromStdString(alra)+",ID asc limit "+QString::number(a-1)+","+QString::number(b-a+1)+") as a,(select * from citytable order by CITY "+QString::fromStdString(alra)+",ID asc limit "+QString::number(a-1)+","+QString::number(b-a+1)+") as b where a.LAT!= b.LAT and a.LON!=b.LON) as result order by distance asc");
    query.next();
    result +=QString::number(query.value(0).toDouble(),'f',4).toStdString()+" "+QString::number(query.value(1).toDouble(),'f',4).toStdString();
    return result;
}
