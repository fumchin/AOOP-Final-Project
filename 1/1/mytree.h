#ifndef MYTREE_H
#define MYTREE_H
#include "problemset.h"
#include <string>
#include <vector>
using namespace std;

class MyTree: public ProblemSet
{
public:
    MyTree();
    virtual string solve(string) = 0;
    vector<int>stringtoVectorInt(string);
    string vectorIntToString(vector<int>);
};

#endif // MYTREE_H
