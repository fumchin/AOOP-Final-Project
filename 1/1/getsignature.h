#ifndef GETSIGNATURE_H
#define GETSIGNATURE_H
#include "myother.h"

class GetSignature:public MyOther
{
    struct assignment
    {
        int source, desination;
        assignment(int s, int d){source=s; desination=d;}
    };
public:
    GetSignature();
    string solve(string s);
    virtual ~GetSignature(){}
};

#endif // GETSIGNATURE_H
