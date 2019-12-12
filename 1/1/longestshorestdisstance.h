#ifndef LONGESTSHORESTDISSTANCE_H
#define LONGESTSHORESTDISSTANCE_H
#include "mydatabase.h"
#include <QSqlDatabase>
#include <QSqlQuery>

class LongestShorestDisstance : public MyDatabase
{
public:
    LongestShorestDisstance();
    string solve(string s);
    QSqlQuery query;
};

#endif // LONGESTSHORESTDISSTANCE_H
