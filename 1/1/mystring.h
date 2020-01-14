#ifndef MYSTRING_H
#define MYSTRING_H
#include <string>
#include <vector>
#include "problemset.h"
using namespace std;


class MyString : public ProblemSet
{
public:
    MyString();
    virtual string solve(string) = 0;
    vector<int>stringtoVectorInt(string);
    string vectorIntToString(vector<int>);
};

#endif // MYSTRING_H
