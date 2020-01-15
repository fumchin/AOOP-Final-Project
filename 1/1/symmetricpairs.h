#ifndef SYMMETRICPAIRS_H
#define SYMMETRICPAIRS_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <string>
#include "mydatabase.h"


class SymmetricPairs: public MyDatabase
{
public:
    SymmetricPairs();
    string solve(string s);
private:
    QSqlQuery query;
    virtual ~SymmetricPairs(){}
};

#endif // SYMMETRICPAIRS_H
