#ifndef PEOPLE_H
#define PEOPLE_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <string>
#include <iostream>
#include <QString>
using namespace std;


class People
{
public:
    People();
    void setPeople(QSqlQuery &);
//private:
    QString id;
    int Nowfloor;
    int Destination;
    int Number;
};

#endif // PEOPLE_H
