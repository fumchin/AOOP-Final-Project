#ifndef MYOTHER_H
#define MYOTHER_H

#include <string>
#include <vector>
#include "problemset.h"
class MyOther:public ProblemSet
{
public:
    MyOther();
    virtual string solve(string) = 0;
    vector<int>stringtoVectorInt(string);
    string vectorIntToString(vector<int>);
};

#endif // MYOTHER_H
