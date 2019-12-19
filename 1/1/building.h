#ifndef BUILDING_H
#define BUILDING_H

#include<iostream>
using namespace std;
#include "judge.h"
#include "add1.h"
#include "data.h"
#include "floor.h"
#include "mymath.h"
#include "prime.h"
#include "problemset.h"
#include "people.h"
#include "judgewindow.h"
#include <string>
#include <QSqlQuery>


class Building
{
public:
    Building();
    void run(int quetion);
    Data getdata(){return  data;}
    People *people[27];

private:
    //QSqlDatabase database;
    JudgeWindow judge;
    Data data;
    QSqlQuery query;
    Floor *floor[30];

    //QSqlQuery query;

};


#endif // BUILDING_H
