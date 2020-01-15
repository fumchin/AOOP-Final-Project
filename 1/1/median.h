#ifndef MEDIAN_H
#define MEDIAN_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <string>
#include "mydatabase.h"

class Median : public MyDatabase
{
public:
    Median();
    string solve(string s);
private:
    QSqlQuery query;
    virtual ~Median(){}
};

#endif // MEDIAN_H
