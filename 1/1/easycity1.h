#ifndef EASYCITY1_H
#define EASYCITY1_H

#include <QSqlQuery>
#include "mydatabase.h"
#include <string>


class EasyCity1:public MyDatabase
{
public:
    EasyCity1();
    string solve(string s);
private:
    QSqlQuery query;
};

#endif // EASYCITY1_H
