#include "median.h"
#include <string>
#include <iostream>
#include <sstream>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QString>
#include <QVariant>
#include <QDebug>
#include <iomanip>

Median::Median()
{
    query.exec("drop schem if exists CITYDATABASE");
    query.exec("create schema if not exists CITYDATABASE");
    query.exec("use CITYDATABASE");
}

string Median::solve(string s){
    query.exec("use CITYDATABASE");
    query.exec("drop table if exists CITYTABLE");
    query.exec("create table if not exists CITYTABLE (ID int,COUNTRY varchar(50),CITY varchar(60),LAT double,LON double,PRIMARY KEY(ID))");

    query.exec("load data infile 'C:/ProgramData/MySQL/MySQL Server 8.0/Uploads/city_forFinal4.csv' into table citytable fields terminated by ',' enclosed by '\"' lines terminated by '\r\n' ignore 1 rows");

    stringstream ss;
    ss<<s;
    string result="";
    int a,b,m;
    string latlon,ascdes;
    ss>>a>>b>>latlon>>m>>ascdes;
    //cout<<a<<" "<<b<<" "<<latlon<<" "<<m<<" "<<ascdes<<endl;
    latlon = (latlon == "lat"? "lat":"lon");
    ascdes = (ascdes == "asc"? "asc":"desc");
    string command = "";
    command += "SELECT cast(round(AVG(dd."+latlon+"),4) as char (20)) as median_val";
    command += " FROM ( " ;
    command += "SELECT d."+latlon+", @rownum:=@rownum+1 as `row_number`, @total_rows:=@rownum";
    command += "  FROM citytable d, (SELECT @rownum:=0) r";
    command += "  WHERE d."+latlon+" is NOT NULL";
    command += "  and right(d.id,1) = "+to_string(m);
    command += "  ORDER BY d."+latlon+" "+ascdes;
    command += "  limit "+to_string(a-1)+","+to_string(b-a+1);
    command += ") as dd";
    command += " WHERE dd.row_number IN ( FLOOR((@total_rows+1)/2), FLOOR((@total_rows+2)/2) )";
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
//SELECT cast(round(AVG(dd.lon),4) as char (20)) as median_val
//FROM (
//SELECT d.lon, @rownum:=@rownum+1 as `row_number`, @total_rows:=@rownum
//  FROM citytable d, (SELECT @rownum:=0) r
//  WHERE d.lon is NOT NULL
//  and right(d.id,1) = 6
//  ORDER BY d.lon
//  limit 0,4
//) as dd
//WHERE dd.row_number IN ( FLOOR((@total_rows+1)/2), FLOOR((@total_rows+2)/2) );
