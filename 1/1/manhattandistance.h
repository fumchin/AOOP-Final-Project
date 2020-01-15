#ifndef MANHATTANDISTANCE_H
#define MANHATTANDISTANCE_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <string>
#include "mydatabase.h"


class ManhattanDistance : public MyDatabase
{
public:
    ManhattanDistance();
    string solve(string s);
private:
    QSqlQuery query;
    virtual ~ManhattanDistance(){}
};

#endif // MANHATTANDISTANCE_H
