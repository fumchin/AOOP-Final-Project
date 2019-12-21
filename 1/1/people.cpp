#include "people.h"
#include <iostream>
#include <QSqlQuery>
#include <QApplication>
#include <QSqlDatabase>
#include <string>
#include <QString>
using namespace std;

People::People()
{

}

//still need some
void People::setPeople(QSqlQuery &query){
    query.next();
    id = query.value(0).toString();
    Nowfloor = query.value(1).toInt();
    Destination = query.value(2).toInt();
    Number = query.value(3).toInt();
    cout<<query.value(0).toInt()<<"\t"<<Nowfloor<<"\t"<<Destination<<"\t"<<Number<<endl;
}

int People::getPeopleNum(){
    return Number;
}
int People::getPeopleDes(){
    return Destination;
}
