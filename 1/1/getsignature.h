#ifndef GETSIGNATURE_H
#define GETSIGNATURE_H
#include "mymath.h"
#include <vector>
class GetSignature:public MyMath
{
    int T, N, a, b;
    vector<int> graph, sum;
    vector<bool> vis;
public:
    GetSignature();
    string solve(string s);
    int dfs(int u);
    virtual ~GetSignature(){}
};

#endif // GETSIGNATURE_H
