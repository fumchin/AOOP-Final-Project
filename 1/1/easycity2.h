#ifndef EASYCITY2_H
#define EASYCITY2_H
#include <QSqlQuery>
#include "mydatabase.h"
#include <string>
#include <QSqlQuery>


class EasyCity2 : public MyDatabase
{
public:
    EasyCity2();
    string solve(string s);
private:
    QSqlQuery query;
};

#endif // EASYCITY2_H
