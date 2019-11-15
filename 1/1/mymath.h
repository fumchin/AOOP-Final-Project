#ifndef MYMATH_H
#define MYMATH_H

#include <string>
#include <vector>
#include "problemset.h"
using namespace std;

class MyMath : public ProblemSet
{
public:
    MyMath();
    virtual string solve(string) = 0;
    vector<int>stringtoVectorInt(string);
    string vectorIntToString(vector<int>);
};

#endif // MYMATH_H
