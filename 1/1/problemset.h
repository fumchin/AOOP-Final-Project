#ifndef PROBLEMSET_H
#define PROBLEMSET_H

#include <string>
using namespace std;

class ProblemSet
{
public:
    ProblemSet();
    virtual string solve(string s) = 0;
};

#endif // PROBLEMSET_H
