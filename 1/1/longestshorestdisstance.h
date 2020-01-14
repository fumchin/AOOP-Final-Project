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
private:
    QSqlQuery query;
    virtual ~LongestShorestDisstance(){}
};

#endif // LONGESTSHORESTDISSTANCE_H
