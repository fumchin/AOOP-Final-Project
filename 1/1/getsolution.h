#ifndef GETSOLUTION_H
#define GETSOLUTION_H
#include "mymath.h"

class GetSolution:public MyMath
{
public:
    GetSolution();
    string solve(string s);
    string gauss(vector< vector<double> > A);
    virtual ~GetSolution(){}
};

#endif // GETSOLUTION_H
