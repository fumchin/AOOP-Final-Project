#ifndef GETSIGNATURE_H
#define GETSIGNATURE_H
#include "mymath.h"

class GetSignature:public MyMath
{
    struct assignment
    {
        int source, desination;
        assignment(int s, int d){source=s; desination=d;}
    };
public:
    GetSignature();
    string solve(string s);
};

#endif // GETSIGNATURE_H
