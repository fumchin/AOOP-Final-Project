#include "easycity1.h"
#include <iostream>
#include <string>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <sstream>
#include <QString>
#include <algorithm>
#include <QVariant>
#include <QDebug>
using namespace std;
EasyCity1::EasyCity1()
{
    query.exec("drop schem if exists CITYDATABASE");
    query.exec("create schema if not exists CITYDATABASE");
    query.exec("use CITYDATABASE");
}

string EasyCity1::solve(string s){
    query.exec("use CITYDATABASE");
    query.exec("drop table if exists CITYTABLE");
    query.exec("create table if not exists CITYTABLE (ID int,COUNTRY varchar(50),CITY varchar(60),LAT double,LON double,PRIMARY KEY(ID))");
    query.exec("load data infile 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/city_forFinal4.csv' into table citytable fields terminated by ',' enclosed by '\"' lines terminated by '\r\n' ignore 1 rows");

    stringstream ss;
    ss<<s;
    string result="";
    //input
    string ch,p,q,m,n,la,lo,evod,evenodd,ascdec;

    //input
    ss>>ch>>la>>lo>>p>>q>>evod>>m>>evenodd>>ascdec>>n;
    transform(ch.begin(),ch.end(),ch.begin(),::tolower);
    evod = (evod=="ev"? "0":"1");
    evenodd = (evenodd=="odd"? "1":"0");
    ascdec = (ascdec=="asc"? "asc":"desc");
    //cout<<evod<<" "<<evenodd<<" "<<ascdec<<endl;
    //output
    string dcc,dmm,sla,slo;

    query.exec("select (count(city) - count(distinct city)) as dcc from citytable where (left(lower(city),1) regexp '["+QString::fromStdString(ch)+"]') and (right(lower(city),1) regexp lower('[^aeiou]')) and (lat>"+QString::fromStdString(la)+" and lon<"+QString::fromStdString(lo)+")");
    query.next();
    dcc = query.value(0).toString().toStdString();
    query.exec("SET SQL_SAFE_UPDATES=0");
    query.exec("update citytable set LAT = LAT*"+QString::fromStdString(p)+", LON = LON*"+QString::fromStdString(q)+" where right(id,1)%2="+QString::fromStdString(evod));
    query.exec("select cast(round(sum(lat),"+QString::fromStdString(n)+") as decimal(30,"+QString::fromStdString(n)+")) as sla,cast(round(sum(lon),"+QString::fromStdString(n)+") as decimal(30,"+QString::fromStdString(n)+")) as slo,(max(length(city))-min(length(city))) as dmm from(select * from (select * from citytable where right(id,1)%2="+QString::fromStdString(evenodd)+") as temp order by length(city) "+QString::fromStdString(ascdec)+" limit 0,"+QString::fromStdString(m)+") as q");
    query.next();
    sla = query.value(0).toString().toStdString();
    slo = query.value(1).toString().toStdString();
    dmm = query.value(2).toString().toStdString();
    result = dcc+" "+sla+" "+slo+" "+dmm;
    //cout<<result<<endl;
    return result;
}
